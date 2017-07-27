// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogSetAnalysisOpintion.h"

DialogSetAnalysisOpintion::DialogSetAnalysisOpintion(wxWindow* Parent, int  *MonitorPortIn, wxString *MonitorHostIn, bool *RtMonitorIn, int *NumModesIn)
	: DialogSetAnalysisOpintionBase(Parent)
{
	MonitorPort = MonitorPortIn;
	MonitorHost = MonitorHostIn;
	RtMonitor = RtMonitorIn;
	NumModes = NumModesIn;

	PortText->SetValue(wxString::wxString(F.ToString(*MonitorPort)));
	HostText->SetValue(wxString::wxString(*MonitorHost));
	RtMonitorCheckBox->SetValue(*RtMonitor);
	ModalNumText->SetValue(wxString::wxString(F.ToString(*NumModes)));
}

DialogSetAnalysisOpintion::~DialogSetAnalysisOpintion()
{
}

void DialogSetAnalysisOpintion::OnOKClick(wxCommandEvent& event)
{
	(*MonitorPort) = F.StrToInt((PortText->GetValue()).ToStdString());
	(*MonitorHost) = HostText->GetValue();
	(*RtMonitor) = RtMonitorCheckBox->GetValue();
	(*NumModes) = F.StrToInt(ModalNumText->GetValue().ToStdString());

	OSLiteConfig *Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	Config->SetValue("RealTimeMonitor", (*RtMonitor) ? "1" : "0");
	Config->SetValue("Host", wxT("") + *MonitorHost);
	Config->SetValue("Port", wxT("") + F.ToString(*MonitorPort));
	Config->SaveConfig();

	EndModal(wxID_OK);
}

void DialogSetAnalysisOpintion::OnCancelClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}