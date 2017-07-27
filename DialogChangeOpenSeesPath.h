// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogChangeOpenSeesPath__
#define __DialogChangeOpenSeesPath__

#include <wx/wx.h>
#include "GuiBase/DialogChangeOpenSeesPathBase.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"

class DialogChangeOpenSeesPath : public DialogChangeOpenSeesPathBase
{
public:
	DialogChangeOpenSeesPath(wxWindow* Parent);
	~DialogChangeOpenSeesPath();
	void SelectOpenSEES(wxCommandEvent& event);
private:
	OSLiteConfig *Config;
};

#endif
