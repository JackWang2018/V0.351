#ifndef __DeclareUserEvent__
#define __DeclareUserEvent__

#include <wx/wx.h>

// declare user event
wxDECLARE_EVENT(wxEVT_THREAD_RUN, wxThreadEvent);
wxDECLARE_EVENT(wxEVT_RT_MONITOR_DEFORM_THREAD, wxThreadEvent);
wxDECLARE_EVENT(wxEVT_DISPLAY_DEFORM, wxCommandEvent);
wxDECLARE_EVENT(wxEVT_SET_STATE, wxCommandEvent);


#endif