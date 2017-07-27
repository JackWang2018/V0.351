// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogImportDxf.h"
#include "DxfInterFace.h"
#include "DxfData.h"

DialogImportDxf::DialogImportDxf(wxWindow* parent)
	: DialogImportDxfBase(parent)
{
}

DialogImportDxf::~DialogImportDxf()
{
}

void DialogImportDxf::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void DialogImportDxf::OnOpenClick(wxCommandEvent& event)
{
	wxFileDialog* inputDxfDialog = new wxFileDialog(this);
	wxString wildcard = wxT("*.dxf");
	inputDxfDialog->SetWildcard(wildcard);
	if (inputDxfDialog->ShowModal() == wxID_OK)
	{
		wxString DxfFilePath = inputDxfDialog->GetPath();
		DxfFilePathInputTextCtrl->SetValue(DxfFilePath);
		string file = DxfFilePath.ToStdString();

		// First read a dwg or dxf file
		dx_iface* Input = new dx_iface();
		bool BadState = Input->fileImport(DxfFilePath.ToStdString(), &fData);
		if (!BadState)
		{
			wxMessageBox(_("Error reading file!"), wxT("Error"));
			delete Input;
		}

		JointLayerComboBox->Clear();
		LineLayerComboBox->Clear();
		NLLinkLayerComboBox->Clear();
		ShellLayerComboBox->Clear();
		SolidLayerComboBox->Clear();

		JointLayerComboBox->Insert(_T("NONE"), 0);
		LineLayerComboBox->Insert(_T("NONE"), 0);
		NLLinkLayerComboBox->Insert(_T("NONE"), 0);
		ShellLayerComboBox->Insert(_T("NONE"), 0);
		SolidLayerComboBox->Insert(_T("NONE"), 0);

		JointLayerComboBox->SetSelection(0);
		LineLayerComboBox->SetSelection(0);
		NLLinkLayerComboBox->SetSelection(0);
		ShellLayerComboBox->SetSelection(0);
		SolidLayerComboBox->SetSelection(0);

		int Cnt = 1;
		for (auto ii = fData.layers.begin(); ii != fData.layers.end(); ++ii)
		{
			wxString STmp = (*ii).name;
			JointLayerComboBox->Insert(STmp, Cnt);
			LineLayerComboBox->Insert(STmp, Cnt);
			NLLinkLayerComboBox->Insert(STmp, Cnt);
			ShellLayerComboBox->Insert(STmp, Cnt);
			SolidLayerComboBox->Insert(STmp, Cnt);

			STmp = STmp.Lower();
			if (STmp.find("frame") != wxNOT_FOUND ||
				STmp.find("truss") != wxNOT_FOUND ||
				STmp.find("beam") != wxNOT_FOUND ||
				STmp.find("column") != wxNOT_FOUND)
			{
				LineLayerComboBox->SetSelection(Cnt);
			}
			else if (STmp.find("shell") != wxNOT_FOUND)
			{
				ShellLayerComboBox->SetSelection(Cnt);
			}
			else if (STmp.find("point") != wxNOT_FOUND ||
				STmp.find("joint") != wxNOT_FOUND)
			{
				JointLayerComboBox->SetSelection(Cnt);
			}

			++Cnt;
		}

		delete Input;
	}
}

