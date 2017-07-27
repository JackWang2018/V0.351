// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "Main.h"

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation
////////////////////////////////////////////////////////////////////////////////


bool MainApp::OnInit()
{
	Locale = NULL;
	ComFunc F;
	OSLiteConfig *Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	if (Config->GetValue("Language") == "Chinese")
	{
		SelectLanguage(wxLANGUAGE_CHINESE_SIMPLIFIED);
	}
	else if (Config->GetValue("Language") == "French")
	{
		SelectLanguage(wxLANGUAGE_FRENCH);
	}
	else
	{
		SelectLanguage(wxLANGUAGE_ENGLISH);
	}

	delete(Config);

	SetTopWindow(new MainFrame(NULL));
	GetTopWindow()->Show();


	// true = enter the main loop
	return true;
}

void MainApp::SelectLanguage(int Lang)
{
	delete Locale;
	Locale = new wxLocale(Lang);
	Locale->AddCatalogLookupPathPrefix("../Locale");
	Locale->AddCatalog(wxT("zh_CN"));
	Locale->AddCatalog(wxT("fr"));
}

enum {
	SERVER_ID = 100,
	SOCKET_ID
};


////////////////////////////////////////////////////////////////////////////////
// main application frame implementation
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent) : MainFrameBase(parent)
{
	SetIcon(wxIcon(Logo_xpm));
	Title = wxT("OSLite ") + Version;
	SetTitle(Title);
	wxTextFile FileInput;
	KeyWords = "";
	if (FileInput.Open(wxT("KeyWords.txt")))
	{
		int num = FileInput.GetLineCount();
		for (int i = 0; i < num; ++i)
		{
			KeyWords += FileInput.GetLine(i);
			KeyWords += " ";
		}
		FileInput.Close();
	}
	else
	{
		wxMessageBox(_("Please create KeyWords!"));
	}

	IsWrapMode = false;
	MenuView->Check(wxID_MenuViewWrap, IsWrapMode);

	IsAutoComp = true;
	MenuOptions->Check(wxID_MenuOptionsCodeComp, true);

	IsLineNumber = true;
	MenuView->Check(wxID_MenuViewLineNumber, true);

	IsNodeNumOn = false;
	IsEleNumOn = false;

	IsRtMonitor = true;

	UpdateCodeEdit();

	FileName = "";
	IsEdited = false;

	StatusBar->SetLabel(_("Jacques.Chen | Welcome to my Website http://blog.whchen.net"));

	//Init KeyWordTire
	KeyWordTire = new  TrieTree();
	int P = 0;
	int Q = KeyWords.find(' ', 0);
	while (Q != -1)
	{
		KeyWordTire->Insert(KeyWords.SubString(P, Q - 1).mb_str(), KeyWordTire);
		P = Q + 1;
		Q = KeyWords.find(' ', Q + 1);
	}

	OsVtkWin = new VtkWin(ViewPanel);
	SendModelData();
	OsVtkWin->Model->InitRenderer();
	OsVtkWin->SetAxes();
	OsVtkWin->ChangeColor();
	OsVtkWin->ViewXYZ();
	OsVtkWin->ResetCamera();
	OsVtkWin->Render();

	IsRunning = false;
	AnalyzeThread = NULL;
	AnalyzeProcess = NULL;

	RightMenu = NULL;

	this->Connect(wxID_ANY, wxEVT_THREAD_RUN, wxThreadEventHandler(MainFrame::OnOutputLog), NULL, this);
	this->Connect(SERVER_ID, wxEVT_SOCKET, wxSocketEventHandler(MainFrame::OnServerEvent), NULL, this);
	this->Connect(SOCKET_ID, wxEVT_SOCKET, wxSocketEventHandler(MainFrame::OnSocketEvent), NULL, this);
	this->Connect(wxID_ANY, wxEVT_DISPLAY_DEFORM, wxCommandEventHandler(MainFrame::OnDisplayNodeDeformByDialog), NULL, this);
	this->Connect(wxID_ANY, wxEVT_SET_STATE, wxCommandEventHandler(MainFrame::OnSetState), NULL, this);


	FindDialog = NULL;
	ReplaceDialog = NULL;
	LastGoto = 1;
	this->Connect(wxID_ANY, wxEVT_COMMAND_FIND, wxFindDialogEventHandler(MainFrame::OnEditFindDialog));
	this->Connect(wxID_ANY, wxEVT_COMMAND_FIND_NEXT, wxFindDialogEventHandler(MainFrame::OnEditFindDialog));
	this->Connect(wxID_ANY, wxEVT_COMMAND_FIND_REPLACE, wxFindDialogEventHandler(MainFrame::OnEditFindDialog));
	this->Connect(wxID_ANY, wxEVT_COMMAND_FIND_REPLACE_ALL, wxFindDialogEventHandler(MainFrame::OnEditFindDialog));
	this->Connect(wxID_ANY, wxEVT_COMMAND_FIND_CLOSE, wxFindDialogEventHandler(MainFrame::OnEditFindDialog));

	SetAnalysisOpintionDialog = NULL;
	RealTimeMonitorDeformDialog = NULL;
	ShowDeformedDialog = NULL;

	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	MonitorPort = F.StrToInt(Config->GetValue("Port").ToStdString());
	MonitorHost = Config->GetValue("Host");
	IsRtMonitor = F.StrToInt(Config->GetValue("RealTimeMonitor").ToStdString()) > 0 ? true : false;
	MonitorScale = 10;
	Server = NULL;
	Sock = NULL;

	NumModes = 12;
}

MainFrame::~MainFrame()
{
	if (IsRunning) StopOS();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu file
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnFileNewClick(wxCommandEvent& event)
{
	if (IsEdited && wxYES == wxMessageBox(_("Save the current file?"), _("Note"), wxYES_NO))
	{
		Save();
	}

	DialogModelerWizard* MyDialog = new DialogModelerWizard(this);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		ifstream FileIn((MyDialog->GetTemplate()).ToStdString());
		if (!FileIn.is_open())
		{
			wxMessageBox(_("Error opening template file"), _("Error"));
			return;
		}

		string Val, Full;
		while (FileIn.good())
		{
			getline(FileIn, Val);
			Full += Val + "\n";
		}
		FileIn.close();
		CodeEdit->SetText(Full);
		//convert all EOLs to one mode. If you do not understand the reason of this call, comment it out and try out.
		//Some lines will not be detected by Scintilla
		CodeEdit->ConvertEOLs(wxSTC_EOL_LF);
		CodeEdit->EmptyUndoBuffer();
		IsEdited = false;
		FileName = "";
		SetTitle(IsEdited ? "*" : "" + Title + " - " + FileName);

		IsNodeNumOn = false;
		IsEleNumOn = false;
		ToolViewNodeNum->SetState(IsNodeNumOn);
		ToolViewEleNum->SetState(IsEleNumOn);
		OsVtkWin->Model->SetLabelOn(IsNodeNumOn, "Node");
		OsVtkWin->Model->SetLabelOn(IsEleNumOn, "Element");

		SendModelData();
		OsVtkWin->Model->InitRenderer();
		OsVtkWin->SetAxes();
		OsVtkWin->ChangeColor();
		OsVtkWin->ViewXYZ();
		OsVtkWin->ResetCamera();
		OsVtkWin->Render();
	}
}

