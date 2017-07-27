///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGCHANGEOPENSEESPATHBASE_H__
#define __DIALOGCHANGEOPENSEESPATHBASE_H__

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
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Open 1000

///////////////////////////////////////////////////////////////////////////////
/// Class DialogChangeOpenSeesPathBase
///////////////////////////////////////////////////////////////////////////////
class DialogChangeOpenSeesPathBase : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* OpenSEESPathCtrl;
		wxButton* Open;
		
		// Virtual event handlers, overide them in your derived class
		virtual void SelectOpenSEES( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogChangeOpenSeesPathBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Change OpenSees.exe Path"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogChangeOpenSeesPathBase();
	
};

#endif //__DIALOGCHANGEOPENSEESPATHBASE_H__
