// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __ComFunc__
#define __ComFunc__

#include <iostream>
#include <string>
#include <sstream>

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/wfstream.h>

#define ESP 1e-25

using namespace std;

class ComFunc
{
public:
	wxString GetWorkPath();
	double StrToDouble(string StrIn);
	int StrToInt(string StrIn);
	string ToString(double DoubleIn);
	string ToString(int IntIn);
	string ExpandStr(string Str);
};

#endif
