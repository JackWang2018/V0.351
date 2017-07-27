///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogImportDxfBase.h"

///////////////////////////////////////////////////////////////////////////

DialogImportDxfBase::DialogImportDxfBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 3, 1, 0, 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Input file") ), wxHORIZONTAL );
	
	DxfFilePathInputTextCtrl = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_DxfFilePathInputTextCtrl, wxEmptyString, wxDefaultPosition, wxSize( 420,-1 ), 0 );
	sbSizer1->Add( DxfFilePathInputTextCtrl, 0, wxALL|wxEXPAND, 5 );
	
	DialogImportDxfOpen = new wxButton( sbSizer1->GetStaticBox(), wxID_DialogImportDxfOpen, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( DialogImportDxfOpen, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer17->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Assign Layers") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer15;
	fgSizer15 = new wxFlexGridSizer( 5, 3, 0, 0 );
	fgSizer15->SetFlexibleDirection( wxBOTH );
	fgSizer15->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText14 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Special Joints"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText14->Wrap( -1 );
	fgSizer15->Add( m_staticText14, 0, wxALL, 5 );
	
	JointLayerComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_JointLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( 240,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( JointLayerComboBox, 0, wxALL, 5 );
	
	JointTypeComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_JointLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( JointTypeComboBox, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText15 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Line"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText15->Wrap( -1 );
	fgSizer15->Add( m_staticText15, 0, wxALL, 5 );
	
	LineLayerComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_FrameLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( 240,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( LineLayerComboBox, 0, wxALL, 5 );
	
	LineTypeComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_FrameLayerComboBox, _("elasticBeamColumn"), wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 );
	LineTypeComboBox->Append( _("elasticBeamColumn") );
	LineTypeComboBox->Append( _("nonlinearBeamColumn") );
	LineTypeComboBox->Append( _("beamWithHinges") );
	LineTypeComboBox->Append( _("corotTruss") );
	LineTypeComboBox->Append( _("dispBeamColumn") );
	LineTypeComboBox->Append( _("truss") );
	LineTypeComboBox->Append( _("zeroLength") );
	LineTypeComboBox->Append( _("zeroLengthND") );
	LineTypeComboBox->Append( _("zeroLengthSection") );
	LineTypeComboBox->Append( _("elasticBeamColumn") );
	LineTypeComboBox->Append( wxEmptyString );
	fgSizer15->Add( LineTypeComboBox, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText16 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("NL Links"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText16->Wrap( -1 );
	fgSizer15->Add( m_staticText16, 0, wxALL, 5 );
	
	NLLinkLayerComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_NLLinkLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( 240,-1 ), 0, NULL, 0 ); 
	NLLinkLayerComboBox->Enable( false );
	
	fgSizer15->Add( NLLinkLayerComboBox, 0, wxALL, 5 );
	
	NLLinkTypeComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_NLLinkLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	NLLinkTypeComboBox->Enable( false );
	
	fgSizer15->Add( NLLinkTypeComboBox, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText17 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Shells"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText17->Wrap( -1 );
	fgSizer15->Add( m_staticText17, 0, wxALL, 5 );
	
	ShellLayerComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_ShellLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( 240,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( ShellLayerComboBox, 0, wxALL, 5 );
	
	ShellTypeComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_ShellLayerComboBox, _("ShellMITC4"), wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 );
	ShellTypeComboBox->Append( _("ShellMITC4") );
	ShellTypeComboBox->Append( _("bbarQuad") );
	ShellTypeComboBox->Append( _("enhancedQuad") );
	ShellTypeComboBox->Append( _("quad") );
	fgSizer15->Add( ShellTypeComboBox, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText18 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Solid"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_staticText18->Wrap( -1 );
	fgSizer15->Add( m_staticText18, 0, wxALL, 5 );
	
	SolidLayerComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_SolidLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( 240,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( SolidLayerComboBox, 0, wxALL, 5 );
	
	SolidTypeComboBox = new wxComboBox( sbSizer2->GetStaticBox(), wxID_SolidLayerComboBox, _("NONE"), wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	fgSizer15->Add( SolidTypeComboBox, 0, wxALL|wxEXPAND, 5 );
	
	
	sbSizer2->Add( fgSizer15, 1, wxEXPAND, 5 );
	
	
	fgSizer17->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	DialogImportDxfCancel = new wxButton( this, wxID_DialogImportDxfCancel, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( DialogImportDxfCancel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	DialogImportDxfOK = new wxButton( this, wxID_DialogImportDxfOK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( DialogImportDxfOK, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	fgSizer17->Add( bSizer10, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer8->Add( fgSizer17, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
	bSizer8->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	DialogImportDxfOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnOpenClick ), NULL, this );
	DialogImportDxfCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnCancelClick ), NULL, this );
	DialogImportDxfOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnOKClick ), NULL, this );
}

DialogImportDxfBase::~DialogImportDxfBase()
{
	// Disconnect Events
	DialogImportDxfOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnOpenClick ), NULL, this );
	DialogImportDxfCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnCancelClick ), NULL, this );
	DialogImportDxfOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogImportDxfBase::OnOKClick ), NULL, this );
	
}
