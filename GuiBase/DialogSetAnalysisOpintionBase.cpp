///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogSetAnalysisOpintionBase.h"

///////////////////////////////////////////////////////////////////////////

DialogSetAnalysisOpintionBase::DialogSetAnalysisOpintionBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Real Time Monitor Deform") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	RtMonitorCheckBox = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Display"), wxDefaultPosition, wxDefaultSize, 0 );
	RtMonitorCheckBox->SetValue(true); 
	fgSizer51->Add( RtMonitorCheckBox, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer51, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	StaticText = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticText->Wrap( -1 );
	fgSizer6->Add( StaticText, 0, wxALL|wxEXPAND, 5 );
	
	PortText = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, _("8099"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer6->Add( PortText, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer6, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText3 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, _("Host"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer5->Add( m_staticText3, 0, wxALL|wxEXPAND, 5 );
	
	HostText = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, _("127.0.0.1"), wxDefaultPosition, wxSize( 160,-1 ), 0 );
	fgSizer5->Add( HostText, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer4->Add( fgSizer5, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizer1->Add( fgSizer4, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Modal Analysis") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	StaticText1 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Modal Number"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticText1->Wrap( -1 );
	fgSizer61->Add( StaticText1, 0, wxALL|wxEXPAND, 5 );
	
	ModalNumText = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, _("0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer61->Add( ModalNumText, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer2->Add( fgSizer61, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 1, 2, 0, 0 );
	
	Cancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( Cancel, 0, wxALL|wxEXPAND, 5 );
	
	OK = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( OK, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( gSizer2, 1, wxALIGN_CENTER, 5 );
	
	
	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSetAnalysisOpintionBase::OnCancelClick ), NULL, this );
	OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSetAnalysisOpintionBase::OnOKClick ), NULL, this );
}

DialogSetAnalysisOpintionBase::~DialogSetAnalysisOpintionBase()
{
	// Disconnect Events
	Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSetAnalysisOpintionBase::OnCancelClick ), NULL, this );
	OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogSetAnalysisOpintionBase::OnOKClick ), NULL, this );
	
}
