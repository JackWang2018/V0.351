///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGDONATE_H__
#define __DIALOGDONATE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/hyperlink.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DialogDonate
///////////////////////////////////////////////////////////////////////////////
class DialogDonate : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText31;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText1;
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText3;
		wxStaticBitmap* m_bitmap2;
		wxHyperlinkCtrl* m_hyperlink1;
	
	public:
		
		DialogDonate( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Donate"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogDonate();
	
};

#endif //__DIALOGDONATE_H__
