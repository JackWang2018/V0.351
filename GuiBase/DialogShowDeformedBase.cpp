///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogShowDeformedBase.h"

///////////////////////////////////////////////////////////////////////////

DialogShowDeformedBase::DialogShowDeformedBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 5, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Resualt File") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	PathText = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 365,-1 ), 0 );
	fgSizer9->Add( PathText, 0, wxALL, 5 );
	
	PathOpen = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( PathOpen, 0, wxALL, 5 );
	
	
	sbSizer2->Add( fgSizer9, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Analysis Case") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer91;
	fgSizer91 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer91->SetFlexibleDirection( wxBOTH );
	fgSizer91->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText3 = new wxStaticText( sbSizer5->GetStaticBox(), wxID_ANY, _("Case"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer91->Add( m_staticText3, 0, wxALL, 5 );
	
	wxArrayString AnalysisCaseChoiceChoices;
	AnalysisCaseChoice = new wxChoice( sbSizer5->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), AnalysisCaseChoiceChoices, 0 );
	AnalysisCaseChoice->SetSelection( 0 );
	fgSizer91->Add( AnalysisCaseChoice, 0, wxALL, 5 );
	
	
	sbSizer5->Add( fgSizer91, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer5, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Scaling") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer81;
	fgSizer81 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer81->SetFlexibleDirection( wxBOTH );
	fgSizer81->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, _("Deform"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer81->Add( m_staticText4, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	ScaleSlider = new wxSlider( sbSizer3->GetStaticBox(), wxID_ScaleSlider, 10, 1, 100, wxDefaultPosition, wxSize( 330,-1 ), wxSL_HORIZONTAL );
	fgSizer81->Add( ScaleSlider, 0, wxALL, 5 );
	
	ScaleText = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, _("10"), wxDefaultPosition, wxSize( 64,-1 ), 0 );
	fgSizer81->Add( ScaleText, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, _("Speed"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	fgSizer81->Add( m_staticText42, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	SpeedSlider = new wxSlider( sbSizer3->GetStaticBox(), wxID_ScaleSlider, 0, -100, 100, wxDefaultPosition, wxSize( 330,-1 ), wxSL_HORIZONTAL );
	fgSizer81->Add( SpeedSlider, 0, wxALL, 5 );
	
	SpeedText = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, _("0"), wxDefaultPosition, wxSize( 64,-1 ), 0 );
	fgSizer81->Add( SpeedText, 0, wxALL, 5 );
	
	
	sbSizer3->Add( fgSizer81, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer3, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Time/Mode Number") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 1, 3, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText41 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("  Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer12->Add( m_staticText41, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	TimeSlider = new wxSlider( sbSizer4->GetStaticBox(), wxID_ScaleSlider, 10, 1, 100, wxDefaultPosition, wxSize( 330,-1 ), wxSL_HORIZONTAL );
	fgSizer12->Add( TimeSlider, 0, wxALL, 5 );
	
	TimeText = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 64,-1 ), 0 );
	fgSizer12->Add( TimeText, 0, wxALL, 5 );
	
	
	sbSizer4->Add( fgSizer12, 1, wxEXPAND, 5 );
	
	
	fgSizer2->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	AutoPlay = new wxButton( this, wxID_ANY, _("AutoPlay"), wxDefaultPosition, wxDefaultSize, 0 );
	AutoPlay->SetDefault(); 
	fgSizer8->Add( AutoPlay, 0, wxALL|wxEXPAND, 5 );
	
	Stop = new wxButton( this, wxID_ANY, _("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( Stop, 0, wxALL|wxEXPAND, 5 );
	
	
	fgSizer2->Add( fgSizer8, 1, wxALIGN_RIGHT|wxALL, 5 );
	
	
	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );
	Timer.SetOwner( this, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogShowDeformedBase::OnCloseDialog ) );
	PathOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnSelectResualtFile ), NULL, this );
	AnalysisCaseChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DialogShowDeformedBase::OnChangeCase ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleText->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DialogShowDeformedBase::OnChangedTextScale ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedText->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DialogShowDeformedBase::OnChangedTextSpeed ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	AutoPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnAutoPlay ), NULL, this );
	Stop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnStop ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogShowDeformedBase::OnTimer ) );
}

DialogShowDeformedBase::~DialogShowDeformedBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogShowDeformedBase::OnCloseDialog ) );
	PathOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnSelectResualtFile ), NULL, this );
	AnalysisCaseChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( DialogShowDeformedBase::OnChangeCase ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderScale ), NULL, this );
	ScaleText->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DialogShowDeformedBase::OnChangedTextScale ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedSliderSpeed ), NULL, this );
	SpeedText->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( DialogShowDeformedBase::OnChangedTextSpeed ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	TimeSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogShowDeformedBase::OnChangedTime ), NULL, this );
	AutoPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnAutoPlay ), NULL, this );
	Stop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogShowDeformedBase::OnStop ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( DialogShowDeformedBase::OnTimer ) );
	
}
