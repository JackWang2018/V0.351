///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogModelerWizardBase.h"

#include "../Icon/ModelerWizardBeam.xpm"
#include "../Icon/ModelerWizardBlank.xpm"
#include "../Icon/ModelerWizardFrames2D.xpm"
#include "../Icon/ModelerWizardFrames3D.xpm"
#include "../Icon/ModelerWizardPushover.xpm"
#include "../Icon/ModelerWizardTrusses2D.xpm"
#include "../Icon/ModelerWizardTrusses3D.xpm"

///////////////////////////////////////////////////////////////////////////

DialogModelerWizardBase::DialogModelerWizardBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 4, 5, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ButtonBlank = new wxBitmapButton( this, wxID_ButtonBlank, wxBitmap( ModelerWizardBlank_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer5->Add( ButtonBlank, 0, wxALL, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Blank"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer5->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ButtonBeam = new wxBitmapButton( this, wxID_ButtonBeam, wxBitmap( ModelerWizardBeam_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer6->Add( ButtonBeam, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Beam"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer6->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button2DTrusses = new wxBitmapButton( this, wxID_Button2DTrusses, wxBitmap( ModelerWizardTrusses2D_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer61->Add( Button2DTrusses, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("2D Trusses"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer61->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer61, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer62;
	fgSizer62 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer62->SetFlexibleDirection( wxBOTH );
	fgSizer62->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button3DTrusses = new wxBitmapButton( this, wxID_Button3DTrusses, wxBitmap( ModelerWizardTrusses3D_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer62->Add( Button3DTrusses, 0, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, _("3D Trusses"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer62->Add( m_staticText7, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer62, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer63;
	fgSizer63 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer63->SetFlexibleDirection( wxBOTH );
	fgSizer63->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button2DFrames = new wxBitmapButton( this, wxID_Button2DFrames, wxBitmap( ModelerWizardFrames2D_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer63->Add( Button2DFrames, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("2D Frames"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer63->Add( m_staticText8, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer63, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer64;
	fgSizer64 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer64->SetFlexibleDirection( wxBOTH );
	fgSizer64->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button3DFrames = new wxBitmapButton( this, wxID_Button3DFrames, wxBitmap( ModelerWizardFrames3D_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer64->Add( Button3DFrames, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("3D Frames"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer64->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer64, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer65;
	fgSizer65 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer65->SetFlexibleDirection( wxBOTH );
	fgSizer65->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ButtonPushover = new wxBitmapButton( this, wxID_ButtonPushover, wxBitmap( ModelerWizardPushover_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer65->Add( ButtonPushover, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Pushover"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer65->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer65, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button8 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer22->Add( Button8, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer22->Add( m_staticText12, 0, wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer22, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button9 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer23->Add( Button9, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer23->Add( m_staticText13, 0, wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer23, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	Button10 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	fgSizer24->Add( Button10, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	fgSizer24->Add( m_staticText14, 0, wxALL, 5 );
	
	
	fgSizer1->Add( fgSizer24, 1, wxEXPAND, 5 );
	
	
	bSizer5->Add( fgSizer1, 1, wxALIGN_CENTER, 5 );
	
	
	this->SetSizer( bSizer5 );
	this->Layout();
	bSizer5->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	ButtonBlank->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnBlankClick ), NULL, this );
	ButtonBeam->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnBeamClick ), NULL, this );
	Button2DTrusses->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On2DTrussesClick ), NULL, this );
	Button3DTrusses->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On3DTrussesClick ), NULL, this );
	Button2DFrames->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On2DFramesClick ), NULL, this );
	Button3DFrames->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On3DFramesClick ), NULL, this );
	ButtonPushover->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnPushoverClick ), NULL, this );
}

DialogModelerWizardBase::~DialogModelerWizardBase()
{
	// Disconnect Events
	ButtonBlank->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnBlankClick ), NULL, this );
	ButtonBeam->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnBeamClick ), NULL, this );
	Button2DTrusses->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On2DTrussesClick ), NULL, this );
	Button3DTrusses->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On3DTrussesClick ), NULL, this );
	Button2DFrames->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On2DFramesClick ), NULL, this );
	Button3DFrames->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::On3DFramesClick ), NULL, this );
	ButtonPushover->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogModelerWizardBase::OnPushoverClick ), NULL, this );
	
}
