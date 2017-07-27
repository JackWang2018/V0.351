// =========================================================================
//    Description:
//       Compiler:  gcc
//         Author:  Jacques CHEN
//         E-Mail:  jacques.chen@qq.com
//       Web-Site:  http://blog.whchen.net
// =========================================================================

#ifndef __Main__
#define __Main__

// main wxWidgets header file

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <float.h>
#include <stdlib.h>
#include <ctype.h>
#include <thread>

#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/fileconf.h>
#include <wx/timer.h>
#include <wx/glcanvas.h>
#include <wx/math.h>
#include <wx/log.h>
#include <wx/cmdline.h>
#include <wx/wfstream.h>
#include <wx/zstream.h>
#include <wx/tokenzr.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/thread.h>
#include <wx/filename.h>
#include <wx/arrstr.h>
#include <wx/fdrepdlg.h>
#include <wx/intl.h>
#include <wx/numdlg.h>
#include <wx/cmdline.h>
#include <tcl.h>

#include "OSLiteConfig.h"
#include "ComFunc.h"
#include "icon/Logo.xpm"
#include "GuiBase/MainWin.h"
#include "AutoComplete.h"
#include "VtkWin.h"
#include "DialogModelerWizard.h"
#include "DialogQuickMaterial.h"
#include "DialogSectionProperties.h"
#include "DialogImportDxf.h"
#include "DialogColorsAndFonts.h"
#include "DialogChangeOpenSeesPath.h"
#include "DialogRealTimeMonitorDeform.h"
#include "DialogSetAnalysisOpintion.h"
#include "GuiBase/DialogAbout.h"
#include "GuiBase/DialogDonate.h"
#include "DialogShowDeformed.h"
#include "Struct.h"
#include "ThreadAnalyze.h"
#include "TclInterFace.h"
#include "DefineUserEvent.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// application class declaration
////////////////////////////////////////////////////////////////////////////////

class MainApp : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;
	void SelectLanguage(int Lang);
private:
	wxLocale *Locale;
};

// declare global static function wxGetApp()
DECLARE_APP(MainApp)



////////////////////////////////////////////////////////////////////////////////
// main application frame declaration
////////////////////////////////////////////////////////////////////////////////

class MainFrame : public MainFrameBase
{
public:
	MainFrame(wxWindow* parent);
	virtual ~MainFrame();

private:
	wxString Version = wxT("0.351");
	wxString ReleaseDate = wxT("2017.07.08 ");
	wxString Author = wxT("Jacques.CHEN/Zack Chen (³ÂÎ¬»Î) ");

	ComFunc F;
	OSLiteConfig *Config;

	wxString Title;
	wxString KeyWords;
	wxString FileName;
	int NumOfNode;
	bool IsEdited;
	bool IsWrapMode;
	bool IsLineNumber;
	bool IsAutoComp;
	bool IsNodeNumOn;
	bool IsEleNumOn;
	bool IsRtMonitor;
	bool Is3dModel;
	bool IsRunning;
	wxFont CodeFont;
	wxFont ModelFont;
	wxFont OutputFont;
	TrieTree *KeyWordTire;
	VtkWin* OsVtkWin;

	ThreadAnalyze *AnalyzeThread;
	wxCriticalSection AnalyzeThreadCS;
	wxProcess *AnalyzeProcess;

	wxString MonitorHost;
	wxSocketServer *Server;
	wxSocketBase *Sock;
	int MonitorPort;
	int MonitorScale;
	int TcpDataCount;
	char TcpDataFlag;

	int NumModes;

	list<double> DeformList;
	double *DeformArr;
	map<int, int> NodeMap;
	map<int, Node> NodeCond;
	double MaxDeform;

	// menu file
	virtual void OnFileNewClick(wxCommandEvent& event);
	virtual void OnFileOpenClick(wxCommandEvent& event);
	virtual void OnFileSaveClick(wxCommandEvent& event);
	virtual void OnFileSaveAsClick(wxCommandEvent& event);
	virtual void OnFileImportDxfClick(wxCommandEvent& event);
	virtual void OnFileExportNodeAndEleClick(wxCommandEvent& event);
	virtual void OnCloseFrame(wxCloseEvent& event);
	virtual void OnFileExitClick(wxCommandEvent& event);
	virtual void Save();

