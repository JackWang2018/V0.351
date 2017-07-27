// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogModelerWizard.h"

DialogModelerWizard::DialogModelerWizard(wxWindow* parent)
	: DialogModelerWizardBase(parent)
{
}

DialogModelerWizard::~DialogModelerWizard()
{
}

void DialogModelerWizard::OnBlankClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/Blank.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::OnBeamClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/Beam.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::On2DTrussesClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/2D_Trusses.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::On3DTrussesClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/3D_Trusses.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::On2DFramesClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/2D_Frames.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::On3DFramesClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/3D_Frames.tcl";
	EndModal(wxID_OK);
}

void DialogModelerWizard::OnPushoverClick(wxCommandEvent& event)
{
	wxString WorkPath = GetWorkPath();
	TemplatePath = WorkPath.substr(0, WorkPath.Len() - 4) + "Templates/Pushover.tcl";
	EndModal(wxID_OK);
}

wxString DialogModelerWizard::GetTemplate()
{
	return TemplatePath;
}

wxString DialogModelerWizard::GetWorkPath()
{
	wxString AppPath;
	wxStandardPathsBase& stpd = wxStandardPaths::Get();

	wxFileName ExeFile(stpd.GetExecutablePath());
	AppPath = ExeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);

	return AppPath;
}