void DialogImportDxf::OnOKClick(wxCommandEvent& event)
{
	wxString DxfFilePath = DxfFilePathInputTextCtrl->GetValue();
	string file = DxfFilePath.ToStdString();

	// First read a dwg or dxf file
	dx_iface* Input = new dx_iface();
	bool BadState = Input->fileImport(DxfFilePath.ToStdString(), &fData);
	if (!BadState)
	{
		wxMessageBox(wxT("Error reading file!"), wxT("Error"));
		delete Input;
	}

	// dxf was stoned in fData
	wxString JointLayer = JointLayerComboBox->GetStringSelection();
	wxString FrameLayer = LineLayerComboBox->GetStringSelection();
	wxString ShellLayer = ShellLayerComboBox->GetStringSelection();
	wxString SolidLayer = SolidLayerComboBox->GetStringSelection();
	int NodeIdx = 1;
	int EleIdx = 1;
	for (auto ii = fData.mBlock->ent.begin(); ii != fData.mBlock->ent.end(); ++ii)
	{
		if ((*ii)->eType == DRW::POINT)
		{
			if ((*ii)->layer == JointLayer.ToStdString())
			{
				int IDP;
				DRW_Point* Point = static_cast<DRW_Point*>(*ii);
				Node NodeInsert;
				NodeInsert.X = (Point->basePoint).x;
				NodeInsert.Y = (Point->basePoint).y;
				NodeInsert.Z = (Point->basePoint).z;
				IDP = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDP < 0)
				{
					IDP = NodeIdx++;
					NodeInsert.ID = IDP;
					NodeArr.push_back(NodeInsert);
				}
			}
		}
		else if ((*ii)->eType == DRW::LINE)
		{
			if ((*ii)->layer == FrameLayer.ToStdString())
			{
				int IDA, IDB;
				DRW_Line* Line = static_cast<DRW_Line*>(*ii);
				Link LinkInsert;
				Node NodeInsert;
				NodeInsert.X = (Line->basePoint).x;
				NodeInsert.Y = (Line->basePoint).y;
				NodeInsert.Z = (Line->basePoint).z;
				IDA = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDA < 0)
				{
					IDA = NodeIdx++;
					NodeInsert.ID = IDA;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Line->secPoint).x;
				NodeInsert.Y = (Line->secPoint).y;
				NodeInsert.Z = (Line->secPoint).z;
				IDB = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDB < 0)
				{
					IDB = NodeIdx++;
					NodeInsert.ID = IDB;
					NodeArr.push_back(NodeInsert);
				}
				if (CheckLink(IDA, IDB) == false)
				{
					LinkInsert.NodeA = IDA;
					LinkInsert.NodeB = IDB;
					LinkInsert.ID = EleIdx++;
					LinkArr.push_back(LinkInsert);
				}
			}
		}
		else if ((*ii)->eType == DRW::E3DFACE)
		{
			if ((*ii)->layer == ShellLayer.ToStdString())
			{
				int IDI, IDJ, IDK, IDL;
				DRW_3Dface* Quad = static_cast<DRW_3Dface*>(*ii);
				Shell ShellInsert;
				Node NodeInsert;

				NodeInsert.X = (Quad->basePoint).x;
				NodeInsert.Y = (Quad->basePoint).y;
				NodeInsert.Z = (Quad->basePoint).z;
				IDI = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDI < 0)
				{
					IDI = NodeIdx++;
					NodeInsert.ID = IDI;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Quad->secPoint).x;
				NodeInsert.Y = (Quad->secPoint).y;
				NodeInsert.Z = (Quad->secPoint).z;
				IDJ = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDJ < 0)
				{
					IDJ = NodeIdx++;
					NodeInsert.ID = IDJ;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Quad->thirdPoint).x;
				NodeInsert.Y = (Quad->thirdPoint).y;
				NodeInsert.Z = (Quad->thirdPoint).z;
				IDK = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDK < 0)
				{
					IDK = NodeIdx++;
					NodeInsert.ID = IDK;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Quad->fourPoint).x;
				NodeInsert.Y = (Quad->fourPoint).y;
				NodeInsert.Z = (Quad->fourPoint).z;
				IDL = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDL < 0)
				{
					IDL = NodeIdx++;
					NodeInsert.ID = IDL;
					NodeArr.push_back(NodeInsert);
				}

				if (CheckQuad(IDI, IDJ, IDK, IDL) == false)
				{
					ShellInsert.Node[0] = IDI;
					ShellInsert.Node[1] = IDJ;
					ShellInsert.Node[2] = IDK;
					ShellInsert.Node[3] = IDL;
					ShellInsert.ID = EleIdx++;
					ShellArr.push_back(ShellInsert);
				}
			}
		}
		/*
		else if ((*ii)->eType == DRW::SOLID)
		{
			if ((*ii)->layer == SolidLayer.ToStdString())
			{
				int IDI, IDJ, IDK, IDL;
				DRW_3Dface* Solid = static_cast<PolyPolygon*>(*ii);
				Shell SolidInsert;
				Node NodeInsert;

				NodeInsert.X = (Solid->basePoint).x;
				NodeInsert.Y = (Solid->basePoint).y;
				NodeInsert.Z = (Solid->basePoint).z;
				IDI = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDI < 0)
				{
					IDI = NodeIdx++;
					NodeInsert.ID = IDI;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Solid->secPoint).x;
				NodeInsert.Y = (Solid->secPoint).y;
				NodeInsert.Z = (Solid->secPoint).z;
				IDJ = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDJ < 0)
				{
					IDJ = NodeIdx++;
					NodeInsert.ID = IDJ;
					NodeArr.push_back(NodeInsert);
				}
				NodeInsert.X = (Solid->thirdPoint).x;
				NodeInsert.Y = (Solid->thirdPoint).y;
				NodeInsert.Z = (Solid->thirdPoint).z;
				IDK = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDK < 0)
				{
					IDK = NodeIdx++;
					NodeInsert.ID = IDK;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Solid->fourPoint).x;
				NodeInsert.Y = (Solid->fourPoint).y;
				NodeInsert.Z = (Solid->fourPoint).z;
				IDL = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDL < 0)
				{
					IDL = NodeIdx++;
					NodeInsert.ID = IDL;
					NodeArr.push_back(NodeInsert);
				}

				NodeInsert.X = (Solid->).x;
				NodeInsert.Y = (Solid->fourPoint).y;
				NodeInsert.Z = (Solid->fourPoint).z;
				IDL = GetNodeID(NodeInsert.X, NodeInsert.Y, NodeInsert.Z);
				if (IDL < 0)
				{
					IDL = NodeIdx++;
					NodeInsert.ID = IDL;
					NodeArr.push_back(NodeInsert);
				}

				if (CheckQuad(IDI, IDJ, IDK, IDL) == false)
				{
					ShellInsert.Node[0] = IDI;
					ShellInsert.Node[1] = IDJ;
					ShellInsert.Node[2] = IDK;
					ShellInsert.Node[3] = IDL;
					ShellInsert.ID = EleIdx++;
					ShellArr.push_back(ShellInsert);
				}
			}
		}*/
	}
	EndModal(wxID_OK);
}

