// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogRealTimeMonitorDeform.h"



DialogRealTimeMonitorDeform::DialogRealTimeMonitorDeform(wxWindow* HandleIn, int PortIn, wxString IPIn, int *ScaleIn) : DialogRealTimeMonitorDeformBase(HandleIn)
{
	Scale = ScaleIn;
	Handle = HandleIn;

	ScaleSlider->SetValue(*Scale);
	ScaleText->SetValue(wxString::wxString(F.ToString(ScaleSlider->GetValue())));
}

DialogRealTimeMonitorDeform::~DialogRealTimeMonitorDeform()
{
}

 void DialogRealTimeMonitorDeform::OnCloseDialog(wxCloseEvent& event)
{
	wxCommandEvent Evt(wxEVT_SET_STATE);
	Evt.SetString("RealTimeMonitorDeformDialog");
	Handle->GetEventHandler()->AddPendingEvent(Evt);
}

void DialogRealTimeMonitorDeform::OnChanged(wxScrollEvent& event)
{
	ScaleText->SetValue(wxString::wxString(F.ToString(ScaleSlider->GetValue())));
	(*Scale) = F.StrToInt((ScaleText->GetValue()).ToStdString());
}