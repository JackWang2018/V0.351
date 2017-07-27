// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "OSLiteConfig.h"

OSLiteConfig::OSLiteConfig(wxString Path)
{
	ConfigPath = Path;

	// load Config file
	wxFileInputStream IS(ConfigPath);
	wxFileConfig *Config = new wxFileConfig(IS);

	Config->Read(wxT("Path/OpenSEESPath"), &OpenSEESPath);

	wxString STmp;
	Config->Read(wxT("Colors And Fonts/Background"), &STmp);
	BgColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Point"), &STmp);
	PointColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Line"), &STmp);
	LineColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Shell"), &STmp);
	ShellColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Solid"), &STmp);
	SolidColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Other"), &STmp);
	OtherColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Link"), &STmp);
	LinkColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/MP"), &STmp);
	MpColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Text"), &STmp);
	TextColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/Edge"), &STmp);
	EdgeColor = StrToColor(STmp);

	Config->Read(wxT("Colors And Fonts/CodeFont"), &STmp);
	CodeFont = STmp;

	Config->Read(wxT("Colors And Fonts/ModelFont"), &STmp);
	ModelFont = STmp;

	Config->Read(wxT("Colors And Fonts/OutputFont"), &STmp);
	OutputFont = STmp;

	Config->Read(wxT("Transparency/Line"), &LineTrans);
	Config->Read(wxT("Transparency/Shell"), &ShellTrans);
	Config->Read(wxT("Transparency/Solid"), &SolidTrans);
	Config->Read(wxT("Transparency/Other"), &OtherTrans);

	Config->Read(wxT("Real Time Monitor/Host"), &Host);
	Config->Read(wxT("Real Time Monitor/Port"), &Port);
	Config->Read(wxT("Real Time Monitor/RealTimeMonitor"), &RealTimeMonitor);

	Config->Read(wxT("Others/LineWidth"), &LineWidth);
	Config->Read(wxT("Others/PointSize"), &PointSize);
	Config->Read(wxT("Others/Language"), &Language);
}

bool OSLiteConfig::SaveConfig()
{
	// load Config file
	wxFileInputStream IS(ConfigPath);
	wxFileConfig *Config = new wxFileConfig(IS);

	Config->Write(wxT("Path/OpenSEESPath"), OpenSEESPath);
	Config->Write(wxT("Colors And Fonts/Background"), BgColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Point"), PointColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Line"), LineColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Shell"), ShellColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Solid"), SolidColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Other"), OtherColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Link"), LinkColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/MP"), MpColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Text"), TextColor.GetAsString(wxC2S_CSS_SYNTAX));
	Config->Write(wxT("Colors And Fonts/Edge"), EdgeColor.GetAsString(wxC2S_CSS_SYNTAX));

	Config->Write(wxT("Colors And Fonts/CodeFont"), CodeFont);
	Config->Write(wxT("Colors And Fonts/ModelFont"), ModelFont);
	Config->Write(wxT("Colors And Fonts/OutputFont"), OutputFont);

	Config->Write(wxT("Transparency/Line"), LineTrans);
	Config->Write(wxT("Transparency/Shell"), ShellTrans);
	Config->Write(wxT("Transparency/Solid"), SolidTrans);
	Config->Write(wxT("Transparency/Other"), OtherTrans);

	Config->Write(wxT("Real Time Monitor/Host"), Host);
	Config->Write(wxT("Real Time Monitor/Port"), Port);
	Config->Write(wxT("Real Time Monitor/RealTimeMonitor"), RealTimeMonitor);

	Config->Write(wxT("Others/LineWidth"), LineWidth);
	Config->Write(wxT("Others/PointSize"), PointSize);
	Config->Write(wxT("Others/Language"), Language);

	wxFileOutputStream OS(ConfigPath);
	if (OS.IsOk())
	{
		Config->Save(OS);
	}
	OS.Close();
	return true;
}

wxString OSLiteConfig::GetOpenSEESPath()
{
	return OpenSEESPath;
}

void OSLiteConfig::SetOpenSEESPath(wxString Val)
{
	OpenSEESPath = Val;
}