void DialogImportDxf::OnCancelClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

int DialogImportDxf::GetNodeID(double X, double Y, double Z)
{
	for (auto ii = NodeArr.begin(); ii != NodeArr.end(); ++ii)
	{
		if (fabs((*ii).X - X) <= ESP && fabs((*ii).Y - Y) <= ESP && fabs((*ii).Z - Z) <= ESP)
		{
			return (*ii).ID;
		}
	}
	return -1;
}

bool DialogImportDxf::CheckLink(int IDA, int IDB)
{
	for (auto ii = LinkArr.begin(); ii != LinkArr.end(); ++ii)
	{
		if (((*ii).NodeA == IDA && (*ii).NodeB == IDB) || ((*ii).NodeA == IDB && (*ii).NodeB == IDA))
		{
			return true;
		}
	}
	return false;
}

bool DialogImportDxf::CheckQuad(int IDI, int IDJ, int IDK, int IDL)
{
	for (auto ii = ShellArr.begin(); ii != ShellArr.end(); ++ii)
	{
		if (((*ii).Node[0] == IDI && (*ii).Node[1] == IDJ) || ((*ii).Node[2] == IDK && (*ii).Node[3] == IDL))
		{
			return true;
		}
	}
	return false;
}

wxString DialogImportDxf::GetData()
{
	NodesData = "";
	NodesData += "# Create nodes & add to Domain - command: node nodeId xCrd yCrd zCrd\n";
	for (auto ii = NodeArr.begin(); ii != NodeArr.end(); ++ii)
	{
		NodesData += "node\t" + F.ToString((*ii).ID) + "\t" + F.ToString((*ii).X) + "\t" + F.ToString((*ii).Y) + "\t" +
			F.ToString((*ii).Z) + "\n";
	}

	LinksData = "";
	LinksData += "# Create elements - command: element eleType $eleTag $iNode $jNode ......\n";
	wxString EleType = LineTypeComboBox->GetValue();
	for (auto ii = LinkArr.begin(); ii != LinkArr.end(); ++ii)
	{
		LinksData += "element\t" + EleType + "\t" + F.ToString((*ii).ID) + "\t" +
			F.ToString((*ii).NodeA) + "\t" +
			F.ToString((*ii).NodeB) + "\t" + "\n";
	}

	QuadsData = "";
	QuadsData += "# Create elements - command: element eleType $eleTag $iNode $jNode $kNode $lNode......\n";
	EleType = ShellTypeComboBox->GetValue();
	for (auto ii = ShellArr.begin(); ii != ShellArr.end(); ++ii)
	{
		QuadsData += "element\t" + EleType + "\t" + F.ToString((*ii).ID) + "\t" +
			F.ToString((*ii).Node[0]) + "\t" +
			F.ToString((*ii).Node[1]) + "\t" +
			F.ToString((*ii).Node[2]) + "\t" +
			F.ToString((*ii).Node[3]) + "\t" + "\n";
	}

	return NodesData + "\n" + LinksData + "\n" + QuadsData;
}
