///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGSETANALYSISOPINTIONBASE_H__
#define __DIALOGSETANALYSISOPINTIONBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DialogSetAnalysisOpintionBase
///////////////////////////////////////////////////////////////////////////////
class DialogSetAnalysisOpintionBase : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* RtMonitorCheckBox;
		wxStaticText* StaticText;
		wxTextCtrl* PortText;
		wxStaticText* m_staticText3;
		wxTextCtrl* HostText;
		wxStaticText* StaticText1;
		wxTextCtrl* ModalNumText;
		wxButton* Cancel;
		wxButton* OK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogSetAnalysisOpintionBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Analysis Opintion..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogSetAnalysisOpintionBase();
	
};

#endif //__DIALOGSETANALYSISOPINTIONBASE_H__
