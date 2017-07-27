// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogQuickMaterial__
#define __DialogQuickMaterial__

#include <wx/wx.h>
#include <wx/textfile.h>
#include "GuiBase/DialogQuickMaterialBase.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class DialogQuickMaterial : public DialogQuickMaterialBase
{
public:
	DialogQuickMaterial(wxWindow* parent);
	~DialogQuickMaterial();

protected:
	vector<wxString> MatVector;
	set<wxString> SetType;
	void SetMaterialChoice(wxString MatType);
	virtual void MatTypeComboxValueChange(wxCommandEvent& event);
};

#endif //__DialogModelerWizard__
