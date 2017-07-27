// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#include "ThreadAnalyze.h"

ThreadAnalyze::ThreadAnalyze(wxString FileNameIn, bool *Running, wxProcess *RunProcessIn, wxWindow *HandleIn) : wxThread(wxTHREAD_JOINABLE)
{
	FileName = FileNameIn;
	RunProcess = RunProcessIn;
	Handle = HandleIn;
	RunFalg = Running;
}

ThreadAnalyze::~ThreadAnalyze()
{
}

wxThread::ExitCode ThreadAnalyze::Entry()
{
	wxThreadEvent event(wxEVT_THREAD_RUN);
	wxInputStream *Stream = RunProcess->GetErrorStream();
	wxTextInputStream Reader(*Stream);
	while (!Stream->Eof())
	{
		wxString Line = Reader.ReadLine();
		event.SetString(Line);
		Handle->GetEventHandler()->AddPendingEvent(event);
	}

	(*RunFalg) = false;
	event.SetString("End Of Script!");
	//wxRemoveFile(FileName);
	Handle->GetEventHandler()->AddPendingEvent(event);
	return (wxThread::ExitCode)0;   // success
}