void MainFrame::OnFileOpenClick(wxCommandEvent& event)
{
	wxString FileNameTmp = wxFileSelector(_("Open file"), "", "", "", wxT("*.tcl"));
	if (FileNameTmp != wxEmptyString)
	{
		ifstream FileIn(FileNameTmp.ToStdString());
		if (!FileIn.is_open())
		{
			wxMessageBox(_("Error opening file"), _("Error"));
			return;
		}
		FileName = FileNameTmp;
		string Val, Full;
		while (FileIn.good())
		{
			getline(FileIn, Val);
			Full += Val + "\n";
		}
		FileIn.close();
		CodeEdit->SetText(Full);
		//convert all EOLs to one mode. If you do not understand the reason of this call, comment it out and try out.
		//Some lines will not be detected by Scintilla
		CodeEdit->ConvertEOLs(wxSTC_EOL_LF);
		CodeEdit->EmptyUndoBuffer();
		IsEdited = false;
		SetTitle(IsEdited ? "*" : "" + Title + " - " + FileName);

		IsNodeNumOn = false;
		IsEleNumOn = false;
		ToolViewNodeNum->SetState(IsNodeNumOn);
		ToolViewEleNum->SetState(IsEleNumOn);
		OsVtkWin->Model->SetLabelOn(IsNodeNumOn, "Node");
		OsVtkWin->Model->SetLabelOn(IsEleNumOn, "Element");

		SendModelData();
		OsVtkWin->Model->InitRenderer();
		OsVtkWin->SetAxes();
		OsVtkWin->ChangeColor();
		OsVtkWin->ViewXYZ();
		OsVtkWin->ResetCamera();
		OsVtkWin->Render();
	}
}

void MainFrame::OnFileSaveClick(wxCommandEvent& event)
{
	Save();
}

void MainFrame::OnFileSaveAsClick(wxCommandEvent& event)
{
	wxString FileNameTmp = wxSaveFileSelector("", wxT("*.tcl"));
	if (FileNameTmp != wxEmptyString)
	{
		FileName = FileNameTmp;
		Save();
	}
}

void MainFrame::Save()
{
	if (FileName.length() <= 0)
	{
		wxString FileNameTmp = wxSaveFileSelector("", wxT("*.tcl"));
		if (FileNameTmp != wxEmptyString)
		{
			FileName = FileNameTmp;
		}
	}

	CodeEdit->SaveFile(FileName);
	IsEdited = false;
	SetTitle(IsEdited ? "*" : "" + Title + " - " + FileName);
}

void MainFrame::OnFileImportDxfClick(wxCommandEvent& event)
{
	DialogImportDxf* MyDialog = new DialogImportDxf(this);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		CodeEdit->InsertText(CodeEdit->GetCurrentPos(), MyDialog->GetData());
		SendModelData();
		OsVtkWin->Render();
		OsVtkWin->ViewXYZ();
	}
}

void MainFrame::OnFileExportNodeAndEleClick(wxCommandEvent& event)
{
	string FileNameTmp = wxSaveFileSelector("", wxT("*.tcl"));
	if (FileNameTmp != wxEmptyString)
	{
		ofstream FileEx(FileNameTmp.c_str());

		string FileDir;
		if (FileName == "")
		{
			FileDir = F.GetWorkPath().ToStdString();// + "\\TempFile";
		}
		else
		{
			FileDir = wxPathOnly(FileName).ToStdString();// + "\\TempFile";
		}


		//into work path
		wxSetWorkingDirectory(FileDir);

		wxCopyFile(FileName, "MainFileTmp1.tcl", true);
		TclInterFace *MyScript = new TclInterFace("MainFileTmp1.tcl");
		wxArrayString Result = MyScript->GetResult();

		int Num = Result.Count();
		string StrTmp;


		// get nodes
		for (int i = 0; i < Num; ++i)
		{
			stringstream SS;
			SS << Result.Item(i);
			SS >> StrTmp;
			if (StrTmp == "Node" || StrTmp == "node")
			{
				FileEx << Result.Item(i) << endl;
			}
		}

		// get element
		for (int i = 0; i < Num; ++i)
		{
			stringstream SS;
			SS << Result.Item(i);
			SS >> StrTmp;
			if (StrTmp == "element")
			{
				FileEx << StrTmp;
				SS >> StrTmp;
				while (!SS.eof())
				{
					SS >> StrTmp;
					FileEx << "    " << StrTmp;
				}
				FileEx << endl;
			}
		}

		// get fix fixX fixY fixZ
		for (int i = 0; i < Num; ++i)
		{
			stringstream SS;
			SS << Result.Item(i);
			SS >> StrTmp;
			if (StrTmp == "fix" || StrTmp == "fixX" || StrTmp == "fixY" || StrTmp == "fixZ")
			{
				FileEx << StrTmp;
				while (!SS.eof())
				{
					SS >> StrTmp;
					FileEx << "    " << StrTmp;
				}
				FileEx << endl;
			}
		}

		FileEx.close();
		wxRemoveFile("MainFileTmp1.tcl");
	}
}

void MainFrame::OnCloseFrame(wxCloseEvent& event)
{
	if (IsRunning) StopOS();
	Destroy();
}

