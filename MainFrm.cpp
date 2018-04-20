// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "thevoid.h"

#include "MainFrm.h"
#include "MinimizeToTray\MinimizeToTray.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_WM_SYSCOMMAND()
	ON_MESSAGE( WM_USER, OnTrayMessage )
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

//
//	CMainFrame::ShowNotifyIcon()
//

void CMainFrame::ShowNotifyIcon( bool bAdd )
{
	NOTIFYICONDATA nid;
	
	ZeroMemory( &nid, sizeof(nid) );
	
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = GetSafeHwnd();
	nid.uID = 0;
	nid.uFlags = NIF_ICON | NIF_MESSAGE /* | NIF_TIP */;
	nid.uCallbackMessage = WM_USER; // what should this be?
	nid.hIcon = LoadIcon( AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME) );
	
//	lstrcpy( nid.szTip, TEXT("Double click to activate!") );
	
	if( bAdd ) {
	
		Shell_NotifyIcon( NIM_ADD, &nid );
	
	} else {

		Shell_NotifyIcon( NIM_DELETE, &nid );
	
	}

}

//
//	CMainFrame::OnSysCommand()
//

void 
CMainFrame::OnSysCommand( UINT nID, LPARAM lParam )
{
	if ( SC_MINIMIZE == nID ) {

		ShowWindow( SW_HIDE );

		ShowNotifyIcon( true );

	} else {

		CMDIFrameWnd::OnSysCommand( nID, lParam );

	}
}

//
//	CMainFrame::OnTrayMessage()
//

LRESULT
CMainFrame::OnTrayMessage( WPARAM wParam, LPARAM lParam )
{
	switch ( lParam ) {

	case WM_RBUTTONDBLCLK:
		ShowWindow( SW_SHOWNORMAL );
		SetActiveWindow();
		SetForegroundWindow();
		m_bDoubleClickedHideTrayIcon = true;
		return TRUE;
		break;

	case WM_RBUTTONUP:
		if ( m_bDoubleClickedHideTrayIcon ) {

			ShowNotifyIcon( false );

			m_bDoubleClickedHideTrayIcon = false;

		}
		return TRUE;
		break;

	}

	return FALSE;
}

// ----------------------------------------------------------------------------

//
//	CMainFrame::CMainFrame()
//

CMainFrame::CMainFrame()
{
	m_bDoubleClickedHideTrayIcon = false;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::DestroyWindow() 
{
	return CMDIFrameWnd::DestroyWindow();
}
