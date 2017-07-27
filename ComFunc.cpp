// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "ComFunc.h"

wxString ComFunc::GetWorkPath()
{
	wxString AppPath;
	wxStandardPathsBase& Stpd = wxStandardPaths::Get();

	wxFileName ExeFile(Stpd.GetExecutablePath());
	AppPath = ExeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);

	return AppPath;
}

double ComFunc::StrToDouble(string StrIn)
{
	stringstream SS;
	SS << StrIn;
	double Ans;
	SS >> Ans;
	return Ans;
}

int ComFunc::StrToInt(string StrIn)
{
	stringstream SS;
	SS << StrIn;
	int Ans;
	SS >> Ans;
	return Ans;
}

string ComFunc::ToString(double DoubleIn)
{
	stringstream SS;
	SS << DoubleIn;
	string Ans;
	SS >> Ans;
	return Ans;
}

string ComFunc::ToString(int IntIn)
{
	stringstream SS;
	SS << IntIn;
	string Ans;
	SS >> Ans;
	return Ans;
}

string ComFunc::ExpandStr(string Str)
{
	int P;
	string SubStr1, SubStr2;
	P = Str.find('+', 0);
	if (P != string::npos)
	{
		SubStr1 = Str.substr(0, P);
		SubStr2 = Str.substr(P + 1, Str.length() - P - 1);
		return ExpandStr(SubStr1) + ExpandStr(SubStr2);
	}
	else
	{
		int Q = Str.find('*', 0);
		if (Q == string::npos)
		{
			return Str + ", ";
		}
		else
		{
			SubStr1 = Str.substr(0, Q);
			SubStr2 = Str.substr(Q + 1, Str.length() - Q - 1);
			int Num = StrToInt(SubStr1);
			double L = StrToDouble(SubStr2);
			string Res = "";
			for (int i = 0; i < Num; ++i)
			{
				Res += ToString(L) + ", ";
			}
			return Res;
		}
	}
}
