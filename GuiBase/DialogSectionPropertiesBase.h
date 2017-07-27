///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGSECTIONPROPERTIESBASE_H__
#define __DIALOGSECTIONPROPERTIESBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_DialogModelerWizard 1000
#define wxID_ButtonBlank 1001
#define wxID_ButtonBeam 1002
#define wxID_Button2DTrusses 1003
#define wxID_Button3DTrusses 1004

///////////////////////////////////////////////////////////////////////////////
/// Class DialogSectionPropertiesBase
///////////////////////////////////////////////////////////////////////////////
class DialogSectionPropertiesBase : public wxDialog
{
private:

protected:
    wxBitmapButton* ButtonBlank;
    wxStaticText* m_staticText1;
    wxBitmapButton* ButtonBeam;
    wxStaticText* m_staticText2;
    wxBitmapButton* Button2DTrusses;
    wxStaticText* m_staticText3;
    wxBitmapButton* Button3DTrusses;
    wxStaticText* m_staticText7;

    // Virtual event handlers, overide them in your derived class
    virtual void OnBlankClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    virtual void OnBeamClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    virtual void On2DTrussesClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    virtual void On3DTrussesClick( wxCommandEvent& event )
    {
        event.Skip();
    }


public:

    DialogSectionPropertiesBase( wxWindow* parent, wxWindowID id = wxID_DialogModelerWizard, const wxString& title = _( "Section Properties" ), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
    ~DialogSectionPropertiesBase();

};

#endif //__DIALOGSECTIONPROPERTIESBASE_H__
