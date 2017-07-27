///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINWIN_H__
#define __MAINWIN_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/stc/stc.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_MenuFileNew 1000
#define wxID_MenuFileOpen 1001
#define wxID_MenuFileSave 1002
#define wxID_MenuFileSaveAs 1003
#define wxID_MenuFileImportDxf 1004
#define wxID_MenuFileExportNodeAndEle 1005
#define wxID_MenuFileExit 1006
#define wxID_MenuEditUndo 1007
#define wxID_MenuEditRedo 1008
#define wxID_MenuEditCut 1009
#define wxID_MenuEditCopy 1010
#define wxID_MenuEditPaste 1011
#define wxID_MenuEditDelete 1012
#define wxID_MenuEditGoto 1013
#define wxID_MenuEditFind 1014
#define wxID_MenuEditReplace 1015
#define wxID_MenuEditComment 1016
#define wxID_MenuEditUnComment 1017
#define wxID_MenuViewWrap 1018
#define wxID_MenuViewLineNumber 1019
#define wxID_MenuViewLongLine 1020
#define wxID_MenuDefineMaterials 1021
#define wxID_MenuDefineSection 1022
#define wxID_MenuSetAnalysisOpintion 1023
#define wxID_MenuAnalyzeRun 1024
#define wxID_MenuAnalyzeStop 1025
#define wxID_MenuDisplayModel 1026
#define wxID_MenuDisplayDeformed 1027
#define wxID_MenuRealTimeMonitorDeform 1028
#define wxID_MenuDisplayForcesStresses 1029
#define wxID_MenuOptionsOpenSeesPath 1030
#define wxID_MenuOptionsCodeComp 1031
#define wxID_MenuOptionsColors 1032
#define wxID_MenuHelpDonate 1033
#define wxID_MenuHelpAbout 1034
#define wxID_m_toolFileNew 1035
#define wxID_m_toolFileOpen 1036
#define wxID_m_toolFileSave 1037
#define wxID_m_ToolFileDxf 1038
#define wxID_m_toolFileUndo 1039
#define wxID_m_toolFileRedo 1040
#define wxID_m_toolFileCut 1041
#define wxID_m_toolFileCopy 1042
#define wxID_m_toolFilePaste 1043
#define wxID_m_toolAnalyzeRun 1044
#define wxID_ToolAnalyzeStop 1045
#define wxID_ToolViewXYZ 1046
#define wxID_ToolViewXZ 1047
#define wxID_ToolViewXY 1048
#define wxID_ToolViewYZ 1049
#define wxID_ToolViewNodeNum 1050
#define wxID_ToolViewEleNum 1051
#define wxID_ToolDrawLine 1052
#define wxID_ToolDrawShell 1053
#define wxID_CodeEdit 1054
#define wxID_LogBox 1055

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* MenuBar;
		wxMenu* MenuFile;
		wxMenu* MenuEdit;
		wxMenu* MenuView;
		wxMenu* MenuDefine;
		wxMenu* MenuDraw;
		wxMenu* MenuSelect;
		wxMenu* MenuAssign;
		wxMenu* MenuAnalyze;
		wxMenu* MenuDisplay;
		wxMenu* MenuOptions;
		wxMenu* MenuHelp;
		wxAuiToolBar* AuiToolBarFile;
		wxAuiToolBarItem* ToolFileNew; 
		wxAuiToolBarItem* ToolFileOpen; 
		wxAuiToolBarItem* ToolFileSave; 
		wxAuiToolBarItem* ToolFileDxf; 
		wxAuiToolBar* AuiToolBarEdit;
		wxAuiToolBarItem* ToolFileUndo; 
		wxAuiToolBarItem* ToolFileRedo; 
		wxAuiToolBarItem* ToolFileCut; 
		wxAuiToolBarItem* ToolFileCopy; 
		wxAuiToolBarItem* ToolFilePaste; 
		wxAuiToolBar* AuiToolBarAnalyze;
		wxAuiToolBarItem* ToolAnalyzeRun; 
		wxAuiToolBarItem* ToolAnalyzeStop; 
		wxAuiToolBar* AuiToolBarView;
		wxAuiToolBarItem* ToolViewRefresh; 
		wxAuiToolBarItem* ToolViewXYZ; 
		wxAuiToolBarItem* ToolViewXZ; 
		wxAuiToolBarItem* ToolViewXY; 
		wxAuiToolBarItem* ToolViewYZ; 
		wxAuiToolBarItem* ToolViewNodeNum; 
		wxAuiToolBarItem* ToolViewEleNum; 
		wxAuiToolBarItem* ToolDrawLine; 
		wxAuiToolBarItem* ToolDrawShell; 
		wxStyledTextCtrl* CodeEdit;
		wxPanel* ViewPanel;
		wxStyledTextCtrl* LogBox;
		wxStatusBar* StatusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFileNewClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileOpenClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileSaveAsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileImportDxfClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileExportNodeAndEleClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileExitClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditUndoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditRedoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditCutClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditCopyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditPasteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditDeleteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditGotoClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditFindClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditReplaceClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditCommentClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditUncommentClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewWrapClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewLineNumbersClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewLongLineMarker( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDefineMaterialsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDefineSectionClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAnalyzeSetAnalysisOpintionClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAnalyzeRunClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAnalyzeStopClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDisplayDeformedClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRealTimeMonitorClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOptionsChangeOpenSeesPathClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOptionsAutoCompClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOptionsColorsAndFontsClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDonateClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAboutClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewRefresh( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewXYZClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewXZClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewXYClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnViewYZClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNodeNumOn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEleNumOn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChange( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnRightMenu( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnSetVtkSize( wxSizeEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,700 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxMAXIMIZE_BOX|wxTAB_TRAVERSAL );
		wxAuiManager m_mgr;
		
		~MainFrameBase();
	
};

#endif //__MAINWIN_H__
