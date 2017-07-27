///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 15 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainWin.h"

#include "../Icon/AnalyzeRun.xpm"
#include "../Icon/AnalyzeSetAnalyzeOpition.xpm"
#include "../Icon/AnalyzeStop.xpm"
#include "../Icon/DefineMaterials.xpm"
#include "../Icon/DefineSection.xpm"
#include "../Icon/DisplayDeformed.xpm"
#include "../Icon/DisplayForcesStresses.xpm"
#include "../Icon/DisplayModel.xpm"
#include "../Icon/DrawLine.xpm"
#include "../Icon/DrawShell.xpm"
#include "../Icon/EditCopy.xpm"
#include "../Icon/EditCut.xpm"
#include "../Icon/EditDelete.xpm"
#include "../Icon/EditPaste.xpm"
#include "../Icon/EditRedo.xpm"
#include "../Icon/EditUndo.xpm"
#include "../Icon/FileDxf.xpm"
#include "../Icon/FileExit.xpm"
#include "../Icon/FileExportNodeAndEle.xpm"
#include "../Icon/FileNew.xpm"
#include "../Icon/FileOpen.xpm"
#include "../Icon/FileSave.xpm"
#include "../Icon/FileSaveAs.xpm"
#include "../Icon/HelpAbout.xpm"
#include "../Icon/HelpDonate.xpm"
#include "../Icon/OptionsColors.xpm"
#include "../Icon/View3D.xpm"
#include "../Icon/ViewEleNum.xpm"
#include "../Icon/ViewNodeNum.xpm"
#include "../Icon/ViewRefresh.xpm"
#include "../Icon/ViewXY.xpm"
#include "../Icon/ViewXZ.xpm"
#include "../Icon/ViewYZ.xpm"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);
	
	MenuBar = new wxMenuBar( 0 );
	MenuFile = new wxMenu();
	wxMenuItem* MenuFileNew;
	MenuFileNew = new wxMenuItem( MenuFile, wxID_MenuFileNew, wxString( _("New Model...") ) + wxT('\t') + wxT("Ctrl+N"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileNew->SetBitmaps( wxBitmap( FileNew_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileNew->SetBitmap( wxBitmap( FileNew_xpm ) );
	#endif
	MenuFile->Append( MenuFileNew );
	
	wxMenuItem* MenuFileOpen;
	MenuFileOpen = new wxMenuItem( MenuFile, wxID_MenuFileOpen, wxString( _("Open...") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileOpen->SetBitmaps( wxBitmap( FileOpen_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileOpen->SetBitmap( wxBitmap( FileOpen_xpm ) );
	#endif
	MenuFile->Append( MenuFileOpen );
	
	MenuFile->AppendSeparator();
	
	wxMenuItem* MenuFileSave;
	MenuFileSave = new wxMenuItem( MenuFile, wxID_MenuFileSave, wxString( _("Save") ) + wxT('\t') + wxT("Ctrl+S"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileSave->SetBitmaps( wxBitmap( FileSave_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileSave->SetBitmap( wxBitmap( FileSave_xpm ) );
	#endif
	MenuFile->Append( MenuFileSave );
	
	wxMenuItem* MenuFileSaveAs;
	MenuFileSaveAs = new wxMenuItem( MenuFile, wxID_MenuFileSaveAs, wxString( _("Save As...") ) + wxT('\t') + wxT("Ctrl+Shit+S"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileSaveAs->SetBitmaps( wxBitmap( FileSaveAs_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileSaveAs->SetBitmap( wxBitmap( FileSaveAs_xpm ) );
	#endif
	MenuFile->Append( MenuFileSaveAs );
	
	MenuFile->AppendSeparator();
	
	wxMenuItem* MenuFileImportDxf;
	MenuFileImportDxf = new wxMenuItem( MenuFile, wxID_MenuFileImportDxf, wxString( _("Import from AutoCAD .dxf file") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileImportDxf->SetBitmaps( wxBitmap( FileDxf_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileImportDxf->SetBitmap( wxBitmap( FileDxf_xpm ) );
	#endif
	MenuFile->Append( MenuFileImportDxf );
	
	wxMenuItem* MenuFileExportNodeAndEle;
	MenuFileExportNodeAndEle = new wxMenuItem( MenuFile, wxID_MenuFileExportNodeAndEle, wxString( _("Export node and element") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileExportNodeAndEle->SetBitmaps( wxBitmap( FileExportNodeAndEle_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileExportNodeAndEle->SetBitmap( wxBitmap( FileExportNodeAndEle_xpm ) );
	#endif
	MenuFile->Append( MenuFileExportNodeAndEle );
	
	MenuFile->AppendSeparator();
	
	wxMenuItem* MenuFileExit;
	MenuFileExit = new wxMenuItem( MenuFile, wxID_MenuFileExit, wxString( _("Exit") ) + wxT('\t') + wxT("Alt+X"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuFileExit->SetBitmaps( wxBitmap( FileExit_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuFileExit->SetBitmap( wxBitmap( FileExit_xpm ) );
	#endif
	MenuFile->Append( MenuFileExit );
	
	MenuBar->Append( MenuFile, _("File  ") ); 
	
	MenuEdit = new wxMenu();
	wxMenuItem* MenuEditUndo;
	MenuEditUndo = new wxMenuItem( MenuEdit, wxID_MenuEditUndo, wxString( _("Undo") ) + wxT('\t') + wxT("Ctrl+Z"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditUndo->SetBitmaps( wxBitmap( EditUndo_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditUndo->SetBitmap( wxBitmap( EditUndo_xpm ) );
	#endif
	MenuEdit->Append( MenuEditUndo );
	
	wxMenuItem* MenuEditRedo;
	MenuEditRedo = new wxMenuItem( MenuEdit, wxID_MenuEditRedo, wxString( _("Redo") ) + wxT('\t') + wxT("Ctrl+Y"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditRedo->SetBitmaps( wxBitmap( EditRedo_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditRedo->SetBitmap( wxBitmap( EditRedo_xpm ) );
	#endif
	MenuEdit->Append( MenuEditRedo );
	
	MenuEdit->AppendSeparator();
	
	wxMenuItem* MenuEditCut;
	MenuEditCut = new wxMenuItem( MenuEdit, wxID_MenuEditCut, wxString( _("Cut") ) + wxT('\t') + wxT("Ctrl+X"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditCut->SetBitmaps( wxBitmap( EditCut_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditCut->SetBitmap( wxBitmap( EditCut_xpm ) );
	#endif
	MenuEdit->Append( MenuEditCut );
	
	wxMenuItem* MenuEditCopy;
	MenuEditCopy = new wxMenuItem( MenuEdit, wxID_MenuEditCopy, wxString( _("Copy") ) + wxT('\t') + wxT("Ctrl+C"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditCopy->SetBitmaps( wxBitmap( EditCopy_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditCopy->SetBitmap( wxBitmap( EditCopy_xpm ) );
	#endif
	MenuEdit->Append( MenuEditCopy );
	
	wxMenuItem* MenuEditPaste;
	MenuEditPaste = new wxMenuItem( MenuEdit, wxID_MenuEditPaste, wxString( _("Paste") ) + wxT('\t') + wxT("Ctrl+V"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditPaste->SetBitmaps( wxBitmap( EditPaste_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditPaste->SetBitmap( wxBitmap( EditPaste_xpm ) );
	#endif
	MenuEdit->Append( MenuEditPaste );
	
	wxMenuItem* MenuEditDelete;
	MenuEditDelete = new wxMenuItem( MenuEdit, wxID_MenuEditDelete, wxString( _("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditDelete->SetBitmaps( wxBitmap( EditDelete_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditDelete->SetBitmap( wxBitmap( EditDelete_xpm ) );
	#endif
	MenuEdit->Append( MenuEditDelete );
	
	MenuEdit->AppendSeparator();
	
	wxMenuItem* MenuEditGoto;
	MenuEditGoto = new wxMenuItem( MenuEdit, wxID_MenuEditGoto, wxString( _("Goto") ) + wxT('\t') + wxT("Ctrl+G"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditGoto->SetBitmaps( wxNullBitmap, wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditGoto->SetBitmap( wxNullBitmap );
	#endif
	MenuEdit->Append( MenuEditGoto );
	
	MenuEdit->AppendSeparator();
	
	wxMenuItem* MenuEditFind;
	MenuEditFind = new wxMenuItem( MenuEdit, wxID_MenuEditFind, wxString( _("Find") ) + wxT('\t') + wxT("Ctrl+F"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditFind->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditFind->SetBitmap( wxNullBitmap );
	#endif
	MenuEdit->Append( MenuEditFind );
	
	wxMenuItem* MenuEditReplace;
	MenuEditReplace = new wxMenuItem( MenuEdit, wxID_MenuEditReplace, wxString( _("Replace") ) + wxT('\t') + wxT("Ctrl+H"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditReplace->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditReplace->SetBitmap( wxNullBitmap );
	#endif
	MenuEdit->Append( MenuEditReplace );
	
	MenuEdit->AppendSeparator();
	
	wxMenuItem* MenuEditComment;
	MenuEditComment = new wxMenuItem( MenuEdit, wxID_MenuEditComment, wxString( _("Comment Selection") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditComment->SetBitmaps( wxNullBitmap, wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditComment->SetBitmap( wxNullBitmap );
	#endif
	MenuEdit->Append( MenuEditComment );
	
	wxMenuItem* MenuEditUnComment;
	MenuEditUnComment = new wxMenuItem( MenuEdit, wxID_MenuEditUnComment, wxString( _("Un-Comment Selection") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuEditUnComment->SetBitmaps( wxNullBitmap, wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuEditUnComment->SetBitmap( wxNullBitmap );
	#endif
	MenuEdit->Append( MenuEditUnComment );
	
	MenuBar->Append( MenuEdit, _("Edit  ") ); 
	
	MenuView = new wxMenu();
	wxMenuItem* MenuViewWrap;
	MenuViewWrap = new wxMenuItem( MenuView, wxID_MenuViewWrap, wxString( _("Wrap mode") ) , wxEmptyString, wxITEM_CHECK );
	#ifdef __WXMSW__
	MenuViewWrap->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuViewWrap->SetBitmap( wxNullBitmap );
	#endif
	MenuView->Append( MenuViewWrap );
	
	wxMenuItem* MenuViewLineNumber;
	MenuViewLineNumber = new wxMenuItem( MenuView, wxID_MenuViewLineNumber, wxString( _("Show line numbers") ) , wxEmptyString, wxITEM_CHECK );
	#ifdef __WXMSW__
	MenuViewLineNumber->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuViewLineNumber->SetBitmap( wxNullBitmap );
	#endif
	MenuView->Append( MenuViewLineNumber );
	MenuViewLineNumber->Check( true );
	
	wxMenuItem* MenuViewLongLine;
	MenuViewLongLine = new wxMenuItem( MenuView, wxID_MenuViewLongLine, wxString( _("Show long line marker") ) , wxEmptyString, wxITEM_CHECK );
	#ifdef __WXMSW__
	MenuViewLongLine->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuViewLongLine->SetBitmap( wxNullBitmap );
	#endif
	MenuView->Append( MenuViewLongLine );
	MenuViewLongLine->Check( true );
	
	MenuBar->Append( MenuView, _("View  ") ); 
	
	MenuDefine = new wxMenu();
	wxMenuItem* MenuDefineMaterials;
	MenuDefineMaterials = new wxMenuItem( MenuDefine, wxID_MenuDefineMaterials, wxString( _("Materials") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuDefineMaterials->SetBitmaps( wxBitmap( DefineMaterials_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuDefineMaterials->SetBitmap( wxBitmap( DefineMaterials_xpm ) );
	#endif
	MenuDefine->Append( MenuDefineMaterials );
	MenuDefineMaterials->Enable( false );
	
	MenuDefine->AppendSeparator();
	
	wxMenuItem* MenuDefineSection;
	MenuDefineSection = new wxMenuItem( MenuDefine, wxID_MenuDefineSection, wxString( _("Section Properties") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuDefineSection->SetBitmaps( wxBitmap( DefineSection_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuDefineSection->SetBitmap( wxBitmap( DefineSection_xpm ) );
	#endif
	MenuDefine->Append( MenuDefineSection );
	
	MenuBar->Append( MenuDefine, _("Define  ") ); 
	
	MenuDraw = new wxMenu();
	MenuBar->Append( MenuDraw, _("Draw  ") ); 
	
	MenuSelect = new wxMenu();
	MenuBar->Append( MenuSelect, _("Select  ") ); 
	
	MenuAssign = new wxMenu();
	MenuBar->Append( MenuAssign, _("Assign  ") ); 
	
	MenuAnalyze = new wxMenu();
	wxMenuItem* MenuSetAnalysisOpintion;
	MenuSetAnalysisOpintion = new wxMenuItem( MenuAnalyze, wxID_MenuSetAnalysisOpintion, wxString( _("Analysis Opintion") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuSetAnalysisOpintion->SetBitmaps( wxBitmap( AnalyzeSetAnalyzeOpition_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuSetAnalysisOpintion->SetBitmap( wxBitmap( AnalyzeSetAnalyzeOpition_xpm ) );
	#endif
	MenuAnalyze->Append( MenuSetAnalysisOpintion );
	
	wxMenuItem* MenuAnalyzeRun;
	MenuAnalyzeRun = new wxMenuItem( MenuAnalyze, wxID_MenuAnalyzeRun, wxString( _("Run") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuAnalyzeRun->SetBitmaps( wxBitmap( AnalyzeRun_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuAnalyzeRun->SetBitmap( wxBitmap( AnalyzeRun_xpm ) );
	#endif
	MenuAnalyze->Append( MenuAnalyzeRun );
	
	wxMenuItem* MenuAnalyzeStop;
	MenuAnalyzeStop = new wxMenuItem( MenuAnalyze, wxID_MenuAnalyzeStop, wxString( _("Stop") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuAnalyzeStop->SetBitmaps( wxBitmap( AnalyzeStop_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuAnalyzeStop->SetBitmap( wxBitmap( AnalyzeStop_xpm ) );
	#endif
	MenuAnalyze->Append( MenuAnalyzeStop );
	
	MenuBar->Append( MenuAnalyze, _("Analyze  ") ); 
	
	MenuDisplay = new wxMenu();
	wxMenuItem* MenuDisplayModel;
	MenuDisplayModel = new wxMenuItem( MenuDisplay, wxID_MenuDisplayModel, wxString( _("Show Model") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuDisplayModel->SetBitmaps( wxBitmap( DisplayModel_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuDisplayModel->SetBitmap( wxBitmap( DisplayModel_xpm ) );
	#endif
	MenuDisplay->Append( MenuDisplayModel );
	
	MenuDisplay->AppendSeparator();
	
	wxMenuItem* MenuDisplayDeformed;
	MenuDisplayDeformed = new wxMenuItem( MenuDisplay, wxID_MenuDisplayDeformed, wxString( _("Display Deformed") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuDisplayDeformed->SetBitmaps( wxBitmap( DisplayDeformed_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuDisplayDeformed->SetBitmap( wxBitmap( DisplayDeformed_xpm ) );
	#endif
	MenuDisplay->Append( MenuDisplayDeformed );
	
	wxMenuItem* MenuRealTimeMonitorDeform;
	MenuRealTimeMonitorDeform = new wxMenuItem( MenuDisplay, wxID_MenuRealTimeMonitorDeform, wxString( _("Real Time Monitor Deform") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuRealTimeMonitorDeform->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuRealTimeMonitorDeform->SetBitmap( wxNullBitmap );
	#endif
	MenuDisplay->Append( MenuRealTimeMonitorDeform );
	
	wxMenuItem* MenuDisplayForcesStresses;
	MenuDisplayForcesStresses = new wxMenuItem( MenuDisplay, wxID_MenuDisplayForcesStresses, wxString( _("Show Forces/Stresses") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuDisplayForcesStresses->SetBitmaps( wxBitmap( DisplayForcesStresses_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuDisplayForcesStresses->SetBitmap( wxBitmap( DisplayForcesStresses_xpm ) );
	#endif
	MenuDisplay->Append( MenuDisplayForcesStresses );
	MenuDisplayForcesStresses->Enable( false );
	
	MenuBar->Append( MenuDisplay, _("Display  ") ); 
	
	MenuOptions = new wxMenu();
	wxMenuItem* MenuOptionsOpenSeesPath;
	MenuOptionsOpenSeesPath = new wxMenuItem( MenuOptions, wxID_MenuOptionsOpenSeesPath, wxString( _("Change OpenSees.exe Path") ) , wxEmptyString, wxITEM_NORMAL );
	MenuOptions->Append( MenuOptionsOpenSeesPath );
	
	wxMenuItem* MenuOptionsCodeComp;
	MenuOptionsCodeComp = new wxMenuItem( MenuOptions, wxID_MenuOptionsCodeComp, wxString( _("Auto Complete") ) , wxEmptyString, wxITEM_CHECK );
	#ifdef __WXMSW__
	MenuOptionsCodeComp->SetBitmaps( wxNullBitmap );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuOptionsCodeComp->SetBitmap( wxNullBitmap );
	#endif
	MenuOptions->Append( MenuOptionsCodeComp );
	MenuOptionsCodeComp->Check( true );
	
	wxMenuItem* MenuOptionsColorsAndFonts;
	MenuOptionsColorsAndFonts = new wxMenuItem( MenuOptions, wxID_MenuOptionsColors, wxString( _("Colors and fonts") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuOptionsColorsAndFonts->SetBitmaps( wxBitmap( OptionsColors_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuOptionsColorsAndFonts->SetBitmap( wxBitmap( OptionsColors_xpm ) );
	#endif
	MenuOptions->Append( MenuOptionsColorsAndFonts );
	
	MenuBar->Append( MenuOptions, _("Options  ") ); 
	
	MenuHelp = new wxMenu();
	wxMenuItem* MenuHelpDonate;
	MenuHelpDonate = new wxMenuItem( MenuHelp, wxID_MenuHelpDonate, wxString( _("Donate") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuHelpDonate->SetBitmaps( wxBitmap( HelpDonate_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuHelpDonate->SetBitmap( wxBitmap( HelpDonate_xpm ) );
	#endif
	MenuHelp->Append( MenuHelpDonate );
	
	wxMenuItem* MenuHelpAbout;
	MenuHelpAbout = new wxMenuItem( MenuHelp, wxID_MenuHelpAbout, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	MenuHelpAbout->SetBitmaps( wxBitmap( HelpAbout_xpm ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	MenuHelpAbout->SetBitmap( wxBitmap( HelpAbout_xpm ) );
	#endif
	MenuHelp->Append( MenuHelpAbout );
	
	MenuBar->Append( MenuHelp, _("Help  ") ); 
	
	this->SetMenuBar( MenuBar );
	
	AuiToolBarFile = new wxAuiToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_LAYOUT ); 
	ToolFileNew = AuiToolBarFile->AddTool( wxID_m_toolFileNew, _("tool"), wxBitmap( FileNew_xpm ), wxNullBitmap, wxITEM_NORMAL, _("New Model..."), wxEmptyString, NULL ); 
	
	ToolFileOpen = AuiToolBarFile->AddTool( wxID_m_toolFileOpen, _("tool"), wxBitmap( FileOpen_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Open..."), wxEmptyString, NULL ); 
	
	ToolFileSave = AuiToolBarFile->AddTool( wxID_m_toolFileSave, _("tool"), wxBitmap( FileSave_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Save"), wxEmptyString, NULL ); 
	
	ToolFileDxf = AuiToolBarFile->AddTool( wxID_m_ToolFileDxf, _("tool"), wxBitmap( FileDxf_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Import Dxf"), wxEmptyString, NULL ); 
	
	AuiToolBarFile->Realize();
	m_mgr.AddPane( AuiToolBarFile, wxAuiPaneInfo().Top().CaptionVisible( false ).PinButton( true ).Gripper().Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Layer( 10 ).ToolbarPane() );
	
	AuiToolBarEdit = new wxAuiToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_LAYOUT ); 
	ToolFileUndo = AuiToolBarEdit->AddTool( wxID_m_toolFileUndo, _("tool"), wxBitmap( EditUndo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Undo"), wxEmptyString, NULL ); 
	
	ToolFileRedo = AuiToolBarEdit->AddTool( wxID_m_toolFileRedo, _("tool"), wxBitmap( EditRedo_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Redo"), wxEmptyString, NULL ); 
	
	ToolFileCut = AuiToolBarEdit->AddTool( wxID_m_toolFileCut, _("tool"), wxBitmap( EditCut_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Cut"), wxEmptyString, NULL ); 
	
	ToolFileCopy = AuiToolBarEdit->AddTool( wxID_m_toolFileCopy, _("tool"), wxBitmap( EditCopy_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Copy"), wxEmptyString, NULL ); 
	
	ToolFilePaste = AuiToolBarEdit->AddTool( wxID_m_toolFilePaste, _("tool"), wxBitmap( EditPaste_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Paste"), wxEmptyString, NULL ); 
	
	AuiToolBarEdit->Realize();
	m_mgr.AddPane( AuiToolBarEdit, wxAuiPaneInfo().Top().CaptionVisible( false ).PinButton( true ).Gripper().Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Layer( 10 ).ToolbarPane() );
	
	AuiToolBarAnalyze = new wxAuiToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_LAYOUT ); 
	ToolAnalyzeRun = AuiToolBarAnalyze->AddTool( wxID_m_toolAnalyzeRun, _("tool"), wxBitmap( AnalyzeRun_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Run Analysis"), wxEmptyString, NULL ); 
	
	ToolAnalyzeStop = AuiToolBarAnalyze->AddTool( wxID_ToolAnalyzeStop, _("tool"), wxBitmap( AnalyzeStop_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Stop Analysis"), wxEmptyString, NULL ); 
	
	AuiToolBarAnalyze->Realize();
	m_mgr.AddPane( AuiToolBarAnalyze, wxAuiPaneInfo().Top().CaptionVisible( false ).PinButton( true ).Gripper().Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Layer( 10 ).ToolbarPane() );
	
	AuiToolBarView = new wxAuiToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE|wxAUI_TB_HORZ_LAYOUT ); 
	ToolViewRefresh = AuiToolBarView->AddTool( wxID_ANY, _("tool"), wxBitmap( ViewRefresh_xpm ), wxNullBitmap, wxITEM_NORMAL, _("Refresh"), wxEmptyString, NULL ); 
	
	ToolViewXYZ = AuiToolBarView->AddTool( wxID_ToolViewXYZ, _("tool"), wxBitmap( View3D_xpm ), wxNullBitmap, wxITEM_NORMAL, _("View default"), wxEmptyString, NULL ); 
	
	ToolViewXZ = AuiToolBarView->AddTool( wxID_ToolViewXZ, _("tool"), wxBitmap( ViewXZ_xpm ), wxNullBitmap, wxITEM_NORMAL, _("View XZ"), wxEmptyString, NULL ); 
	
	ToolViewXY = AuiToolBarView->AddTool( wxID_ToolViewXY, _("tool"), wxBitmap( ViewXY_xpm ), wxNullBitmap, wxITEM_NORMAL, _("View XY"), wxEmptyString, NULL ); 
	
	ToolViewYZ = AuiToolBarView->AddTool( wxID_ToolViewYZ, _("tool"), wxBitmap( ViewYZ_xpm ), wxNullBitmap, wxITEM_NORMAL, _("View YZ"), wxEmptyString, NULL ); 
	
	ToolViewNodeNum = AuiToolBarView->AddTool( wxID_ToolViewNodeNum, _("tool"), wxBitmap( ViewNodeNum_xpm ), wxNullBitmap, wxITEM_CHECK, _("Set On/Off Node Label"), wxEmptyString, NULL ); 
	
	ToolViewEleNum = AuiToolBarView->AddTool( wxID_ToolViewEleNum, _("tool"), wxBitmap( ViewEleNum_xpm ), wxNullBitmap, wxITEM_CHECK, _("Set On/Off Element Label"), wxEmptyString, NULL ); 
	
	ToolDrawLine = AuiToolBarView->AddTool( wxID_ToolDrawLine, _("tool"), wxBitmap( DrawLine_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	ToolDrawShell = AuiToolBarView->AddTool( wxID_ToolDrawShell, _("tool"), wxBitmap( DrawShell_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	AuiToolBarView->Realize();
	m_mgr.AddPane( AuiToolBarView, wxAuiPaneInfo().Top().CaptionVisible( false ).PinButton( true ).Gripper().Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Layer( 10 ).ToolbarPane() );
	
	CodeEdit = new wxStyledTextCtrl( this, wxID_CodeEdit, wxDefaultPosition, wxSize( -1,-1 ), 0, wxEmptyString );
	CodeEdit->SetUseTabs( true );
	CodeEdit->SetTabWidth( 4 );
	CodeEdit->SetIndent( 4 );
	CodeEdit->SetTabIndents( true );
	CodeEdit->SetBackSpaceUnIndents( true );
	CodeEdit->SetViewEOL( false );
	CodeEdit->SetViewWhiteSpace( false );
	CodeEdit->SetMarginWidth( 2, 0 );
	CodeEdit->SetIndentationGuides( false );
	CodeEdit->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	CodeEdit->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	CodeEdit->SetMarginWidth( 1, 16);
	CodeEdit->SetMarginSensitive( 1, true );
	CodeEdit->SetProperty( wxT("fold"), wxT("1") );
	CodeEdit->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	CodeEdit->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	CodeEdit->SetMarginWidth( 0, CodeEdit->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	{
		wxFont font = wxFont( 12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") );
		CodeEdit->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	CodeEdit->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	CodeEdit->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	CodeEdit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	CodeEdit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	CodeEdit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	CodeEdit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	CodeEdit->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	CodeEdit->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	CodeEdit->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	CodeEdit->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	CodeEdit->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	CodeEdit->SetFont( wxFont( 12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_mgr.AddPane( CodeEdit, wxAuiPaneInfo() .Left() .Caption( _("Code") ).CloseButton( false ).MaximizeButton( true ).PaneBorder( false ).Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Row( 0 ).BestSize( wxSize( 480,360 ) ).Layer( 2 ) );
	
	ViewPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	m_mgr.AddPane( ViewPanel, wxAuiPaneInfo() .Center() .Caption( _("Model View") ).CloseButton( false ).MaximizeButton( true ).PaneBorder( false ).Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Layer( 10 ) );
	
	LogBox = new wxStyledTextCtrl( this, wxID_LogBox, wxDefaultPosition, wxSize( -1,-1 ), 0, wxEmptyString );
	LogBox->SetUseTabs( true );
	LogBox->SetTabWidth( 4 );
	LogBox->SetIndent( 4 );
	LogBox->SetTabIndents( true );
	LogBox->SetBackSpaceUnIndents( true );
	LogBox->SetViewEOL( false );
	LogBox->SetViewWhiteSpace( false );
	LogBox->SetMarginWidth( 2, 0 );
	LogBox->SetIndentationGuides( false );
	LogBox->SetMarginWidth( 1, 0 );
	LogBox->SetMarginWidth( 0, 0 );
	{
		wxFont font = wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") );
		LogBox->StyleSetFont( wxSTC_STYLE_DEFAULT, font );
	}
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	LogBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	LogBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	LogBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	LogBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	LogBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	LogBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	LogBox->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	LogBox->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	LogBox->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	LogBox->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	LogBox->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	LogBox->SetFont( wxFont( 10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );
	
	m_mgr.AddPane( LogBox, wxAuiPaneInfo() .Bottom() .Caption( _("Output View") ).CloseButton( false ).MaximizeButton( true ).PaneBorder( false ).Dock().Resizable().FloatingSize( wxSize( -1,-1 ) ).Row( 0 ).BestSize( wxSize( 480,160 ) ).Layer( 1 ) );
	
	StatusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	m_mgr.Update();
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( MenuFileNew->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileNewClick ) );
	this->Connect( MenuFileOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileOpenClick ) );
	this->Connect( MenuFileSave->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileSaveClick ) );
	this->Connect( MenuFileSaveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileSaveAsClick ) );
	this->Connect( MenuFileImportDxf->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileImportDxfClick ) );
	this->Connect( MenuFileExportNodeAndEle->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileExportNodeAndEleClick ) );
	this->Connect( MenuFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileExitClick ) );
	this->Connect( MenuEditUndo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditUndoClick ) );
	this->Connect( MenuEditRedo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditRedoClick ) );
	this->Connect( MenuEditCut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCutClick ) );
	this->Connect( MenuEditCopy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCopyClick ) );
	this->Connect( MenuEditPaste->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditPasteClick ) );
	this->Connect( MenuEditDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditDeleteClick ) );
	this->Connect( MenuEditGoto->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditGotoClick ) );
	this->Connect( MenuEditFind->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditFindClick ) );
	this->Connect( MenuEditReplace->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditReplaceClick ) );
	this->Connect( MenuEditComment->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCommentClick ) );
	this->Connect( MenuEditUnComment->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditUncommentClick ) );
	this->Connect( MenuViewWrap->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewWrapClick ) );
	this->Connect( MenuViewLineNumber->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewLineNumbersClick ) );
	this->Connect( MenuViewLongLine->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewLongLineMarker ) );
	this->Connect( MenuDefineMaterials->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDefineMaterialsClick ) );
	this->Connect( MenuDefineSection->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDefineSectionClick ) );
	this->Connect( MenuSetAnalysisOpintion->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeSetAnalysisOpintionClick ) );
	this->Connect( MenuAnalyzeRun->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeRunClick ) );
	this->Connect( MenuAnalyzeStop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeStopClick ) );
	this->Connect( MenuDisplayModel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewClick ) );
	this->Connect( MenuDisplayDeformed->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDisplayDeformedClick ) );
	this->Connect( MenuRealTimeMonitorDeform->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnRealTimeMonitorClick ) );
	this->Connect( MenuOptionsOpenSeesPath->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsChangeOpenSeesPathClick ) );
	this->Connect( MenuOptionsCodeComp->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsAutoCompClick ) );
	this->Connect( MenuOptionsColorsAndFonts->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsColorsAndFontsClick ) );
	this->Connect( MenuHelpDonate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDonateClick ) );
	this->Connect( MenuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAboutClick ) );
	this->Connect( ToolFileNew->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileNewClick ) );
	this->Connect( ToolFileOpen->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileOpenClick ) );
	this->Connect( ToolFileSave->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileSaveClick ) );
	this->Connect( ToolFileDxf->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileImportDxfClick ) );
	this->Connect( ToolFileUndo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditUndoClick ) );
	this->Connect( ToolFileRedo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditRedoClick ) );
	this->Connect( ToolFileCut->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditCutClick ) );
	this->Connect( ToolFileCopy->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditCopyClick ) );
	this->Connect( ToolFilePaste->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditPasteClick ) );
	this->Connect( ToolAnalyzeRun->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnAnalyzeRunClick ) );
	this->Connect( ToolAnalyzeStop->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnAnalyzeStopClick ) );
	this->Connect( ToolViewRefresh->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewRefresh ) );
	this->Connect( ToolViewXYZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXYZClick ) );
	this->Connect( ToolViewXZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXZClick ) );
	this->Connect( ToolViewXY->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXYClick ) );
	this->Connect( ToolViewYZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewYZClick ) );
	this->Connect( ToolViewNodeNum->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnNodeNumOn ) );
	this->Connect( ToolViewEleNum->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEleNumOn ) );
	CodeEdit->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnChange ), NULL, this );
	CodeEdit->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MainFrameBase::OnRightMenu ), NULL, this );
	CodeEdit->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::OnUpdateUI ), NULL, this );
	ViewPanel->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnSetVtkSize ), NULL, this );
	LogBox->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameBase::OnChange ), NULL, this );
	LogBox->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::OnUpdateUI ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxID_MenuFileNew, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileNewClick ) );
	this->Disconnect( wxID_MenuFileOpen, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileOpenClick ) );
	this->Disconnect( wxID_MenuFileSave, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileSaveClick ) );
	this->Disconnect( wxID_MenuFileSaveAs, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileSaveAsClick ) );
	this->Disconnect( wxID_MenuFileImportDxf, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileImportDxfClick ) );
	this->Disconnect( wxID_MenuFileExportNodeAndEle, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileExportNodeAndEleClick ) );
	this->Disconnect( wxID_MenuFileExit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnFileExitClick ) );
	this->Disconnect( wxID_MenuEditUndo, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditUndoClick ) );
	this->Disconnect( wxID_MenuEditRedo, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditRedoClick ) );
	this->Disconnect( wxID_MenuEditCut, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCutClick ) );
	this->Disconnect( wxID_MenuEditCopy, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCopyClick ) );
	this->Disconnect( wxID_MenuEditPaste, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditPasteClick ) );
	this->Disconnect( wxID_MenuEditDelete, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditDeleteClick ) );
	this->Disconnect( wxID_MenuEditGoto, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditGotoClick ) );
	this->Disconnect( wxID_MenuEditFind, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditFindClick ) );
	this->Disconnect( wxID_MenuEditReplace, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditReplaceClick ) );
	this->Disconnect( wxID_MenuEditComment, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditCommentClick ) );
	this->Disconnect( wxID_MenuEditUnComment, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnEditUncommentClick ) );
	this->Disconnect( wxID_MenuViewWrap, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewWrapClick ) );
	this->Disconnect( wxID_MenuViewLineNumber, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewLineNumbersClick ) );
	this->Disconnect( wxID_MenuViewLongLine, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewLongLineMarker ) );
	this->Disconnect( wxID_MenuDefineMaterials, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDefineMaterialsClick ) );
	this->Disconnect( wxID_MenuDefineSection, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDefineSectionClick ) );
	this->Disconnect( wxID_MenuSetAnalysisOpintion, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeSetAnalysisOpintionClick ) );
	this->Disconnect( wxID_MenuAnalyzeRun, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeRunClick ) );
	this->Disconnect( wxID_MenuAnalyzeStop, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAnalyzeStopClick ) );
	this->Disconnect( wxID_MenuDisplayModel, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnViewClick ) );
	this->Disconnect( wxID_MenuDisplayDeformed, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDisplayDeformedClick ) );
	this->Disconnect( wxID_MenuRealTimeMonitorDeform, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnRealTimeMonitorClick ) );
	this->Disconnect( wxID_MenuOptionsOpenSeesPath, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsChangeOpenSeesPathClick ) );
	this->Disconnect( wxID_MenuOptionsCodeComp, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsAutoCompClick ) );
	this->Disconnect( wxID_MenuOptionsColors, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnOptionsColorsAndFontsClick ) );
	this->Disconnect( wxID_MenuHelpDonate, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnDonateClick ) );
	this->Disconnect( wxID_MenuHelpAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnAboutClick ) );
	this->Disconnect( ToolFileNew->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileNewClick ) );
	this->Disconnect( ToolFileOpen->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileOpenClick ) );
	this->Disconnect( ToolFileSave->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileSaveClick ) );
	this->Disconnect( ToolFileDxf->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnFileImportDxfClick ) );
	this->Disconnect( ToolFileUndo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditUndoClick ) );
	this->Disconnect( ToolFileRedo->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditRedoClick ) );
	this->Disconnect( ToolFileCut->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditCutClick ) );
	this->Disconnect( ToolFileCopy->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditCopyClick ) );
	this->Disconnect( ToolFilePaste->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditPasteClick ) );
	this->Disconnect( ToolAnalyzeRun->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnAnalyzeRunClick ) );
	this->Disconnect( ToolAnalyzeStop->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnAnalyzeStopClick ) );
	this->Disconnect( ToolViewRefresh->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewRefresh ) );
	this->Disconnect( ToolViewXYZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXYZClick ) );
	this->Disconnect( ToolViewXZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXZClick ) );
	this->Disconnect( ToolViewXY->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewXYClick ) );
	this->Disconnect( ToolViewYZ->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnViewYZClick ) );
	this->Disconnect( ToolViewNodeNum->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnNodeNumOn ) );
	this->Disconnect( ToolViewEleNum->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::OnEleNumOn ) );
	CodeEdit->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( MainFrameBase::OnChange ), NULL, this );
	CodeEdit->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MainFrameBase::OnRightMenu ), NULL, this );
	CodeEdit->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::OnUpdateUI ), NULL, this );
	ViewPanel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrameBase::OnSetVtkSize ), NULL, this );
	LogBox->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( MainFrameBase::OnChange ), NULL, this );
	LogBox->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::OnUpdateUI ), NULL, this );
	
	m_mgr.UnInit();
	
}
