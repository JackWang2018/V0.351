///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGREALTIMEMONITORDEFORMBASE_H__
#define __DIALOGREALTIMEMONITORDEFORMBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_ScaleSlider 1000

///////////////////////////////////////////////////////////////////////////////
/// Class DialogRealTimeMonitorDeformBase
///////////////////////////////////////////////////////////////////////////////
class DialogRealTimeMonitorDeformBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxSlider* ScaleSlider;
		wxTextCtrl* ScaleText;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseDialog( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnChanged( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogRealTimeMonitorDeformBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Real Time Monitor Deform"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogRealTimeMonitorDeformBase();
	
};

#endif //__DIALOGREALTIMEMONITORDEFORMBASE_H__
