///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogSectionPropertiesBase.h"

#include "../Icon/DefineSectionCir.xpm"
#include "../Icon/DefineSectionI.xpm"
#include "../Icon/DefineSectionRec.xpm"
#include "../Icon/DefineSectionT.xpm"

///////////////////////////////////////////////////////////////////////////

DialogSectionPropertiesBase::DialogSectionPropertiesBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer* fgSizer1;
    fgSizer1 = new wxFlexGridSizer( 4, 4, 0, 0 );
    fgSizer1->SetFlexibleDirection( wxBOTH );
    fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    wxFlexGridSizer* fgSizer5;
    fgSizer5 = new wxFlexGridSizer( 2, 1, 0, 0 );
    fgSizer5->SetFlexibleDirection( wxBOTH );
    fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    ButtonBlank = new wxBitmapButton( this, wxID_ButtonBlank, wxBitmap( DefineSectionRec_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    fgSizer5->Add( ButtonBlank, 0, wxALL, 5 );

    m_staticText1 = new wxStaticText( this, wxID_ANY, _( "Rectangular" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText1->Wrap( -1 );
    fgSizer5->Add( m_staticText1, 0, wxALIGN_CENTER | wxALL, 5 );


    fgSizer1->Add( fgSizer5, 1, wxEXPAND, 5 );

    wxFlexGridSizer* fgSizer6;
    fgSizer6 = new wxFlexGridSizer( 2, 1, 0, 0 );
    fgSizer6->SetFlexibleDirection( wxBOTH );
    fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    ButtonBeam = new wxBitmapButton( this, wxID_ButtonBeam, wxBitmap( DefineSectionCir_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    fgSizer6->Add( ButtonBeam, 0, wxALL, 5 );

    m_staticText2 = new wxStaticText( this, wxID_ANY, _( "Circular" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText2->Wrap( -1 );
    fgSizer6->Add( m_staticText2, 0, wxALIGN_CENTER | wxALL, 5 );


    fgSizer1->Add( fgSizer6, 1, wxEXPAND, 5 );

    wxFlexGridSizer* fgSizer61;
    fgSizer61 = new wxFlexGridSizer( 2, 1, 0, 0 );
    fgSizer61->SetFlexibleDirection( wxBOTH );
    fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    Button2DTrusses = new wxBitmapButton( this, wxID_Button2DTrusses, wxBitmap( DefineSectionI_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    fgSizer61->Add( Button2DTrusses, 0, wxALL, 5 );

    m_staticText3 = new wxStaticText( this, wxID_ANY, _( "I/Wide Flange" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText3->Wrap( -1 );
    fgSizer61->Add( m_staticText3, 0, wxALIGN_CENTER | wxALL, 5 );


    fgSizer1->Add( fgSizer61, 1, wxEXPAND, 5 );

    wxFlexGridSizer* fgSizer62;
    fgSizer62 = new wxFlexGridSizer( 2, 1, 0, 0 );
    fgSizer62->SetFlexibleDirection( wxBOTH );
    fgSizer62->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    Button3DTrusses = new wxBitmapButton( this, wxID_Button3DTrusses, wxBitmap( DefineSectionT_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
    fgSizer62->Add( Button3DTrusses, 0, wxALL, 5 );

    m_staticText7 = new wxStaticText( this, wxID_ANY, _( "Tee" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    fgSizer62->Add( m_staticText7, 0, wxALIGN_CENTER | wxALL, 5 );


    fgSizer1->Add( fgSizer62, 1, wxEXPAND, 5 );


    bSizer5->Add( fgSizer1, 1, wxALIGN_CENTER, 5 );


    this->SetSizer( bSizer5 );
    this->Layout();
    bSizer5->Fit( this );

    this->Centre( wxBOTH );

    // Connect Events
    ButtonBlank->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::OnBlankClick ), NULL, this );
    ButtonBeam->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::OnBeamClick ), NULL, this );
    Button2DTrusses->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::On2DTrussesClick ), NULL, this );
    Button3DTrusses->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::On3DTrussesClick ), NULL, this );
}

DialogSectionPropertiesBase::~DialogSectionPropertiesBase()
{
    // Disconnect Events
    ButtonBlank->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::OnBlankClick ), NULL, this );
    ButtonBeam->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::OnBeamClick ), NULL, this );
    Button2DTrusses->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::On2DTrussesClick ), NULL, this );
    Button3DTrusses->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSectionPropertiesBase::On3DTrussesClick ), NULL, this );

}
