///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGSHOWDEFORMEDBASE_H__
#define __DIALOGSHOWDEFORMEDBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_ScaleSlider 1000

///////////////////////////////////////////////////////////////////////////////
/// Class DialogShowDeformedBase
///////////////////////////////////////////////////////////////////////////////
class DialogShowDeformedBase : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* PathText;
		wxButton* PathOpen;
		wxStaticText* m_staticText3;
		wxChoice* AnalysisCaseChoice;
		wxStaticText* m_staticText4;
		wxSlider* ScaleSlider;
		wxTextCtrl* ScaleText;
		wxStaticText* m_staticText42;
		wxSlider* SpeedSlider;
		wxTextCtrl* SpeedText;
		wxStaticText* m_staticText41;
		wxSlider* TimeSlider;
		wxTextCtrl* TimeText;
		wxButton* AutoPlay;
		wxButton* Stop;
		wxTimer Timer;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseDialog( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnSelectResualtFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangeCase( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChangedSliderScale( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnChangedTextScale( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnChangedSliderSpeed( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnChangedTextSpeed( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnChangedTime( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAutoPlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogShowDeformedBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Deformed Shape"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogShowDeformedBase();
	
};

#endif //__DIALOGSHOWDEFORMEDBASE_H__