	// menu edit
	virtual void OnEditUndoClick(wxCommandEvent& event);
	virtual void OnEditRedoClick(wxCommandEvent& event);
	virtual void OnEditCutClick(wxCommandEvent& event);
	virtual void OnEditCopyClick(wxCommandEvent& event);
	virtual void OnEditPasteClick(wxCommandEvent& event);
	virtual void OnEditDeleteClick(wxCommandEvent& event);
	virtual void OnEditGotoClick(wxCommandEvent& event);

	wxFindReplaceData FindData;
	wxFindReplaceDialog *FindDialog, *ReplaceDialog;
	int LastIndex, LastGoto;
	wxMenu *RightMenu;
	virtual void OnEditFindClick(wxCommandEvent& event);
	virtual void OnEditReplaceClick(wxCommandEvent& event);
	virtual void OnEditFindDialog(wxFindDialogEvent& event);
	virtual void OnEditCommentClick(wxCommandEvent& event);
	virtual void OnEditUncommentClick(wxCommandEvent& event);
	virtual void OnRightMenu(wxMouseEvent& event);

	// menu view
	virtual void OnViewWrapClick(wxCommandEvent& event);
	virtual void OnViewLineNumbersClick(wxCommandEvent& event);
	virtual void OnViewLongLineMarker(wxCommandEvent& event);

	// menu define
	virtual void OnDefineMaterialsClick(wxCommandEvent& event);
	virtual void OnDefineSectionClick(wxCommandEvent& event);

	// menu analyze
	DialogSetAnalysisOpintion* SetAnalysisOpintionDialog;
	DialogRealTimeMonitorDeform* RealTimeMonitorDeformDialog;
	virtual void OnAnalyzeSetAnalysisOpintionClick(wxCommandEvent& event);
	virtual void OnAnalyzeRunClick(wxCommandEvent& event);
	virtual void OnAnalyzeStopClick(wxCommandEvent& event);
	virtual void StopOS();
	virtual void OnOutputLog(wxThreadEvent& event);

	// menu options
	virtual void OnOptionsAutoCompClick(wxCommandEvent& event);
	virtual void OnOptionsColorsAndFontsClick(wxCommandEvent& event);
	virtual void OnOptionsChangeOpenSeesPathClick(wxCommandEvent& event);
	void ChangeOpenSeesPath();

	// menu display
	DialogShowDeformed* ShowDeformedDialog;
	virtual void OnSetVtkSize(wxSizeEvent& event);
	virtual void OnDisplayDeformedClick(wxCommandEvent& event);
	virtual void OnRealTimeMonitorClick(wxCommandEvent& event);
	virtual void OnDisplayNodeDeformByDialog(wxCommandEvent& event);
	virtual void DisplayNodeDeform(bool IsRealTime, double MaxDeform = 0.0);

	//menu help
	virtual void OnAboutClick(wxCommandEvent& event);
	virtual void OnDonateClick(wxCommandEvent& event);

	//tool bar
	virtual void OnViewRefresh(wxCommandEvent& event);
	virtual void OnViewXYZClick(wxCommandEvent& event);
	virtual void OnViewXZClick(wxCommandEvent& event);
	virtual void OnViewXYClick(wxCommandEvent& event);
	virtual void OnViewYZClick(wxCommandEvent& event);
	virtual void OnNodeNumOn(wxCommandEvent& event);
	virtual void OnEleNumOn(wxCommandEvent& event);

	// something about code edit
	virtual void OnChange(wxKeyEvent& event);
	virtual void OnUpdateUI(wxUpdateUIEvent& event);
	virtual void UpdateCodeEdit();

	// something about model view
	virtual void SendModelData();
	virtual void OnServerEvent(wxSocketEvent& event);
	virtual void OnSocketEvent(wxSocketEvent& event);
	virtual void OnSetState(wxCommandEvent& event);
};

#endif
