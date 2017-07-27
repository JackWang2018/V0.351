#ifndef __DefineUserEvent__
#define __DefineUserEvent__

#include <wx/wx.h>

// define user event
wxDEFINE_EVENT(wxEVT_THREAD_RUN, wxThreadEvent);
wxDEFINE_EVENT(wxEVT_RT_MONITOR_DEFORM_THREAD, wxThreadEvent);
wxDEFINE_EVENT(wxEVT_DISPLAY_DEFORM, wxCommandEvent);
wxDEFINE_EVENT(wxEVT_SET_STATE, wxCommandEvent);


#endif