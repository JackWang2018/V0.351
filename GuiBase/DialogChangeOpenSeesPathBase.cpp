///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "DialogChangeOpenSeesPathBase.h"

///////////////////////////////////////////////////////////////////////////

DialogChangeOpenSeesPathBase::DialogChangeOpenSeesPathBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	OpenSEESPathCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 360,-1 ), 0 );
	fgSizer23->Add( OpenSEESPathCtrl, 0, wxALL, 5 );
	
	Open = new wxButton( this, wxID_Open, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer23->Add( Open, 0, wxALL, 5 );
	
	
	bSizer14->Add( fgSizer23, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer14 );
	this->Layout();
	bSizer14->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Open->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogChangeOpenSeesPathBase::SelectOpenSEES ), NULL, this );
}

DialogChangeOpenSeesPathBase::~DialogChangeOpenSeesPathBase()
{
	// Disconnect Events
	Open->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogChangeOpenSeesPathBase::SelectOpenSEES ), NULL, this );
	
}