void MainFrame::OnFileExitClick(wxCommandEvent& event)
{
	if (IsRunning) StopOS();
	Destroy();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu edit
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnEditUndoClick(wxCommandEvent& event)
{
	CodeEdit->Undo();
}

void MainFrame::OnEditRedoClick(wxCommandEvent& event)
{
	CodeEdit->Redo();
}

void MainFrame::OnEditCutClick(wxCommandEvent& event)
{
	CodeEdit->Cut();
}

void MainFrame::OnEditCopyClick(wxCommandEvent& event)
{
	CodeEdit->Copy();
}

void MainFrame::OnEditPasteClick(wxCommandEvent& event)
{
	CodeEdit->Paste();
}

void MainFrame::OnEditDeleteClick(wxCommandEvent& event)
{
	CodeEdit->DeleteBack();
}

void MainFrame::OnEditGotoClick(wxCommandEvent& event)
{
	int Num = CodeEdit->GetNumberOfLines();
	LastGoto = wxGetNumberFromUser(wxT(""), _("Line(L):"), _("Goto"), LastGoto, 0, Num, this);
	if (LastGoto >= 0) CodeEdit->GotoLine(LastGoto - 1);
}

void MainFrame::OnEditFindClick(wxCommandEvent &event)
{
	if (FindDialog)
	{
		delete FindDialog;
		FindDialog = NULL;
	}
	else
	{
		FindData.SetFlags(wxFR_DOWN);
		FindDialog = new wxFindReplaceDialog(this, &FindData, _("Find"), wxFR_NOWHOLEWORD);
		FindDialog->Show(true);
	}
}

void MainFrame::OnEditReplaceClick(wxCommandEvent &event)
{
	if (ReplaceDialog)
	{
		delete ReplaceDialog;
		ReplaceDialog = NULL;
	}
	else
	{
		FindData.SetFlags(wxFR_DOWN);
		ReplaceDialog = new wxFindReplaceDialog(this, &FindData, _("Find and replace"), wxFR_REPLACEDIALOG | wxFR_NOWHOLEWORD);
		ReplaceDialog->Show(true);
	}
}

void MainFrame::OnEditFindDialog(wxFindDialogEvent& event)
{
	wxEventType EType = event.GetEventType();

	if (EType == wxEVT_COMMAND_FIND || EType == wxEVT_COMMAND_FIND_NEXT)
	{
		int Idx;
		if (event.GetFlags()&wxFR_DOWN)
		{
			if (EType == wxEVT_COMMAND_FIND)
			{
				if (event.GetFlags()&wxFR_MATCHCASE)//区分大小写的情况
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, CodeEdit->GetLastPosition(), event.GetFindString(), wxSTC_FIND_MATCHCASE);
				}
				else
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, CodeEdit->GetLastPosition(), event.GetFindString());
				}
			}
			else//find next
			{
				if (event.GetFlags()&wxFR_MATCHCASE)//区分大小写的情况
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, CodeEdit->GetLastPosition(), event.GetFindString(), wxSTC_FIND_MATCHCASE);
				}
				else
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, CodeEdit->GetLastPosition(), event.GetFindString());
				}
			}
		}
		else//find up
		{
			if (EType == wxEVT_COMMAND_FIND)
			{
				if (event.GetFlags()&wxFR_MATCHCASE)//区分大小写的情况
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, 0, event.GetFindString(), wxSTC_FIND_MATCHCASE);
				}
				else
				{
					LastIndex = CodeEdit->GetInsertionPoint();
					Idx = CodeEdit->FindText(LastIndex, 0, event.GetFindString());
				}
			}
			else
			{
				if (event.GetFlags()&wxFR_MATCHCASE)//区分大小写的情况
				{
					LastIndex = CodeEdit->GetInsertionPoint() - 1;
					Idx = CodeEdit->FindText(LastIndex, 0, event.GetFindString(), wxSTC_FIND_MATCHCASE);
				}
				else
				{
					LastIndex = CodeEdit->GetInsertionPoint() - 1;
					Idx = CodeEdit->FindText(LastIndex, 0, event.GetFindString());
				}
			}
		}

		if (Idx >= 0)
		{
			CodeEdit->SetSelection(Idx, Idx + event.GetFindString().Length());
			CodeEdit->GotoPos(CodeEdit->GetSelectionEnd());
			CodeEdit->SetSelection(Idx, Idx + event.GetFindString().Length());
		}
	}
	else if (EType == wxEVT_COMMAND_FIND_REPLACE || EType == wxEVT_COMMAND_FIND_REPLACE_ALL)
	{
		if (EType == wxEVT_COMMAND_FIND_REPLACE_ALL)
		{
			//CodeEdit->Replace(0,CodeEdit->GetLastPosition(),event.GetReplaceString());
			wxString Str = CodeEdit->GetValue();
			Str.Replace(event.GetFindString(), event.GetReplaceString());
			CodeEdit->SetValue(Str);
		}
		else
		{
			//替换处理(没有向上向下处理，只有从光标处向下查)，就是先检查有没有选中，如果有则判断是否相等
			//是则替换这段内容，否则从光标处开始向下查找
			int From, To;
			CodeEdit->GetSelection(&From, &To);
			wxString StrSel = CodeEdit->GetStringSelection();
			if (StrSel == event.GetFindString())
			{
				CodeEdit->Replace(From, To, event.GetReplaceString());
			}
			//////////to find the next words//////////
			int Pos = CodeEdit->GetInsertionPoint();
			wxString Temp = CodeEdit->GetValue().SubString(Pos, CodeEdit->GetLastPosition() - 1);
			int i;
			if (event.GetFlags()&wxFR_MATCHCASE)//区分大小写的情况
			{
				i = Temp.Find(event.GetFindString().c_str());
			}
			else
			{
				i = Temp.Upper().Find(event.GetFindString().Upper().c_str());
			}

			if (i >= 0)
			{
				Pos += i;
				CodeEdit->SetSelection(Pos, Pos + event.GetFindString().Length());
				CodeEdit->GotoPos(CodeEdit->GetSelectionEnd());
			}
		}
	}
	else if (EType == wxEVT_COMMAND_FIND_CLOSE)
	{
		wxFindReplaceDialog *Dlg = event.GetDialog();

		int IdMenu;
		const wxChar *Txt;
		if (Dlg == FindDialog)
		{
			Txt = _("Find");
			FindDialog = NULL;
		}
		else if (Dlg == ReplaceDialog)
		{
			Txt = _("Replace");
			ReplaceDialog = NULL;
		}
		else
		{
			Txt = _("Unknown");
			IdMenu = wxID_ANY;

			wxFAIL_MSG(_("unexpected event"));
		}

		Dlg->Destroy();
	}
	else
	{
		wxLogError(_("Unknown find dialog event!"));
	}
}

void MainFrame::OnEditCommentClick(wxCommandEvent& event)
{
	if (!CodeEdit->GetSelectionEmpty())
	{
		int ST = CodeEdit->GetSelectionStart();
		int EN = CodeEdit->GetSelectionEnd();
		CodeEdit->InsertText(ST, wxT("#"));
		for (int i = ST; i <= EN; ++i)
		{
			char Ch = CodeEdit->GetCharAt(i);
			if (Ch == '\n')
			{
				++EN;
				++i;
				CodeEdit->InsertText(i, wxT("#"));
			}
		}
	}
}

void MainFrame::OnEditUncommentClick(wxCommandEvent& event)
{
	if (!CodeEdit->GetSelectionEmpty())
	{
		int ST = CodeEdit->GetSelectionStart();
		int EN = CodeEdit->GetSelectionEnd();
		for (int i = ST; i <= EN; ++i)
		{
			char Ch = CodeEdit->GetCharAt(i);
			if (Ch == '#')
			{
				--EN;
				CodeEdit->SetSelection(i, i);
				CodeEdit->Clear();
			}
		}
	}
}

