///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGABOUT_H__
#define __DIALOGABOUT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/hyperlink.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class DialogAbout
///////////////////////////////////////////////////////////////////////////////
class DialogAbout : public wxDialog
{
private:

protected:
    wxStaticBitmap* m_bitmap1;
    wxStaticText* m_staticText9;
    wxStaticText* m_staticText20;
    wxStaticText* m_staticText22;
    wxStaticText* m_staticText24;
    wxStaticText* m_staticText26;
    wxStaticText* m_staticText28;
    wxStaticText* VersionStaticText;
    wxStaticText* DateStaticText;
    wxStaticText* AuthorSaticText;
    wxHyperlinkCtrl* SiteHyperlink;
    wxHyperlinkCtrl* MailHyperlink;

public:

    DialogAbout( wxWindow* parent, wxString Version, wxString ReleaseDate, wxString Author, wxWindowID id = wxID_ANY, const wxString& title = _( "About OSLite" ), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
    ~DialogAbout();

};

#endif //__DIALOGABOUT_H__
