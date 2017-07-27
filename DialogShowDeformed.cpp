// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogShowDeformed.h"

DialogShowDeformed::DialogShowDeformed(wxWindow* HandleIn, wxString PathIn, double *DeformArrIn, int *ScaleIn, int NodeOfNumIn, double *MaxDeformIn) : DialogShowDeformedBase(HandleIn), D(NodeOfNumIn)
{
	Handle = HandleIn;
	Path = PathIn;
	PathText->SetValue(Path + wxT("\\NodeDisp.txt"));
	Scale = ScaleIn;
	ScaleSlider->SetValue(*Scale);
	ScaleText->SetValue(F.ToString(ScaleSlider->GetValue()));
	NodeOfNum = NodeOfNumIn;
	MaxDeform = MaxDeformIn;
	DeformArr = DeformArrIn;

	ifstream FileIn((Path + wxT("\\DataIndex.txt")).ToStdString());
	string Tmp;
	AnalysisCaseVec.clear();
	bool T = true;
	while (getline(FileIn, Tmp))
	{
		istringstream Line(Tmp);
		if (T)
		{
			Line >> NumModes;
			T = false;
			continue;
		}

		AnalysisCase ACTmp;
		Line >> ACTmp.ID >> ACTmp.LineStart >> ACTmp.LineEnd;
		AnalysisCaseVec.push_back(ACTmp);
	}
	//wxMessageBox("DialogShowDeformed");
	LoadData();
}

void DialogShowDeformed::OnCloseDialog(wxCloseEvent& event)
{
	wxCommandEvent Evt(wxEVT_SET_STATE);
	Evt.SetString("ShowDeformedDialog");
	Handle->GetEventHandler()->AddPendingEvent(Evt);
}

DialogShowDeformed::~DialogShowDeformed()
{
}

void DialogShowDeformed::LoadData()
{
	//wxMessageBox("LoadData");
	AnalysisCaseChoice->Clear();
	if (!AnalysisCaseVec.empty())
	{
		ifstream FileIn((PathText->GetValue()).ToStdString());
		string Line;
		D.clear();
		while (getline(FileIn, Line))
		{
			stringstream SS;
			SS << Line;
			double DTmp;
			vector<double> OneLine;
			for (int i = 0; i < 3 * NodeOfNum + 1; ++i)
			{
				SS >> DTmp;
				OneLine.push_back(DTmp);
			}

			D.push_back(OneLine);
		}

		CntRow = D.size();
		CntCol = 3 * NodeOfNum + 1;

		AnalysisCaseChoice->Enable(true);
		for (auto ii = AnalysisCaseVec.end() - 1;; --ii)
		{
			wxString Item = F.ToString((*ii).ID);
			AnalysisCaseChoice->Insert(Item, 0);
			if (ii == AnalysisCaseVec.begin()) break;
		}

		LineStart = AnalysisCaseVec[0].LineStart;
		LineEnd = AnalysisCaseVec[0].LineEnd < CntRow - 1 ? AnalysisCaseVec[0].LineEnd : CntRow - 1;
		LineIdx = LineStart;

		TimeSlider->SetMin(LineStart);
		TimeSlider->SetMax(LineEnd);
		TimeSlider->SetValue(LineStart);
		TimeText->SetValue(F.ToString(D[LineStart][0]));
		TimeSpeed = 0;

		*MaxDeform = 0.0;
		for (int i = LineStart; i <= LineEnd; ++i)
		{
			for (int j = 3; j < CntCol; j += 3)
			{
				double Deform = sqrt((D[i][j])*(D[i][j]) + (D[i][j - 1])*(D[i][j - 1]) + (D[i][j - 2])*(D[i][j - 2]));
				if (Deform > (*MaxDeform))
				{
					*MaxDeform = Deform;
				}
			}
		}
	}

	if (NumModes > 0)
	{
		int NumCase = (int)AnalysisCaseChoice->GetCount();
		AnalysisCaseChoice->Insert(wxT("Modal"), NumCase);
	}

	AnalysisCaseChoice->Select(0);
	CheckStates();
}

