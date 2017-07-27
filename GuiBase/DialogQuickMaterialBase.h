///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGQUICKMATERIALBASE_H__
#define __DIALOGQUICKMATERIALBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stc/stc.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_ComboBoxType 1000
#define wxID_ComboBoxMaterial 1001
#define wxID_FormatView 1002
#define wxID_DialogQuickMaterialInput 1003
#define wxID_DialogQuickMaterialCancel 1004
#define wxID_DialogQuickMaterialOK 1005

///////////////////////////////////////////////////////////////////////////////
/// Class DialogQuickMaterialBase
///////////////////////////////////////////////////////////////////////////////
class DialogQuickMaterialBase : public wxDialog
{
private:

protected:
    wxStaticText* m_staticText7;
    wxComboBox* ComboBoxType;
    wxStaticText* m_staticText11;
    wxComboBox* ComboBoxMaterial;
    wxStaticLine* m_staticline1;
    wxStyledTextCtrl* FormatView;
    wxStaticLine* m_staticline11;
    wxStaticText* m_staticText71;
    wxTextCtrl* m_textCtrl2;
    wxStaticLine* DialogQuickMaterialInput;
    wxButton* DialogQuickMaterialCancel;
    wxButton* DialogQuickMaterialOK;

    // Virtual event handlers, overide them in your derived class
    virtual void MatTypeComboxValueChange( wxCommandEvent& event )
    {
        event.Skip();
    }


public:

    DialogQuickMaterialBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _( "Quick Material Definition" ), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1, -1 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~DialogQuickMaterialBase();

};

#endif //__DIALOGQUICKMATERIALBASE_H__
