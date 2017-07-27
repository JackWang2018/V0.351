///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGCOLORSANDFONTSBASE_H__
#define __DIALOGCOLORSANDFONTSBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/clrpicker.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/fontpicker.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_DialogColorCancel 1000
#define wxID_DialogOKCancel 1001

///////////////////////////////////////////////////////////////////////////////
/// Class DialogColorsAndFontsBase
///////////////////////////////////////////////////////////////////////////////
class DialogColorsAndFontsBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText32;
		wxColourPickerCtrl* BgColorPicker;
		wxStaticText* m_staticText321;
		wxColourPickerCtrl* PointColorPicker;
		wxStaticText* m_staticText33;
		wxColourPickerCtrl* LineColorPicker;
		wxStaticText* m_staticText72;
		wxColourPickerCtrl* ShellColorPicker;
		wxStaticText* m_staticText721;
		wxColourPickerCtrl* SolidColorPicker;
		wxStaticText* m_staticText7211;
		wxColourPickerCtrl* OtherColorPicker;
		wxStaticText* m_staticText30;
		wxColourPickerCtrl* LinkColorPicker;
		wxStaticText* m_staticText3011;
		wxColourPickerCtrl* MpColorPicker;
		wxStaticText* m_staticText301;
		wxColourPickerCtrl* TextColorPicker;
		wxStaticText* m_staticText3012;
		wxColourPickerCtrl* EdgeColorPicker;
		wxStaticText* TransparencyStaticTextPoint;
		wxTextCtrl* PointTransTextCtrl;
		wxStaticText* TransparencyStaticText1D;
		wxTextCtrl* LineTransTextCtrl;
		wxStaticText* TransparencyStaticText2D;
		wxTextCtrl* ShellTransTextCtrl;
		wxStaticText* TransparencyStaticText3D;
		wxTextCtrl* SolidTransTextCtrl;
		wxStaticText* TransparencyStaticTextOther;
		wxTextCtrl* OtherTransTextCtrl;
		wxStaticText* m_staticText6;
		wxFontPickerCtrl* CodeFontPicker;
		wxStaticText* m_staticText7;
		wxFontPickerCtrl* ModelFontPicker;
		wxStaticText* m_staticText71;
		wxFontPickerCtrl* OutputFontPicker;
		wxStaticText* LineWidthStaticText;
		wxTextCtrl* LineWidthTextCtrl;
		wxStaticText* PointSizeStaticText;
		wxTextCtrl* PointSizeTextCtrl;
		wxButton* DialogColorCancel;
		wxButton* DialogOKCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogColorsAndFontsBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Colors and fonts"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogColorsAndFontsBase();
	
};

#endif //__DIALOGCOLORSANDFONTSBASE_H__
