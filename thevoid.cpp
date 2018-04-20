// thevoid.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "thevoid.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "thevoidDoc.h"
#include "thevoidView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThevoidApp

BEGIN_MESSAGE_MAP(CThevoidApp, CWinApp)
	//{{AFX_MSG_MAP(CThevoidApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_CLOSE_CAPTURED_ON_CLOSE, OnCloseCapturedOnClose)
	ON_UPDATE_COMMAND_UI(ID_CLOSE_CAPTURED_ON_CLOSE, OnUpdateCloseCapturedOnClose)
	ON_COMMAND(ID_SHOW_ALL, OnShowAll)
	ON_UPDATE_COMMAND_UI(ID_SHOW_ALL, OnUpdateShowAll)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThevoidApp construction

CThevoidApp::CThevoidApp()
{
	m_bCloseCapturedOnViewClose = true;
	m_bShowAllWindows = false;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CThevoidApp object

CThevoidApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CThevoidApp initialization

BOOL CThevoidApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_THEVOITYPE,
		RUNTIME_CLASS(CThevoidDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CThevoidView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CThevoidApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CThevoidApp message handlers


void CThevoidApp::OnCloseCapturedOnClose() 
{
	m_bCloseCapturedOnViewClose = !m_bCloseCapturedOnViewClose;
}

void CThevoidApp::OnUpdateCloseCapturedOnClose(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_bCloseCapturedOnViewClose ? 1 : 0 );
}

void CThevoidApp::OnShowAll() 
{
	m_bShowAllWindows = !m_bShowAllWindows;
}

void CThevoidApp::OnUpdateShowAll(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_bShowAllWindows ? 1 : 0 );
}
