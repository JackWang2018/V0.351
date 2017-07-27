///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogRealTimeMonitorDeformBase.h"

///////////////////////////////////////////////////////////////////////////

DialogRealTimeMonitorDeformBase::DialogRealTimeMonitorDeformBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 1, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Scale Factor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer4->Add( m_staticText4, 0, wxALL, 5 );
	
	ScaleSlider = new wxSlider( this, wxID_ScaleSlider, 10, 1, 100, wxDefaultPosition, wxSize( 300,-1 ), wxSL_HORIZONTAL );
	fgSizer4->Add( ScaleSlider, 0, wxALL, 5 );
	
	ScaleText = new wxTextCtrl( this, wxID_ANY, _("10"), wxDefaultPosition, wxSize( 64,-1 ), 0 );
	fgSizer4->Add( ScaleText, 0, wxALL, 5 );
	
	
	fgSizer2->Add( fgSizer4, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer2 );
	this->Layout();
	fgSizer2->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogRealTimeMonitorDeformBase::OnCloseDialog ) );
	ScaleSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
}

DialogRealTimeMonitorDeformBase::~DialogRealTimeMonitorDeformBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DialogRealTimeMonitorDeformBase::OnCloseDialog ) );
	ScaleSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	ScaleSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( DialogRealTimeMonitorDeformBase::OnChanged ), NULL, this );
	
}
