// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "DialogColorsAndFonts.h"

DialogColorsAndFonts::DialogColorsAndFonts(wxWindow* parent)
	: DialogColorsAndFontsBase(parent)
{
	Config = new OSLiteConfig(F.GetWorkPath() + "conf.ini");
	BgColorPicker->SetColour(Config->GetColor("BgColor"));
	PointColorPicker->SetColour(Config->GetColor("PointColor"));
	LineColorPicker->SetColour(Config->GetColor("LineColor"));
	ShellColorPicker->SetColour(Config->GetColor("ShellColor"));
	SolidColorPicker->SetColour(Config->GetColor("SolidColor"));
	OtherColorPicker->SetColour(Config->GetColor("OtherColor"));
	LinkColorPicker->SetColour(Config->GetColor("LinkColor"));
	MpColorPicker->SetColour(Config->GetColor("MpColor"));
	TextColorPicker->SetColour(Config->GetColor("TextColor"));
	EdgeColorPicker->SetColour(Config->GetColor("EdgeColor"));

	CodeFontPicker->SetSelectedFont(Config->GetFont("CodeFont"));
	ModelFontPicker->SetSelectedFont(Config->GetFont("ModelFont"));
	OutputFontPicker->SetSelectedFont(Config->GetFont("OutputFont"));

	LineTransTextCtrl->SetValue(Config->GetValue("LineTrans"));
	ShellTransTextCtrl->SetValue(Config->GetValue("ShellTrans"));
	SolidTransTextCtrl->SetValue(Config->GetValue("SolidTrans"));
	OtherTransTextCtrl->SetValue(Config->GetValue("OtherTrans"));
	LineWidthTextCtrl->SetValue(Config->GetValue("LineWidth"));
	PointSizeTextCtrl->SetValue(Config->GetValue("PointSize"));
}

DialogColorsAndFonts::~DialogColorsAndFonts()
{
}

void DialogColorsAndFonts::OnCancelClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

void DialogColorsAndFonts::OnOKClick(wxCommandEvent& event)
{
	Config->SetColor("BgColor", BgColorPicker->GetColour());
	Config->SetColor("PointColor", PointColorPicker->GetColour());
	Config->SetColor("LineColor", LineColorPicker->GetColour());
	Config->SetColor("ShellColor", ShellColorPicker->GetColour());
	Config->SetColor("SolidColor", SolidColorPicker->GetColour());
	Config->SetColor("OtherColor", OtherColorPicker->GetColour());
	Config->SetColor("LinkColor", LinkColorPicker->GetColour());
	Config->SetColor("MpColor", MpColorPicker->GetColour());
	Config->SetColor("TextColor", TextColorPicker->GetColour());
	Config->SetColor("EdgeColor", EdgeColorPicker->GetColour());

	Config->SetFont("CodeFont", CodeFontPicker->GetSelectedFont());
	Config->SetFont("ModelFont", ModelFontPicker->GetSelectedFont());
	Config->SetFont("OutputFont", OutputFontPicker->GetSelectedFont());

	Config->SetValue("LineTrans", LineTransTextCtrl->GetValue());
	Config->SetValue("ShellTrans", ShellTransTextCtrl->GetValue());
	Config->SetValue("SolidTrans", SolidTransTextCtrl->GetValue());
	Config->SetValue("OtherTrans", OtherTransTextCtrl->GetValue());
	Config->SetValue("LineWidth", LineWidthTextCtrl->GetValue());
	Config->SetValue("PointSize", PointSizeTextCtrl->GetValue());

	Config->SaveConfig();
	EndModal(wxID_OK);
}
