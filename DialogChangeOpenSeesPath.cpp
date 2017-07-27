// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogChangeOpenSeesPath.h"

DialogChangeOpenSeesPath::DialogChangeOpenSeesPath(wxWindow* Parent)
	: DialogChangeOpenSeesPathBase(Parent)
{
	ComFunc F;
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	OpenSEESPathCtrl->Clear();
	OpenSEESPathCtrl->AppendText(Config->GetOpenSEESPath());
}

DialogChangeOpenSeesPath::~DialogChangeOpenSeesPath()
{
}

void DialogChangeOpenSeesPath::SelectOpenSEES(wxCommandEvent& event)
{
	wxFileDialog* MyDialog = new wxFileDialog(this, _("Select Opensees.exe"),
		wxEmptyString, wxEmptyString, wxT("*.exe"),
		wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR);
	if (MyDialog->ShowModal() == wxID_OK)
	{
		wxString FilePath = MyDialog->GetPath();
		OpenSEESPathCtrl->Clear();
		OpenSEESPathCtrl->AppendText(FilePath);
		Config->SetOpenSEESPath(FilePath);
		Config->SaveConfig();
	}
	EndModal(wxID_OK);
}
