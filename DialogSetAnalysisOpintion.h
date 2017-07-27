// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __DialogSetAnalysisOpintion__
#define __DialogSetAnalysisOpintion__

#include <wx/wx.h>
#include "GuiBase/DialogSetAnalysisOpintionBase.h"
#include "OSLiteConfig.h"
#include "ComFunc.h"

class DialogSetAnalysisOpintion : public DialogSetAnalysisOpintionBase
{
public:
	DialogSetAnalysisOpintion(wxWindow* Parent, int  *MonitorPort, wxString *MonitorHost,bool *RtMonitorIn,int *NumModesIn);
	~DialogSetAnalysisOpintion();
	void OnOKClick(wxCommandEvent& event);
	void OnCancelClick(wxCommandEvent& event);

private:
	OSLiteConfig *Config;
	ComFunc F;
	int  *MonitorPort;
	wxString *MonitorHost;
	bool *RtMonitor;
	int *NumModes;
};

#endif
