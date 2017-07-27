///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogColorsAndFontsBase.h"

///////////////////////////////////////////////////////////////////////////

DialogColorsAndFontsBase::DialogColorsAndFontsBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 1, 3, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Color") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 10, 2, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText32 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Background"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer7->Add( m_staticText32, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	BgColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( BgColorPicker, 0, wxALL, 5 );
	
	m_staticText321 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText321->Wrap( -1 );
	fgSizer7->Add( m_staticText321, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	PointColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( PointColorPicker, 0, wxALL, 5 );
	
	m_staticText33 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Line Element"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer7->Add( m_staticText33, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	LineColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 0, 0, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( LineColorPicker, 0, wxALL, 5 );
	
	m_staticText72 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Shell Element"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	fgSizer7->Add( m_staticText72, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	ShellColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 255, 0, 128 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( ShellColorPicker, 0, wxALL, 5 );
	
	m_staticText721 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Solid Element"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText721->Wrap( -1 );
	fgSizer7->Add( m_staticText721, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	SolidColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( SolidColorPicker, 0, wxALL, 5 );
	
	m_staticText7211 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("MasonPan Element"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7211->Wrap( -1 );
	fgSizer7->Add( m_staticText7211, 0, wxALL, 5 );
	
	OtherColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 255, 255, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( OtherColorPicker, 0, wxALL, 5 );
	
	m_staticText30 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Link Element"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer7->Add( m_staticText30, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	LinkColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 128, 255, 128 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( LinkColorPicker, 0, wxALL, 5 );
	
	m_staticText3011 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("MP Constraint"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3011->Wrap( -1 );
	fgSizer7->Add( m_staticText3011, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	MpColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 0, 255, 64 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( MpColorPicker, 0, wxALL, 5 );
	
	m_staticText301 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Model Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText301->Wrap( -1 );
	fgSizer7->Add( m_staticText301, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	TextColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 128, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( TextColorPicker, 0, wxALL, 5 );
	
	m_staticText3012 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Edge"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3012->Wrap( -1 );
	fgSizer7->Add( m_staticText3012, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	EdgeColorPicker = new wxColourPickerCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxColour( 0, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer7->Add( EdgeColorPicker, 0, wxALL, 5 );
	
	
	sbSizer8->Add( fgSizer7, 1, wxEXPAND, 5 );
	
	
	fgSizer8->Add( sbSizer8, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer23->Add( fgSizer8, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Transparency") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer511;
	fgSizer511 = new wxFlexGridSizer( 5, 2, 0, 0 );
	fgSizer511->SetFlexibleDirection( wxBOTH );
	fgSizer511->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	TransparencyStaticTextPoint = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Point"), wxDefaultPosition, wxDefaultSize, 0 );
	TransparencyStaticTextPoint->Wrap( -1 );
	fgSizer511->Add( TransparencyStaticTextPoint, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	PointTransTextCtrl = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, _("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer511->Add( PointTransTextCtrl, 0, wxALL, 5 );
	
	TransparencyStaticText1D = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Line Element"), wxDefaultPosition, wxDefaultSize, 0 );
	TransparencyStaticText1D->Wrap( -1 );
	fgSizer511->Add( TransparencyStaticText1D, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	LineTransTextCtrl = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, _("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer511->Add( LineTransTextCtrl, 0, wxALL, 5 );
	
	TransparencyStaticText2D = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Shell Element"), wxDefaultPosition, wxDefaultSize, 0 );
	TransparencyStaticText2D->Wrap( -1 );
	fgSizer511->Add( TransparencyStaticText2D, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	ShellTransTextCtrl = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, _("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer511->Add( ShellTransTextCtrl, 0, wxALL, 5 );
	
	TransparencyStaticText3D = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Solid Element"), wxDefaultPosition, wxDefaultSize, 0 );
	TransparencyStaticText3D->Wrap( -1 );
	fgSizer511->Add( TransparencyStaticText3D, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	SolidTransTextCtrl = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer511->Add( SolidTransTextCtrl, 0, wxALL, 5 );
	
	TransparencyStaticTextOther = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("MasonPan Element"), wxDefaultPosition, wxDefaultSize, 0 );
	TransparencyStaticTextOther->Wrap( -1 );
	fgSizer511->Add( TransparencyStaticTextOther, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	OtherTransTextCtrl = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer511->Add( OtherTransTextCtrl, 0, wxALL, 5 );
	
	
	sbSizer4->Add( fgSizer511, 1, wxEXPAND, 5 );
	
	
	fgSizer6->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer23->Add( fgSizer6, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 2, 1, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Fonts") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 3, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, _("Code Font"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer5->Add( m_staticText6, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	CodeFontPicker = new wxFontPickerCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	CodeFontPicker->SetMaxPointSize( 100 ); 
	fgSizer5->Add( CodeFontPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText7 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, _("Model Font"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer5->Add( m_staticText7, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	ModelFontPicker = new wxFontPickerCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	ModelFontPicker->SetMaxPointSize( 100 ); 
	fgSizer5->Add( ModelFontPicker, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText71 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, _("Output Font"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	fgSizer5->Add( m_staticText71, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	OutputFontPicker = new wxFontPickerCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL );
	OutputFontPicker->SetMaxPointSize( 100 ); 
	fgSizer5->Add( OutputFontPicker, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer3->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	
	fgSizer9->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* Other;
	Other = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Other") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	LineWidthStaticText = new wxStaticText( Other->GetStaticBox(), wxID_ANY, _("Line Width"), wxDefaultPosition, wxDefaultSize, 0 );
	LineWidthStaticText->Wrap( -1 );
	fgSizer51->Add( LineWidthStaticText, 0, wxALL, 5 );
	
	LineWidthTextCtrl = new wxTextCtrl( Other->GetStaticBox(), wxID_ANY, _("3"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer51->Add( LineWidthTextCtrl, 0, wxALL, 5 );
	
	PointSizeStaticText = new wxStaticText( Other->GetStaticBox(), wxID_ANY, _("Point Size"), wxDefaultPosition, wxDefaultSize, 0 );
	PointSizeStaticText->Wrap( -1 );
	fgSizer51->Add( PointSizeStaticText, 0, wxALL, 5 );
	
	PointSizeTextCtrl = new wxTextCtrl( Other->GetStaticBox(), wxID_ANY, _("5"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer51->Add( PointSizeTextCtrl, 0, wxALL, 5 );
	
	
	Other->Add( fgSizer51, 1, wxEXPAND, 5 );
	
	
	fgSizer9->Add( Other, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer23->Add( fgSizer9, 1, wxEXPAND, 5 );
	
	
	fgSizer21->Add( fgSizer23, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	DialogColorCancel = new wxButton( this, wxID_DialogColorCancel, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( DialogColorCancel, 0, wxALL, 5 );
	
	DialogOKCancel = new wxButton( this, wxID_DialogOKCancel, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( DialogOKCancel, 0, wxALL, 5 );
	
	
	fgSizer21->Add( bSizer15, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer12->Add( fgSizer21, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer12 );
	this->Layout();
	bSizer12->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	DialogColorCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogColorsAndFontsBase::OnCancelClick ), NULL, this );
	DialogOKCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogColorsAndFontsBase::OnOKClick ), NULL, this );
}

DialogColorsAndFontsBase::~DialogColorsAndFontsBase()
{
	// Disconnect Events
	DialogColorCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogColorsAndFontsBase::OnCancelClick ), NULL, this );
	DialogOKCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogColorsAndFontsBase::OnOKClick ), NULL, this );
	
}
