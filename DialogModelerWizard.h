// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogModelerWizard__
#define __DialogModelerWizard__

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include "GuiBase/DialogModelerWizardBase.h"

class DialogModelerWizard : public DialogModelerWizardBase
{
public:
	DialogModelerWizard(wxWindow* parent);
	~DialogModelerWizard();
	virtual wxString GetTemplate();

protected:
	wxString TemplatePath;
	// protected event handlers
	virtual void OnBlankClick(wxCommandEvent& event);
	virtual void OnBeamClick(wxCommandEvent& event);
	virtual void On2DTrussesClick(wxCommandEvent& event);
	virtual void On3DTrussesClick(wxCommandEvent& event);
	virtual void On2DFramesClick(wxCommandEvent& event);
	virtual void On3DFramesClick(wxCommandEvent& event);
	virtual void OnPushoverClick(wxCommandEvent& event);
	virtual wxString GetWorkPath();
};

#endif //__DialogModelerWizard__
