// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogQuickMaterial.h"

DialogQuickMaterial::DialogQuickMaterial(wxWindow* parent)
	: DialogQuickMaterialBase(parent)
{
	MatVector.clear();
	wxTextFile FileInput;
	if (FileInput.Open(wxT("../Materials/list.txt")))
	{
		int num = FileInput.GetLineCount();
		for (int i = 0; i < num; ++i)
		{
			wxString StrTmp = FileInput.GetLine(i);
			MatVector.push_back(StrTmp);
			int p = StrTmp.find_first_of(' ', 0);
			wxString SubStr = StrTmp.SubString(0, p - 1);
			SetType.insert(SubStr);
		}
		FileInput.Close();
		int idx = 0;
		for (auto jj = SetType.begin(); jj != SetType.end(); ++jj)
		{
			ComboBoxType->Insert(*jj, idx++);
		}
		wxString InitMatType = "uniaxialMaterial";
		ComboBoxType->SetValue(InitMatType);
		// SetMaterialChoice(InitMatType);
	}
	else
	{
		wxMessageBox(_T("I can't open ../Materials/list.txt"));
	}
}

DialogQuickMaterial::~DialogQuickMaterial()
{
}

void DialogQuickMaterial::SetMaterialChoice(wxString MatType)
{
	ComboBoxMaterial->Clear();
	int idx = 0;
	bool T = true;
	for (auto ii = MatVector.begin(); ii != MatVector.end(); ++ii)
	{
		wxString MatStr = *ii;
		int p = MatStr.find_first_of(' ', 0);
		wxString SubStr = MatStr.SubString(0, p - 1);
		if (SubStr == MatType)
		{
			SubStr = MatStr.SubString(p + 1, MatStr.length());
			ComboBoxMaterial->Insert(SubStr, idx++);
			if (T)
			{
				ComboBoxMaterial->SetValue(SubStr);
				T = false;
			}
		}
	}
}

void DialogQuickMaterial::MatTypeComboxValueChange(wxCommandEvent& event)
{
	wxString MatType = ComboBoxType->GetValue();
	SetMaterialChoice(MatType);
}