void DialogShowDeformed::OnSelectResualtFile(wxCommandEvent& event)
{
	wxFileDialog* MyDialog = new wxFileDialog(this, _("Select Resualt of Node Deform File"),
		wxEmptyString, wxEmptyString, wxT("*.txt"),
		wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		wxString FilePath = MyDialog->GetPath();
		PathText->Clear();
		PathText->AppendText(FilePath);
	}
	LoadData();
}

void DialogShowDeformed::DisplayDeform()
{
	//wxMessageBox("DisplayDeform");
	wxString Case = AnalysisCaseChoice->GetStringSelection();
	if (Case != wxT("Modal"))
	{
		for (int j = 0; j < CntCol; ++j)
		{
			DeformArr[j] = D[LineIdx][j];
		}
	}

	wxCommandEvent Evt(wxEVT_DISPLAY_DEFORM);
	Handle->GetEventHandler()->AddPendingEvent(Evt);
}

void DialogShowDeformed::OnAutoPlay(wxCommandEvent& event)
{
	//wxMessageBox("OnAutoPlay");
	wxString Case = AnalysisCaseChoice->GetStringSelection();
	if (Case == wxT("Modal"))
	{
		LineIdx = TimeSlider->GetValue();
		ifstream ModalData(Path.ToStdString() + ("\\Mode") + F.ToString(LineIdx) + (".txt"));
		string Line;
		getline(ModalData, Line);
		stringstream SS;
		SS << Line;
		for (int i = 0; i < 3 * NodeOfNum + 1; ++i)
		{
			SS >> DeformArr[i];
		}

		*MaxDeform = 0.0;
		for (int i = 3; i < 3 * NodeOfNum + 1; i += 3)
		{
			double Deform = sqrt(DeformArr[i] * DeformArr[i] + DeformArr[i - 1] * DeformArr[i - 1] + DeformArr[i - 2] * DeformArr[i - 2]);
			if (Deform > (*MaxDeform))
			{
				*MaxDeform = Deform;
			}
		}

		*Scale = 0;
		TimeStep = 100;
	}
	else
	{
		int Idx = AnalysisCaseChoice->GetSelection();
		LineStart = AnalysisCaseVec[Idx].LineStart;
		LineEnd = AnalysisCaseVec[Idx].LineEnd < CntRow - 1 ? AnalysisCaseVec[Idx].LineEnd : CntRow - 1;
		LineIdx = LineStart;
		TimeStep = (D[LineEnd][0] - D[LineEnd - 1][0]) * 1000;
		TimeSpeed = F.StrToInt(SpeedText->GetValue().ToStdString());

		if (TimeSpeed > 0)
		{
			TimeStep /= (1 + abs(TimeSpeed));
			if (TimeStep == 0) TimeStep = 1;
		}
		else
		{
			TimeStep *= (1 + abs(TimeSpeed));
		}
	}

	Timer.Start(TimeStep);
}

void DialogShowDeformed::OnTimer(wxTimerEvent& event)
{
	//wxMessageBox("OnTimer");
	wxString Case = AnalysisCaseChoice->GetStringSelection();
	if (Case == wxT("Modal"))
	{
		*Scale += 1;
		if ((*Scale) <= F.StrToInt(ScaleText->GetValue().ToStdString()))
		{
			DisplayDeform();
		}
		else
		{
			Timer.Stop();
		}
	}
	else
	{
		TimeSlider->SetValue(LineIdx);
		TimeText->SetValue(F.ToString(D[LineIdx][0]));
		++LineIdx;

		if (LineIdx > LineEnd)
		{
			LineIdx = LineEnd;
			Timer.Stop();
		}
	}
}

void DialogShowDeformed::OnStop(wxCommandEvent& event)
{
	Timer.Stop();
}

void DialogShowDeformed::OnChangeCase(wxCommandEvent& event)
{
	//wxMessageBox("OnChangeCase");
	CheckStates();
}