wxColour OSLiteConfig::GetColor(wxString Name)
{
	wxColour Que = wxColor(0, 0, 0, 0);
	if (Name == "BgColor")
	{
		Que = BgColor;
	}
	else if (Name == "PointColor")
	{
		Que = PointColor;
	}
	else if (Name == "LineColor")
	{
		Que = LineColor;
	}
	else if (Name == "ShellColor")
	{
		Que = ShellColor;
	}
	else if (Name == "SolidColor")
	{
		Que = SolidColor;
	}
	else if (Name == "OtherColor")
	{
		Que = OtherColor;
	}
	else if (Name == "LinkColor")
	{
		Que = LinkColor;
	}
	else if (Name == "MpColor")
	{
		Que = MpColor;
	}
	else if (Name == "TextColor")
	{
		Que = TextColor;
	}
	else if (Name == "EdgeColor")
	{
		Que = EdgeColor;
	}
	return Que;
}

void OSLiteConfig::SetColor(wxString Name, wxColour Val)
{
	if (Name == "BgColor")
	{
		BgColor = Val;
	}
	else if (Name == "PointColor")
	{
		PointColor = Val;
	}
	else if (Name == "LineColor")
	{
		LineColor = Val;
	}
	else if (Name == "ShellColor")
	{
		ShellColor = Val;
	}
	else if (Name == "SolidColor")
	{
		SolidColor = Val;
	}
	else if (Name == "OtherColor")
	{
		OtherColor = Val;
	}
	else if (Name == "LinkColor")
	{
		LinkColor = Val;
	}
	else if (Name == "MpColor")
	{
		MpColor = Val;
	}
	else if (Name == "TextColor")
	{
		TextColor = Val;
	}
	else if (Name == "EdgeColor")
	{
		EdgeColor = Val;
	}
}

wxColour OSLiteConfig::StrToColor(wxString Str)
{
	long R, G, B;
	wxString RS, GS, BS;
	Str = Str.SubString(4, Str.length() - 2);
	int k = Str.find(',', 0);
	RS = Str.SubString(0, k - 1);

	Str = Str.SubString(k + 1, Str.length());
	k = Str.find(',', 0);
	GS = Str.SubString(0, k - 1);
	BS = Str.SubString(k + 1, Str.length());

	RS.ToLong(&R, 10);
	GS.ToLong(&G, 10);
	BS.ToLong(&B, 10);

	return wxColor(R, G, B);
}

void OSLiteConfig::SetFont(wxString Name, wxFont Val)
{
	if (Name == "CodeFont")
	{
		CodeFont = Val;
	}
	else if (Name == "ModelFont")
	{
		ModelFont = Val;
	}
	else if (Name == "OutputFont")
	{
		OutputFont = Val;
	}
}

wxFont OSLiteConfig::GetFont(wxString Name)
{
	wxFont Que;
	if (Name == "CodeFont")
	{
		Que = CodeFont;
	}
	else if (Name == "ModelFont")
	{
		Que = ModelFont;
	}
	else if (Name == "OutputFont")
	{
		Que = OutputFont;
	}
	return Que;
}

void OSLiteConfig::SetValue(wxString Name, wxString Val)
{
	if (Name == "LineWidth")
	{
		LineWidth = Val;
	}
	else if (Name == "PointSize")
	{
		PointSize = Val;
	}
	else if (Name == "LineTrans")
	{
		LineTrans = Val;
	}
	else if (Name == "ShellTrans")
	{
		ShellTrans = Val;
	}
	else if (Name == "SolidTrans")
	{
		SolidTrans = Val;
	}
	else if (Name == "OtherTrans")
	{
		OtherTrans = Val;
	}
	else if (Name == "RealTimeMonitor")
	{
		RealTimeMonitor = Val;
	}
	else if (Name == "Host")
	{
		Host = Val;
	}
	else if (Name == "Port")
	{
		Port = Val;
	}
	else if (Name == "Language")
	{
		Language = Val;
	}
}

wxString OSLiteConfig::GetValue(wxString Name)
{
	wxString Que;
	if (Name == "LineWidth")
	{
		Que = LineWidth;
	}
	else if (Name == "PointSize")
	{
		Que = PointSize;
	}
	else if (Name == "LineTrans")
	{
		Que = LineTrans;
	}
	else if (Name == "ShellTrans")
	{
		Que = ShellTrans;
	}
	else if (Name == "SolidTrans")
	{
		Que = SolidTrans;
	}
	else if (Name == "OtherTrans")
	{
		Que = OtherTrans;
	}
	else if (Name == "RealTimeMonitor")
	{
		Que = RealTimeMonitor;
	}
	else if (Name == "Host")
	{
		Que = Host;
	}
	else if (Name == "Port")
	{
		Que = Port;
	}
	else if (Name == "Language")
	{
		Que = Language;
	}

	return Que;
}
