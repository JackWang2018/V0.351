///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DIALOGIMPORTDXFBASE_H__
#define __DIALOGIMPORTDXFBASE_H__

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
#include <wx/combobox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_DxfFilePathInputTextCtrl 1000
#define wxID_DialogImportDxfOpen 1001
#define wxID_JointLayerComboBox 1002
#define wxID_FrameLayerComboBox 1003
#define wxID_NLLinkLayerComboBox 1004
#define wxID_ShellLayerComboBox 1005
#define wxID_SolidLayerComboBox 1006
#define wxID_DialogImportDxfCancel 1007
#define wxID_DialogImportDxfOK 1008

///////////////////////////////////////////////////////////////////////////////
/// Class DialogImportDxfBase
///////////////////////////////////////////////////////////////////////////////
class DialogImportDxfBase : public wxDialog 
{
	private:
	
	protected:
		wxTextCtrl* DxfFilePathInputTextCtrl;
		wxButton* DialogImportDxfOpen;
		wxStaticText* m_staticText14;
		wxComboBox* JointLayerComboBox;
		wxComboBox* JointTypeComboBox;
		wxStaticText* m_staticText15;
		wxComboBox* LineLayerComboBox;
		wxComboBox* LineTypeComboBox;
		wxStaticText* m_staticText16;
		wxComboBox* NLLinkLayerComboBox;
		wxComboBox* NLLinkTypeComboBox;
		wxStaticText* m_staticText17;
		wxComboBox* ShellLayerComboBox;
		wxComboBox* ShellTypeComboBox;
		wxStaticText* m_staticText18;
		wxComboBox* SolidLayerComboBox;
		wxComboBox* SolidTypeComboBox;
		wxButton* DialogImportDxfCancel;
		wxButton* DialogImportDxfOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOpenClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOKClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogImportDxfBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Import Information"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogImportDxfBase();
	
};

#endif //__DIALOGIMPORTDXFBASE_H__
