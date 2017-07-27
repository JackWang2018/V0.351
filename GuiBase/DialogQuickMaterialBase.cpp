///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogQuickMaterialBase.h"

///////////////////////////////////////////////////////////////////////////

DialogQuickMaterialBase::DialogQuickMaterialBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer* fgSizer3;
    fgSizer3 = new wxFlexGridSizer( 2, 1, 0, 0 );
    fgSizer3->SetFlexibleDirection( wxBOTH );
    fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    wxFlexGridSizer* fgSizer2;
    fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer2->SetFlexibleDirection( wxBOTH );
    fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_staticText7 = new wxStaticText( this, wxID_ANY, _( "Type       " ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    fgSizer2->Add( m_staticText7, 0, wxALL, 5 );

    ComboBoxType = new wxComboBox( this, wxID_ComboBoxType, _( "uniaxialMaterial" ), wxDefaultPosition, wxSize( 480, -1 ), 0, NULL, 0 );
    fgSizer2->Add( ComboBoxType, 0, wxALL, 5 );

    m_staticText11 = new wxStaticText( this, wxID_ANY, _( "Material" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText11->Wrap( -1 );
    fgSizer2->Add( m_staticText11, 0, wxALL, 5 );

    ComboBoxMaterial = new wxComboBox( this, wxID_ComboBoxMaterial, wxEmptyString, wxDefaultPosition, wxSize( 480, -1 ), 0, NULL, 0 );
    fgSizer2->Add( ComboBoxMaterial, 0, wxALL, 5 );


    fgSizer3->Add( fgSizer2, 1, wxEXPAND, 5 );

    m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    fgSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

    FormatView = new wxStyledTextCtrl( this, wxID_FormatView, wxDefaultPosition, wxSize( -1, 400 ), wxNO_BORDER, wxEmptyString );
    FormatView->SetUseTabs( true );
    FormatView->SetTabWidth( 4 );
    FormatView->SetIndent( 4 );
    FormatView->SetTabIndents( true );
    FormatView->SetBackSpaceUnIndents( true );
    FormatView->SetViewEOL( false );
    FormatView->SetViewWhiteSpace( false );
    FormatView->SetMarginWidth( 2, 0 );
    FormatView->SetIndentationGuides( true );
    FormatView->SetMarginWidth( 1, 0 );
    FormatView->SetMarginWidth( 0, 0 );
    {
        wxFont font = wxFont( 11, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT( "Consolas" ) );
        FormatView->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
    }
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
    FormatView->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT( "BLACK" ) ) );
    FormatView->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT( "WHITE" ) ) );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
    FormatView->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT( "BLACK" ) ) );
    FormatView->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT( "WHITE" ) ) );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
    FormatView->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT( "BLACK" ) ) );
    FormatView->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT( "WHITE" ) ) );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
    FormatView->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT( "BLACK" ) ) );
    FormatView->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT( "WHITE" ) ) );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
    FormatView->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
    FormatView->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
    FormatView->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
    FormatView->SetFont( wxFont( 11, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT( "Consolas" ) ) );

    fgSizer3->Add( FormatView, 1, wxEXPAND | wxALL, 5 );

    m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    fgSizer3->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );

    wxFlexGridSizer* fgSizer21;
    fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer21->SetFlexibleDirection( wxBOTH );
    fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_staticText71 = new wxStaticText( this, wxID_ANY, _( "Input       " ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText71->Wrap( -1 );
    fgSizer21->Add( m_staticText71, 0, wxALL, 5 );

    m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 480, -1 ), 0 );
    fgSizer21->Add( m_textCtrl2, 0, wxALL, 5 );


    fgSizer3->Add( fgSizer21, 1, wxEXPAND, 5 );

    DialogQuickMaterialInput = new wxStaticLine( this, wxID_DialogQuickMaterialInput, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    fgSizer3->Add( DialogQuickMaterialInput, 0, wxEXPAND | wxALL, 5 );

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxHORIZONTAL );

    DialogQuickMaterialCancel = new wxButton( this, wxID_DialogQuickMaterialCancel, _( "Cancel" ), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer7->Add( DialogQuickMaterialCancel, 0, wxALL, 5 );

    DialogQuickMaterialOK = new wxButton( this, wxID_DialogQuickMaterialOK, _( "OK" ), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer7->Add( DialogQuickMaterialOK, 0, wxALL, 5 );


    fgSizer3->Add( bSizer7, 1, wxALIGN_CENTER, 5 );


    bSizer6->Add( fgSizer3, 1, wxEXPAND, 5 );


    this->SetSizer( bSizer6 );
    this->Layout();
    bSizer6->Fit( this );

    this->Centre( wxBOTH );

    // Connect Events
    ComboBoxType->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DialogQuickMaterialBase::MatTypeComboxValueChange ), NULL, this );
}

DialogQuickMaterialBase::~DialogQuickMaterialBase()
{
    // Disconnect Events
    ComboBoxType->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( DialogQuickMaterialBase::MatTypeComboxValueChange ), NULL, this );

}
