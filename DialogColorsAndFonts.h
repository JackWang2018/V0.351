// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogColorsAndFonts__
#define __DialogColorsAndFonts__

#include <wx/wx.h>
#include "GuiBase/DialogColorsAndFontsBase.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"

class DialogColorsAndFonts : public DialogColorsAndFontsBase
{
public:
	DialogColorsAndFonts(wxWindow* parent);
	~DialogColorsAndFonts();

protected:
	// protected event handlers
	ComFunc F;
	OSLiteConfig *Config;

	virtual void OnCancelClick(wxCommandEvent& event);
	virtual void OnOKClick(wxCommandEvent& event);

};

#endif
