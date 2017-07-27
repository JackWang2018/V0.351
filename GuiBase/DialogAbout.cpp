///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogAbout.h"

#include "../Icon/Logo.xpm"

///////////////////////////////////////////////////////////////////////////

DialogAbout::DialogAbout( wxWindow* parent, wxString Version, wxString ReleaseDate, wxString Author, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer* fgSizer17;
    fgSizer17 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer17->SetFlexibleDirection( wxBOTH );
    fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( Logo_xpm ), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer17->Add( m_bitmap1, 0, wxALL, 5 );

    wxFlexGridSizer* fgSizer19;
    fgSizer19 = new wxFlexGridSizer( 2, 0, 0, 0 );
    fgSizer19->SetFlexibleDirection( wxBOTH );
    fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    m_staticText9 = new wxStaticText( this, wxID_ANY, _( "OSLite" ), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText9->Wrap( -1 );
    m_staticText9->SetFont( wxFont( 26, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT( "Consolas" ) ) );

    fgSizer19->Add( m_staticText9, 0, wxALIGN_CENTER | wxALL, 5 );

    wxFlexGridSizer* fgSizer3;
    fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer3->SetFlexibleDirection( wxBOTH );
    fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxVERTICAL );

    m_staticText20 = new wxStaticText( this, wxID_ANY, _( "Version:" ), wxDefaultPosition, wxSize( -1, 25 ), 0 );
    m_staticText20->Wrap( -1 );
    bSizer8->Add( m_staticText20, 0, wxALIGN_RIGHT | wxALL, 5 );

    m_staticText22 = new wxStaticText( this, wxID_ANY, _( "Date:" ), wxDefaultPosition, wxSize( -1, 25 ), 0 );
    m_staticText22->Wrap( -1 );
    bSizer8->Add( m_staticText22, 0, wxALIGN_RIGHT | wxALL, 5 );

    m_staticText24 = new wxStaticText( this, wxID_ANY, _( "Developer:" ), wxDefaultPosition, wxSize( -1, 25 ), 0 );
    m_staticText24->Wrap( -1 );
    bSizer8->Add( m_staticText24, 0, wxALIGN_RIGHT | wxALL, 5 );

    m_staticText26 = new wxStaticText( this, wxID_ANY, _( "Web-site:" ), wxDefaultPosition, wxSize( -1, 25 ), 0 );
    m_staticText26->Wrap( -1 );
    bSizer8->Add( m_staticText26, 0, wxALIGN_RIGHT | wxALL, 5 );

    m_staticText28 = new wxStaticText( this, wxID_ANY, _( "E-mail:" ), wxDefaultPosition, wxSize( -1, 25 ), 0 );
    m_staticText28->Wrap( -1 );
    bSizer8->Add( m_staticText28, 0, wxALIGN_RIGHT | wxALL, 5 );


    fgSizer3->Add( bSizer8, 1, wxEXPAND, 5 );

    wxBoxSizer* SizerInfo;
    SizerInfo = new wxBoxSizer( wxVERTICAL );

    VersionStaticText = new wxStaticText( this, wxID_ANY, Version, wxDefaultPosition, wxSize( -1, 25 ), 0 );
    VersionStaticText->Wrap( -1 );
    SizerInfo->Add( VersionStaticText, 0, wxALIGN_LEFT | wxALL, 5 );

    DateStaticText = new wxStaticText( this, wxID_ANY, ReleaseDate, wxDefaultPosition, wxSize( -1, 25 ), 0 );
    DateStaticText->Wrap( -1 );
    SizerInfo->Add( DateStaticText, 0, wxALIGN_LEFT | wxALL, 5 );

    AuthorSaticText = new wxStaticText( this, wxID_ANY, Author, wxDefaultPosition, wxSize( -1, 25 ), 0 );
    AuthorSaticText->Wrap( -1 );
    SizerInfo->Add( AuthorSaticText, 0, wxALIGN_LEFT | wxALL, 5 );

    SiteHyperlink = new wxHyperlinkCtrl( this, wxID_ANY, _( "http://blog.whchen.net" ), wxT( "http://whchen.net/blog/index.php/oslite" ), wxDefaultPosition, wxSize( -1, 25 ), wxHL_DEFAULT_STYLE );
    SizerInfo->Add( SiteHyperlink, 0, wxALL, 5 );

    MailHyperlink = new wxHyperlinkCtrl( this, wxID_ANY, _( "Jacques.Chen@qq.com" ), wxT( "mailto://Jacques.Chen@qq.com" ), wxDefaultPosition, wxSize( -1, 25 ), wxHL_DEFAULT_STYLE );
    SizerInfo->Add( MailHyperlink, 0, wxALL, 5 );


    fgSizer3->Add( SizerInfo, 1, wxEXPAND, 5 );


    fgSizer19->Add( fgSizer3, 1, wxEXPAND, 5 );


    fgSizer17->Add( fgSizer19, 1, wxEXPAND, 5 );


    bSizer7->Add( fgSizer17, 1, wxEXPAND, 5 );


    this->SetSizer( bSizer7 );
    this->Layout();
    bSizer7->Fit( this );

    this->Centre( wxBOTH );
}

DialogAbout::~DialogAbout()
{
}
