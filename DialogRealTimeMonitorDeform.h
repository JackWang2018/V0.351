// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogRealTimeMonitorDeform__
#define __DialogRealTimeMonitorDeform__

#include <wx/wx.h>  
#include <wx/socket.h>
#include <wx/slider.h>
#include "GuiBase/DialogRealTimeMonitorDeformBase.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"
#include "DeclareUserEvent.h"

class DialogRealTimeMonitorDeform : public DialogRealTimeMonitorDeformBase
{
public:
	DialogRealTimeMonitorDeform(wxWindow* HandleIn, int PortIn, wxString IPIn,int *ScaleIn);
	~DialogRealTimeMonitorDeform();
	virtual void OnCloseDialog(wxCloseEvent& event);
	virtual void OnChanged(wxScrollEvent& event);

private:
	OSLiteConfig *Config;
	ComFunc F;
	int *Scale;
	wxWindow* Handle;
};

#endif