void DialogShowDeformed::OnChangedSliderScale(wxScrollEvent& event)
{
	//wxMessageBox("OnChangedSliderScale");
	ScaleText->SetValue(F.ToString(ScaleSlider->GetValue()));
}

void DialogShowDeformed::OnChangedTextScale(wxUpdateUIEvent& event)
{
	//wxMessageBox("OnChangedTextScale");
	(*Scale) = F.StrToInt((ScaleText->GetValue()).ToStdString());
	DisplayDeform();
}

void DialogShowDeformed::OnChangedSliderSpeed(wxScrollEvent& event)
{
	//wxMessageBox("OnChangedSliderSpeed");
	SpeedText->SetValue(F.ToString(SpeedSlider->GetValue()));
}

void DialogShowDeformed::OnChangedTextSpeed(wxUpdateUIEvent& event)
{
	//wxMessageBox("OnChangedTextSpeed");
	TimeSpeed = F.StrToInt((SpeedText->GetValue()).ToStdString());
}

void DialogShowDeformed::OnChangedTime(wxScrollEvent& event)
{
	//wxMessageBox("OnChangedTime");
	wxString Case = AnalysisCaseChoice->GetStringSelection();
	if (Case == wxT("Modal"))
	{
		LineIdx = TimeSlider->GetValue();
		TimeText->SetValue(F.ToString(LineIdx));
	}
	else
	{
		LineIdx = TimeSlider->GetValue();
		TimeText->SetValue(F.ToString(D[LineIdx][0]));
		DisplayDeform();
	}
}

void DialogShowDeformed::CheckStates()
{
	//wxMessageBox("CheckStates");
	wxString Case = AnalysisCaseChoice->GetStringSelection();
	if (Case == wxT("Modal"))
	{
		ScaleSlider->Enable(true);
		ScaleText->Enable(true);
		SpeedSlider->Enable(true);
		SpeedText->Enable(true);
		TimeSlider->Enable(true);
		TimeText->Enable(true);
		AutoPlay->Enable(true);
		Stop->Enable(true);

		TimeSlider->SetMin(1);
		TimeSlider->SetMax(NumModes);
		TimeSlider->SetValue(1);
		TimeText->SetValue("1");
	}
	else
	{
		int k = AnalysisCaseChoice->GetSelection();
		LineStart = AnalysisCaseVec[k].LineStart;
		LineEnd = AnalysisCaseVec[k].LineEnd < CntRow - 1 ? AnalysisCaseVec[k].LineEnd : CntRow - 1;

		*MaxDeform = 0.0;
		for (int i = LineStart; i <= LineEnd; ++i)
		{
			for (int j = 3; j < CntCol; j += 3)
			{
				double Deform = sqrt((D[i][j])*(D[i][j]) + (D[i][j - 1])*(D[i][j - 1]) + (D[i][j - 2])*(D[i][j - 2]));
				if (Deform > (*MaxDeform))
				{
					*MaxDeform = Deform;
				}
			}
		}

		LineIdx = LineStart;
		TimeSlider->SetMin(LineStart);
		TimeSlider->SetMax(LineEnd);
		TimeSlider->SetValue(LineStart);
		TimeText->SetValue(F.ToString(D[LineStart][0]));

		if (LineEnd > LineStart)
		{
			ScaleSlider->Enable(true);
			ScaleText->Enable(true);
			SpeedSlider->Enable(true);
			SpeedText->Enable(true);
			TimeSlider->Enable(true);
			TimeText->Enable(true);
			AutoPlay->Enable(true);
			Stop->Enable(true);
		}
		else
		{
			ScaleSlider->Enable(true);
			ScaleText->Enable(true);
			SpeedSlider->Enable(false);
			SpeedText->Enable(false);
			TimeSlider->Enable(false);
			TimeText->Enable(false);
			AutoPlay->Enable(false);
			Stop->Enable(false);
		}
	}
}