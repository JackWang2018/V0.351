// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __ThreadRun__
#define __ThreadRun__

#include <iostream>
#include <string>

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/stc/stc.h>
#include "ComFunc.h"
#include "DeclareUserEvent.h"

using namespace std;


class ThreadAnalyze : public wxThread
{
public:
	ThreadAnalyze(wxString FileNameIn, bool *Running, wxProcess *RunProcessIn, wxWindow *HandleIn);
	~ThreadAnalyze();
	virtual ExitCode Entry() wxOVERRIDE;

private:
	wxProcess *RunProcess;
	wxWindow *Handle;
	bool *RunFalg;
	wxString FileName;
};

#endif
