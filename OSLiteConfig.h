// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __OSLiteConfig__
#define __OSLiteConfig__

#include <wx/wx.h>
#include <wx/wfstream.h>
#include <wx/fileconf.h>

class OSLiteConfig
{
public:
	OSLiteConfig(wxString Path);

	bool SaveConfig();

	wxString GetOpenSEESPath();
	void SetOpenSEESPath(wxString Val);

	wxColour GetColor(wxString Name);
	void SetColor(wxString Name, wxColour Val);
	wxColour StrToColor(wxString Str);

	void SetFont(wxString Name, wxFont Val);
	wxFont GetFont(wxString Name);

	void SetValue(wxString Name, wxString Val);
	wxString GetValue(wxString Name);

private:

	//ConfigPath;
	wxString ConfigPath;

	//OpenSEES Path
	wxString OpenSEESPath;

	//Color
	wxColour BgColor;
	wxColour PointColor;
	wxColour LineColor;
	wxColour ShellColor;
	wxColour SolidColor;
	wxColour LinkColor;
	wxColour MpColor;
	wxColour TextColor;
	wxColour EdgeColor;
	wxColour OtherColor;

	// Font
	wxFont CodeFont;
	wxFont ModelFont;
	wxFont OutputFont;

	//Transparency
	wxString LineTrans;
	wxString ShellTrans;
	wxString SolidTrans;
	wxString OtherTrans;

	//Real Time Monitor
	wxString Host;
	wxString Port;
	wxString RealTimeMonitor;

	// Other
	wxString LineWidth;
	wxString PointSize;
	wxString Language;

};

#endif