void MainFrame::OnRightMenu(wxMouseEvent& event)
{
	RightMenu = new wxMenu;
	RightMenu->Append(wxID_MenuAnalyzeRun, _("Run"));
	RightMenu->AppendSeparator();
	RightMenu->Append(wxID_MenuEditUndo, _("Undo"));
	RightMenu->Append(wxID_MenuEditRedo, _("Redo"));
	RightMenu->AppendSeparator();
	RightMenu->Append(wxID_MenuEditCut, _("Cut"));
	RightMenu->Append(wxID_MenuEditCopy, _("Copy"));
	RightMenu->Append(wxID_MenuEditPaste, _("Paste"));
	RightMenu->Append(wxID_MenuEditDelete, _("Delete"));
	RightMenu->AppendSeparator();
	RightMenu->Append(wxID_MenuEditComment, _("Comment Selection"));
	RightMenu->Append(wxID_MenuEditUnComment, _("Un-Comment Selection"));
	PopupMenu(RightMenu, event.GetPosition());
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu view
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnViewWrapClick(wxCommandEvent& event)
{
	IsWrapMode = IsWrapMode ? false : true;
	MenuView->Check(wxID_MenuViewWrap, IsWrapMode);
	CodeEdit->SetWrapMode(IsWrapMode ? wxSTC_WRAP_WORD : wxSTC_WRAP_NONE);
}

void MainFrame::OnViewLineNumbersClick(wxCommandEvent& event)
{
	IsLineNumber = IsLineNumber ? false : true;
	MenuView->Check(wxID_MenuViewLineNumber, IsLineNumber);
	if (IsLineNumber)
	{
		CodeEdit->SetMarginType(0, wxSTC_MARGIN_NUMBER);
		CodeEdit->SetMarginWidth(0, CodeEdit->TextWidth(wxSTC_STYLE_LINENUMBER, wxT("_99999")));
	}
	else
	{
		CodeEdit->SetMarginWidth(0, 0);
	}
}

void MainFrame::OnViewLongLineMarker(wxCommandEvent& event)
{
	CodeEdit->SetEdgeMode(CodeEdit->GetEdgeMode() == 0 ? wxSTC_EDGE_LINE : wxSTC_EDGE_NONE);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu define
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnDefineMaterialsClick(wxCommandEvent& event)
{
}

void MainFrame::OnDefineSectionClick(wxCommandEvent& event)
{
	DialogSectionProperties* MyDialog = new DialogSectionProperties(this);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		// CodeEdit -> InsertText(CodeEdit -> GetCurrentPos(),MyDialog -> GetNodesData());
		// CodeEdit -> AppendText(MyDialog -> getNumOfOpeningDef());
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu analyze
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnAnalyzeSetAnalysisOpintionClick(wxCommandEvent& event)
{
	DialogSetAnalysisOpintion* MyDialog = new DialogSetAnalysisOpintion(this, &MonitorPort, &MonitorHost, &IsRtMonitor, &NumModes);
	if (MyDialog->ShowModal() == wxID_OK)
	{
	}
}

void MainFrame::OnAnalyzeRunClick(wxCommandEvent& event)
{
	if (!IsRunning)
	{
		if (ShowDeformedDialog != NULL)
		{
			ShowDeformedDialog->Destroy();
			ShowDeformedDialog = NULL;
		}

		if (RealTimeMonitorDeformDialog != NULL)
		{
			RealTimeMonitorDeformDialog->Destroy();
			RealTimeMonitorDeformDialog = NULL;

		}

		if (SetAnalysisOpintionDialog != NULL)
		{
			SetAnalysisOpintionDialog->Destroy();
			SetAnalysisOpintionDialog = NULL;
		}

		SetAnalysisOpintionDialog = new DialogSetAnalysisOpintion(this, &MonitorPort, &MonitorHost, &IsRtMonitor, &NumModes);
		if (SetAnalysisOpintionDialog->ShowModal() == wxID_OK)
		{
			RealTimeMonitorDeformDialog = new DialogRealTimeMonitorDeform(this, MonitorPort, MonitorHost, &MonitorScale);
			RealTimeMonitorDeformDialog->Show();
		}




		Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
		if (Config->GetOpenSEESPath() == "" || (!wxFileExists(Config->GetOpenSEESPath())))
		{
			Config->SetOpenSEESPath("");
			Config->SaveConfig();
			ChangeOpenSeesPath();
		}

		IsRunning = true;
		LogBox->ClearAll();
		Save();

		//Load Config file
		Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
		wxString OSPath = Config->GetOpenSEESPath();

		//into work path
		int Last = FileName.find_last_of('\\');
		wxString FileDir = FileName.SubString(0, Last - 1);
		wxSetWorkingDirectory(FileDir);
		if (!wxDirExists("OSLiteOutput"))
		{
			wxMkdir("OSLiteOutput", 777);
		}

		wxCopyFile(FileName, "MainFileTmp1.tcl", true);


		ifstream InFile("MainFileTmp1.tcl");
		ofstream OuFile("MainFileTmp.tcl");

		string Line;
		bool T = true;
		int Idx = 0;

		TclInterFace *MyScript = new TclInterFace("MainFileTmp1.tcl");
		wxArrayString Result = MyScript->GetResult();
		string StrTmp;

		ofstream AnalysisCaseListOut("OSLiteOutput\\DataIndex.txt");
		AnalysisCaseListOut << NumModes << endl;

		int LineSum = 0;
		AnalysisCase ACTmp;
		ACTmp.ID = 0;
		ACTmp.LineStart = ACTmp.LineEnd = -1;

		for (int i = 0; i < (int)Result.Count(); ++i)
		{
			stringstream SS;
			SS << Result.Item(i);
			SS >> StrTmp;

			if (StrTmp == "analyze")
			{
				int Len;
				SS >> Len;
				LineSum += Len;
			}

			if (LineSum != 0 && (StrTmp == "loadConst" || i == (int)Result.Count() - 1))
			{
				++ACTmp.ID;
				ACTmp.LineStart = ACTmp.LineEnd + 1;
				ACTmp.LineEnd += LineSum;
				AnalysisCaseListOut << ACTmp.ID << " " << ACTmp.LineStart << " " << ACTmp.LineEnd << endl;
				LineSum = 0;
			}

		}
		AnalysisCaseListOut.close();


		while (getline(InFile, Line))
		{
			OuFile << Line << endl;

			if (T && Line.find("model", 0) != string::npos)
			{


				OuFile << "recorder Node -file OSLiteOutput/NodeDisp.txt -time -node";
				for (int i = 0; i < (int)Result.Count(); ++i)
				{
					stringstream SS;
					SS << Result.Item(i);
					SS >> StrTmp;
					if (StrTmp == "Node" || StrTmp == "node")
					{
						int ID;
						SS >> ID;
						OuFile << " " << ID;
					}
				}
				OuFile << " -dof 1 2 3 disp;" << endl;

				if (IsRtMonitor)
				{
					OuFile << "recorder Node -tcp " << MonitorHost << " " << MonitorPort << " -time -node";
					for (int i = 0; i < (int)Result.Count(); ++i)
					{
						stringstream SS;
						SS << Result.Item(i);
						SS >> StrTmp;
						if (StrTmp == "Node" || StrTmp == "node")
						{
							int ID;
							SS >> ID;
							SS.clear();
							OuFile << " " << ID;
						}
					}
					OuFile << " -dof 1 2 3 disp;" << endl;
				}

				T = false;
			}

			/*
			else if (Line.find("analyze", 0) != string::npos)
			{
				stringstream SS;
				SS << Line;
				SS >> StrTmp;
				if (StrTmp == "analyze")
				{
					int Len;
					SS >> Len;
					LineSum += Len;
				}
			}
			else if ((Line.find("loadConst", 0) != string::npos && LineSum != 0))
			{
				stringstream SS;
				SS << Line;
				SS >> StrTmp;
				if (StrTmp == "loadConst")
				{
					++ACTmp.ID;
					ACTmp.LineStart = ACTmp.LineEnd + 1;
					ACTmp.LineEnd += LineSum;
					AnalysisCaseListOut << ACTmp.ID << " " << ACTmp.LineStart << " " << ACTmp.LineEnd << endl;
					LineSum = 0;
				}
			}
			*/
		}

		/*
		if (LineSum != 0)
		{
			++ACTmp.ID;
			ACTmp.LineStart = ACTmp.LineEnd + 1;
			ACTmp.LineEnd += LineSum;
			AnalysisCaseListOut << ACTmp.ID << " " << ACTmp.LineStart << " " << ACTmp.LineEnd << endl;
			//wxMessageBox("BBBBBBB");
		}*/

		//add Modal Analysis code
		if (NumModes > 0)
		{
			OuFile << endl << "set numModes " << NumModes << endl;


			//recorder  Node -file out/20.txt  -time  -nodeRange 1  725  -dof 1  2  3  eigen20 

			for (int i = 1; i <= NumModes; ++i)
			{
				OuFile << "recorder  Node -file OSLiteOutput/Mode" << i << ".txt  -time  -node";

				for (int j = 0; j < (int)Result.Count(); ++j)
				{
					stringstream SS;
					SS << Result.Item(j);
					SS >> StrTmp;
					if (StrTmp == "Node" || StrTmp == "node")
					{
						int ID;
						SS >> ID;
						SS.clear();
						OuFile << " " << ID;
					}
				}

				OuFile << " -dof 1 2 3 eigen" << i << endl;
			}

			OuFile << "set pi [expr acos(-1.0)]" << endl;
			OuFile << "set eigFID [open OSLiteOutput/EigenVal.txt w]" << endl;
			OuFile << "set lambda [eigen  -fullGenLapack    $numModes]" << endl;
			OuFile << "puts $eigFID \" lambda          omega           period          frequency\"" << endl;
			OuFile << "foreach lambda $lambda {" << endl;
			OuFile << "    set omega [expr sqrt($lambda)]" << endl;
			OuFile << "    set period [expr 2.0*$pi/$omega]" << endl;
			OuFile << "    set frequ [expr 1.0/$period]" << endl;
			OuFile << "    puts $eigFID [format \" %+1.6e  %+1.6e  %+1.6e  %+1.6e\" $lambda $omega $period $frequ]" << endl;
			OuFile << "}" << endl;
			OuFile << "close $eigFID" << endl;
			OuFile << "record" << endl;
		}

		InFile.close();
		OuFile.close();
		wxRemoveFile("MainFileTmp1.tcl");

		TcpDataCount = 0;
		TcpDataFlag = 'H';
		DeformList.clear();
		wxIPV4address Addr;
		Addr.Hostname(MonitorHost);
		Addr.Service(MonitorPort);
		Server = new wxSocketServer(Addr);
		if (!Server->Ok())
		{
			wxMessageBox(wxT("Listen Port Fail！/n"));
			return;
		}

		Server->SetEventHandler(*this, SERVER_ID);
		Server->SetNotify(wxSOCKET_CONNECTION_FLAG);
		Server->Notify(true);

		wxString Cmd = OSPath + " " + "MainFileTmp.tcl";
		AnalyzeProcess = new wxProcess();
		AnalyzeProcess->Redirect();
		if (wxExecute(Cmd, wxEXEC_ASYNC, AnalyzeProcess) > 0)
		{
			AnalyzeThread = new ThreadAnalyze("MainFileTmp.tcl", &IsRunning, AnalyzeProcess, this);
			AnalyzeThread->Create();
			AnalyzeThread->Run();
		}
		else
		{
			LogBox->AppendText("Creat process fail\n");
		}
	}
}

void MainFrame::OnAnalyzeStopClick(wxCommandEvent& event)
{
	StopOS();
}

void MainFrame::StopOS()
{
	if (SetAnalysisOpintionDialog != NULL)
	{
		SetAnalysisOpintionDialog->Destroy();
		SetAnalysisOpintionDialog = NULL;
	}

	if (RealTimeMonitorDeformDialog != NULL)
	{
		RealTimeMonitorDeformDialog->Destroy();
		RealTimeMonitorDeformDialog = NULL;
	}

	if (ShowDeformedDialog != NULL)
	{
		ShowDeformedDialog->Destroy();
		ShowDeformedDialog = NULL;
	}

	if (IsRunning)
	{
		if (AnalyzeProcess != NULL && AnalyzeProcess->GetPid() > 0)
		{
			wxProcess::Kill(AnalyzeProcess->GetPid(), wxSIGKILL);
		}

		wxCriticalSectionLocker enter(AnalyzeThreadCS);
		if (AnalyzeThread != NULL) // does the thread still exist?
		{
			AnalyzeThread->Kill();
		}
		IsRunning = false;
	}

	if (Server != NULL)
	{
		Server->Destroy();
	}

	if (Sock != NULL)
	{
		if (!Sock->IsClosed()) Sock->Destroy();
	}

	Server = NULL;
	Sock = NULL;
}

void MainFrame::OnOutputLog(wxThreadEvent& event)
{
	wxString Tmp = event.GetString();
	LogBox->AppendText(Tmp + "\n");
	LogBox->DocumentEnd();
	if (IsRunning == false) StopOS();
}

void MainFrame::DisplayNodeDeform(bool IsRealTime, double MaxDeform)
{
	map<int, NodeDeform> DeformdMap;
	for (int i = 0; i < NumOfNode; ++i)
	{
		DeformdMap[i].ID = NodeMap[i];
	}

	DeformList.pop_front();//time

	for (int i = 0; i < NumOfNode; ++i)
	{
		DeformdMap[i].X = DeformList.front();
		DeformList.pop_front();

		DeformdMap[i].Y = DeformList.front();
		DeformList.pop_front();

		DeformdMap[i].Z = DeformList.front();
		DeformList.pop_front();

		if (!Is3dModel)
		{
			swap(DeformdMap[i].Y, DeformdMap[i].Z);
			DeformdMap[i].Y = 0;
		}
	}

	for (auto ii = DeformdMap.begin(); ii != DeformdMap.end(); ++ii)
	{
		OsVtkWin->Model->ModifyScalars((*ii).second, IsRealTime, MaxDeform);

		(*ii).second.X *= MonitorScale;
		(*ii).second.Y *= MonitorScale;
		(*ii).second.Z *= MonitorScale;

		(*ii).second.X += NodeCond[(*ii).second.ID].X;
		(*ii).second.Y += NodeCond[(*ii).second.ID].Y;
		(*ii).second.Z += NodeCond[(*ii).second.ID].Z;

		OsVtkWin->Model->ModifyNode((*ii).second);
	}

	IsEleNumOn = false;
	ToolViewEleNum->SetState(0);
	OsVtkWin->Model->SetLabelOn(IsEleNumOn, "Element");

	OsVtkWin->Model->ModifyNode();
	OsVtkWin->Render();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu display
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnSetVtkSize(wxSizeEvent & event)
{
	if (OsVtkWin)
	{
		OsVtkWin->SetDefaultSize();
	}
}


void MainFrame::OnDisplayDeformedClick(wxCommandEvent& event)
{
	if (SetAnalysisOpintionDialog != NULL)
	{
		SetAnalysisOpintionDialog->Destroy();
		SetAnalysisOpintionDialog = NULL;
	}

	if (RealTimeMonitorDeformDialog != NULL)
	{
		RealTimeMonitorDeformDialog->Destroy();
		RealTimeMonitorDeformDialog = NULL;
	}

	if (NumOfNode != 0)
	{
		int Last = FileName.find_last_of('\\');
		wxString PathDir = FileName.SubString(0, Last - 1);
		delete(DeformArr);
		DeformArr = NULL;
		DeformArr = new double[3 * NumOfNode + 1];
		ShowDeformedDialog = new DialogShowDeformed(this, PathDir + wxT("\\OSLiteOutput"), DeformArr, &MonitorScale, NumOfNode, &MaxDeform);
		ShowDeformedDialog->Show();
	}
}

void MainFrame::OnRealTimeMonitorClick(wxCommandEvent& event)
{
	if (ShowDeformedDialog != NULL)
	{
		ShowDeformedDialog->Destroy();
		ShowDeformedDialog = NULL;
	}

	if (RealTimeMonitorDeformDialog == NULL)
	{
		RealTimeMonitorDeformDialog = new DialogRealTimeMonitorDeform(this, MonitorPort, MonitorHost, &MonitorScale);
		RealTimeMonitorDeformDialog->Show();
	}
}

void MainFrame::OnDisplayNodeDeformByDialog(wxCommandEvent& event)
{
	DeformList.clear();
	wxString AA = "";
	for (int i = 0; i < NumOfNode * 3 + 1; ++i)
	{
		DeformList.push_back(DeformArr[i]);
	}
	DisplayNodeDeform(false, MaxDeform);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu options
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnOptionsAutoCompClick(wxCommandEvent & event)
{
	IsAutoComp = IsAutoComp ? false : true;
	MenuView->Check(wxID_MenuViewWrap, IsAutoComp);
}

void MainFrame::OnOptionsColorsAndFontsClick(wxCommandEvent & event)
{
	DialogColorsAndFonts* MyDialog = new DialogColorsAndFonts(this);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		OsVtkWin->ChangeColor();
		OsVtkWin->Render();
		UpdateCodeEdit();
	}
}

void MainFrame::OnOptionsChangeOpenSeesPathClick(wxCommandEvent & event)
{
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	if (Config->GetOpenSEESPath() == "" || (!wxFileExists(Config->GetOpenSEESPath())))
	{
		Config->SetOpenSEESPath("");
		Config->SaveConfig();
	}

	ChangeOpenSeesPath();
}

void MainFrame::ChangeOpenSeesPath()
{
	DialogChangeOpenSeesPath* MyDialog = new DialogChangeOpenSeesPath(this);
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	if (MyDialog->ShowModal() != wxID_OK)
	{
		wxMessageBox(_("Current OpenSees.exe at ") + Config->GetOpenSEESPath());
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// menu help
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnAboutClick(wxCommandEvent & event)
{
	DialogAbout* MyDialog = new DialogAbout(this, Version, ReleaseDate, Author);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		//do nothing
		//just show about information
	}
}

void MainFrame::OnDonateClick(wxCommandEvent & event)
{
	DialogDonate* MyDialog = new DialogDonate(this);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		//do nothing
		//just show about information
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////
// tool bar
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnViewRefresh(wxCommandEvent& event)
{
	SendModelData();
	OsVtkWin->Model->InitRenderer();
	OsVtkWin->Render();
}

void MainFrame::OnViewXYZClick(wxCommandEvent& event)
{
	OsVtkWin->ViewXYZ();
}

void MainFrame::OnViewXZClick(wxCommandEvent& event)
{
	OsVtkWin->ViewXZ();
}

void MainFrame::OnViewXYClick(wxCommandEvent& event)
{
	OsVtkWin->ViewXY();
}

void MainFrame::OnViewYZClick(wxCommandEvent& event)
{
	OsVtkWin->ViewYZ();
}

void MainFrame::OnNodeNumOn(wxCommandEvent & event)
{
	IsNodeNumOn = IsNodeNumOn ? false : true;
	OsVtkWin->Model->SetLabelOn(IsNodeNumOn, "Node");
	OsVtkWin->Render();
}

void MainFrame::OnEleNumOn(wxCommandEvent & event)
{
	IsEleNumOn = IsEleNumOn ? false : true;
	OsVtkWin->Model->SetLabelOn(IsEleNumOn, "Element");
	OsVtkWin->Render();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// something about code edit
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::OnChange(wxKeyEvent& event)
{
	if (event.ControlDown())
	{
	}
	else
	{
		IsEdited = true;
		SetTitle(IsEdited ? "*" : "" + Title + " - " + FileName);
		event.Skip();
	}
}

void MainFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
	if (CodeEdit->IsMouseInWindow())
	{
		int Pos = CodeEdit->GetCurrentPos();
		int c1 = CodeEdit->GetCharAt(Pos);
		int c2 = (Pos > 1 ? CodeEdit->GetCharAt(Pos - 1) : 0);

		if (c2 == '(' || c2 == ')' || c1 == '(' || c1 == ')')
		{
			int sp = (c2 == '(' || c2 == ')') ? Pos - 1 : Pos;

			int q = CodeEdit->BraceMatch(sp);
			if (q == wxSTC_INVALID_POSITION)
			{
				CodeEdit->BraceBadLight(sp);
			}
			else
			{
				CodeEdit->BraceHighlight(sp, q);
			}
		}
		else if (c2 == '[' || c2 == ']' || c1 == '[' || c1 == ']')
		{
			int sp = (c2 == '[' || c2 == ']') ? Pos - 1 : Pos;

			int q = CodeEdit->BraceMatch(sp);
			if (q == wxSTC_INVALID_POSITION)
			{
				CodeEdit->BraceBadLight(sp);
			}
			else
			{
				CodeEdit->BraceHighlight(sp, q);
			}
		}
		else if (c2 == '{' || c2 == '}' || c1 == '{' || c1 == '}')
		{
			int sp = (c2 == '{' || c2 == '}') ? Pos - 1 : Pos;

			int q = CodeEdit->BraceMatch(sp);
			if (q == wxSTC_INVALID_POSITION)
			{
				CodeEdit->BraceBadLight(sp);
			}
			else
			{
				CodeEdit->BraceHighlight(sp, q);
			}
		}
		else
		{
			CodeEdit->BraceBadLight(wxSTC_INVALID_POSITION);    // remove light
		}


		int Start = CodeEdit->WordStartPosition(Pos, true);
		// require 3 characters to show auto-complete
		if (Pos - Start > 2 && !CodeEdit->AutoCompActive() && IsAutoComp == true && (!isalpha(CodeEdit->GetCharAt(Pos))))
		{
			wxString TrieStr = CodeEdit->GetTextRange(Start, Pos);
			TrieTree *CompWord = KeyWordTire->Query(TrieStr.mb_str(), KeyWordTire);
			if (CompWord != NULL)
			{
				wxString KeyList = KeyWordTire->GetKeyList(CompWord, TrieStr);
				CodeEdit->AutoCompShow(Pos - Start, KeyList);
			}
		}
	}
	else
	{
		CodeEdit->AutoCompCancel();
	}
}

void MainFrame::UpdateCodeEdit()
{
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	CodeFont = Config->GetFont("CodeFont");
	ModelFont = Config->GetFont("ModelFont");
	OutputFont = Config->GetFont("OutputFont");

	LogBox->StyleSetFont(wxSTC_STYLE_DEFAULT, OutputFont);
	CodeEdit->StyleSetFont(wxSTC_STYLE_DEFAULT, CodeFont);

	LogBox->StyleClearAll();

	CodeEdit->StyleClearAll();
	CodeEdit->SetLexer(wxSTC_LEX_TCL);

	CodeEdit->StyleSetForeground(wxSTC_TCL_BLOCK_COMMENT, wxColour(0, 128, 0));
	CodeEdit->StyleSetForeground(wxSTC_TCL_COMMENT, wxColour(0, 128, 0));
	CodeEdit->StyleSetForeground(wxSTC_TCL_COMMENTLINE, wxColour(0, 128, 0));
	CodeEdit->StyleSetForeground(wxSTC_TCL_COMMENT_BOX, wxColour(0, 128, 0));

	CodeEdit->StyleSetForeground(wxSTC_TCL_WORD, wxColour(128, 0, 128));
	CodeEdit->StyleSetForeground(wxSTC_TCL_WORD2, wxColour(128, 0, 128));

	CodeEdit->StyleSetForeground(wxSTC_TCL_NUMBER, wxColour(0, 128, 128));
	CodeEdit->StyleSetForeground(wxSTC_TCL_IN_QUOTE, wxColour(0, 128, 128));

	CodeEdit->StyleSetForeground(wxSTC_TCL_OPERATOR, wxColour(176, 0, 176));

	CodeEdit->StyleSetForeground(wxSTC_TCL_IDENTIFIER, wxColour(128, 0, 128));

	CodeEdit->StyleSetForeground(wxSTC_TCL_SUBSTITUTION, wxColour(204, 0, 0));
	CodeEdit->StyleSetForeground(wxSTC_TCL_SUB_BRACE, wxColour(204, 0, 0));

	CodeEdit->StyleSetForeground(wxSTC_TCL_MODIFIER, wxColour(255, 0, 255));

	CodeEdit->SetKeyWords(0, KeyWords);
	CodeEdit->SetKeyWords(2, KeyWords);
	CodeEdit->SetZoom(0.75);
	CodeEdit->CanCopy();
	CodeEdit->CanCut();
	CodeEdit->CanPaste();
	CodeEdit->SetCaretLineVisible(true);
	CodeEdit->SetCaretLineBackground(wxColour(191, 216, 216));
	CodeEdit->AutoCompActive();
	CodeEdit->AutoCompSetIgnoreCase(true);
	CodeEdit->SetWrapMode(IsWrapMode ? wxSTC_WRAP_WORD : wxSTC_WRAP_NONE);
	CodeEdit->SetEdgeColumn(80);
	CodeEdit->SetEdgeMode(wxSTC_EDGE_LINE);

	CodeEdit->StyleSetBackground(wxSTC_STYLE_BRACELIGHT, wxColour(0xff, 0xcc, 0x00));        // brace highlight
	CodeEdit->StyleSetBackground(wxSTC_STYLE_BRACEBAD, wxColour(0xff, 0x33, 0x33));        // brace bad highlight
	CodeEdit->StyleSetBold(wxSTC_STYLE_BRACELIGHT, TRUE);
	CodeEdit->StyleSetBold(wxSTC_STYLE_BRACEBAD, TRUE);

	//CodeEdit->SetAutomaticFold(0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// something about model view
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainFrame::SendModelData()
{
	OsVtkWin->Model->Reset();

	//save os script as temp file
	string FileDir;
	if (FileName == "")
	{
		FileDir = F.GetWorkPath().ToStdString();
	}
	else
	{
		FileDir = wxPathOnly(FileName).ToStdString();
	}

	wxSetWorkingDirectory(FileDir);
	CodeEdit->SaveFile("TEMPFILE");

	TclInterFace *MyScript = new TclInterFace("TEMPFILE");
	wxArrayString Result = MyScript->GetResult();
	string StrTmp;

	//Check 3D or 2D
	Is3dModel = false;
	for (int i = 0; i < (int)Result.Count(); ++i)
	{
		stringstream SS;
		SS << Result.Item(i);
		SS >> StrTmp;
		double CoordZ;
		if (StrTmp == "Node" || StrTmp == "node")
		{
			SS >> CoordZ;// ID;
			SS >> CoordZ;// X;
			SS >> CoordZ;// Y;
			SS >> CoordZ;// Z;
			if (fabs(CoordZ) > ESP)
			{
				Is3dModel = true;
				break;
			}
		}
	}

	NodeCond.clear();
	NumOfNode = 0;
	int Cnt = 0;
	for (int i = 0; i < (int)Result.Count(); ++i)
	{
		stringstream SS;
		SS << Result.Item(i);
		SS >> StrTmp;

		// get nodes
		if (StrTmp == "Node" || StrTmp == "node")
		{
			++NumOfNode;
			StrTmp.clear();
			Node NodeTmp;
			SS >> NodeTmp.ID;
			NodeMap[Cnt++] = NodeTmp.ID;

			SS >> NodeTmp.X;
			if (Is3dModel)
			{
				SS >> NodeTmp.Y;
				SS >> NodeTmp.Z;
			}
			else
			{
				SS >> NodeTmp.Z;
				SS >> NodeTmp.Y;
			}
			OsVtkWin->Model->InsertNode(NodeTmp);
			NodeCond[NodeTmp.ID] = NodeTmp;
		}
	}


	for (int i = 0; i < (int)Result.Count(); ++i)
	{
		stringstream SS;
		SS << Result.Item(i);
		SS >> StrTmp;

		// get element
		if (StrTmp == "element")
		{
			SS >> StrTmp;
			string StrTmp2;
			SS >> StrTmp2;
			if (StrTmp == "D2N3")
			{
				Shell ShellTmp;
				SS >> ShellTmp.ID;
				ShellTmp.NumP = 3;
				for (int i = 0; i < ShellTmp.NumP; ++i)
				{
					SS >> ShellTmp.Node[i];
				}
				OsVtkWin->Model->InsertShell(ShellTmp);
			}
			else if (StrTmp == "D2N4")
			{
				Shell ShellTmp;
				SS >> ShellTmp.ID;
				ShellTmp.NumP = 4;
				for (int i = 0; i < ShellTmp.NumP; ++i)
				{
					SS >> ShellTmp.Node[i];
				}
				OsVtkWin->Model->InsertShell(ShellTmp);
			}
			else if (StrTmp == "D2N9")
			{
				Shell9N ShellTmp;
				SS >> ShellTmp.ID;
				for (int i = 0; i < 9; ++i)
				{
					SS >> ShellTmp.Node[i];
				}
				OsVtkWin->Model->InsertShell9N(ShellTmp);
			}
			else if (StrTmp == "D3N8")
			{
				Brick8N SolidTmp;
				SS >> SolidTmp.ID;
				for (int i = 0; i < 8; ++i)
				{
					SS >> SolidTmp.Node[i];
				}
				OsVtkWin->Model->InsertBrick8N(SolidTmp);
			}
			else if (StrTmp == "D3N12")
			{
				MasonPan MasonPanTmp;
				SS >> MasonPanTmp.ID;
				for (int i = 0; i < 12; ++i)
				{
					SS >> MasonPanTmp.Node[i];
				}
				OsVtkWin->Model->InsertMasonPan(MasonPanTmp);
			}
			else if (StrTmp == "D3N20")
			{
				Brick20N SolidTmp;
				SS >> SolidTmp.ID;
				for (int i = 0; i < 20; ++i)
				{
					SS >> SolidTmp.Node[i];
				}
				OsVtkWin->Model->InsertBrick20N(SolidTmp);
			}
			else if (StrTmp == "Joint2D")
			{
				Joint2D Joint2DTmp;
				SS >> Joint2DTmp.ID;
				SS >> Joint2DTmp.Node[0];
				SS >> Joint2DTmp.Node[1];
				SS >> Joint2DTmp.Node[2];
				SS >> Joint2DTmp.Node[3];
				SS >> Joint2DTmp.Ndc;
				OsVtkWin->Model->InsertJoint2D(Joint2DTmp);
			}
			else if (StrTmp == "beamColumnJoint")
			{
				BeamColumnJoint BeamColumnJointTmp;
				SS >> BeamColumnJointTmp.ID;
				SS >> BeamColumnJointTmp.Node[0];
				SS >> BeamColumnJointTmp.Node[1];
				SS >> BeamColumnJointTmp.Node[2];
				SS >> BeamColumnJointTmp.Node[3];
				OsVtkWin->Model->InsertBeamColumnJoint(BeamColumnJointTmp);
			}
			else
			{
				Link LineTmp;
				SS >> LineTmp.ID;
				SS >> LineTmp.NodeA;
				SS >> LineTmp.NodeB;
				OsVtkWin->Model->InsertLine(LineTmp);
			}
		}

		// get rigidLink
		else if (StrTmp == "rigidLink")
		{
			SS >> StrTmp;
			if (StrTmp == "bar" || StrTmp == "beam")
			{
				Link LineTmp;
				SS >> LineTmp.NodeA;
				SS >> LineTmp.NodeB;
				OsVtkWin->Model->InsertRigidLink(LineTmp);
			}
		}

		// get equalDOF
		else if (StrTmp == "equalDOF")
		{
			Link LineTmp;
			SS >> LineTmp.NodeA;
			SS >> LineTmp.NodeB;
			OsVtkWin->Model->InsertEqualDof(LineTmp);
		}
	}

	wxRemoveFile("TEMPFILE");
}

void MainFrame::OnServerEvent(wxSocketEvent& event)
{
	Sock = Server->Accept(false);
	Sock->SetEventHandler(*this, SOCKET_ID);
	Sock->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
	Sock->Notify(true);
}

void MainFrame::OnSocketEvent(wxSocketEvent& event)
{
	//Sock->SetFlags(wxSOCKET_BLOCK);
	//Sock->SetFlags(wxSOCKET_NOWAIT);
	Sock->SetFlags(wxSOCKET_WAITALL);
	//Sock->SetFlags(wxSOCKET_NONE);

	switch (event.GetSocketEvent())
	{
	case wxSOCKET_INPUT:
	{
		Sock->SetNotify(wxSOCKET_LOST_FLAG);
		char *Buff;
		Buff = new char[8];
		Sock->Read(Buff, 8);
		void *PV = Buff;
		double *PD = NULL;
		PD = (double *)PV;

		if (TcpDataFlag != 'H' && TcpDataFlag != 'N')
		{
			++TcpDataCount;
			DeformList.push_back(*PD);
		}

		switch (TcpDataFlag)
		{
		case 'H':
			TcpDataFlag = 'N';
			break;
		case 'N':
			TcpDataFlag = 'T';
			break;
		case 'T':
			TcpDataFlag = 'X';
			TcpDataCount = 0;
			break;
		}

		if (TcpDataCount == 3 * NumOfNode)
		{
			TcpDataFlag = 'N';
			TcpDataCount = 0;
			DisplayNodeDeform(true);
		}

		Sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
		break;
	}
	case wxSOCKET_LOST:
	{
		Sock->Destroy();
		break;
	}
	default:;
	}
}

void MainFrame::OnSetState(wxCommandEvent& event)
{
	if (event.GetString() == "RealTimeMonitorDeformDialog")
	{
		RealTimeMonitorDeformDialog->Destroy();
		RealTimeMonitorDeformDialog = NULL;
	}

	else if (event.GetString() == "ShowDeformedDialog")
	{
		ShowDeformedDialog->Destroy();
		ShowDeformedDialog = NULL;
	}
}
