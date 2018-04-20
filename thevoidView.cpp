// thevoidView.cpp : implementation of the CThevoidView class
//

#include "stdafx.h"
#include "thevoid.h"

#include "thevoidDoc.h"
#include "thevoidView.h"
#include "ListWindowsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThevoidView

IMPLEMENT_DYNCREATE(CThevoidView, CView)

BEGIN_MESSAGE_MAP(CThevoidView, CView)
	//{{AFX_MSG_MAP(CThevoidView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThevoidView construction/destruction

CThevoidView::CThevoidView()
{
	m_hwndCaptured = 0;
	m_dwStyle = 0;
	m_dwExStyle = 0;
}

CThevoidView::~CThevoidView()
{
}

BOOL CThevoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

//	cs.style

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CThevoidView drawing

void CThevoidView::OnDraw(CDC* pDC)
{
	CThevoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CThevoidView diagnostics

#ifdef _DEBUG
void CThevoidView::AssertValid() const
{
	CView::AssertValid();
}

void CThevoidView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThevoidDoc* CThevoidView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThevoidDoc)));
	return (CThevoidDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CThevoidView message handlers

int CThevoidView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	CListWindowsDlg dlg;

	CThevoidApp * pVoidApp = (CThevoidApp *)AfxGetApp();

	if ( pVoidApp ) {

		dlg.m_bShowAll = pVoidApp->m_bShowAllWindows;

	}

	if ( IDOK != dlg.DoModal() ) {

		return 0;

	}

	m_hwndCaptured = dlg.m_hSelectedWindow;

	CWnd * pCapturedWnd = CWnd::FromHandle( m_hwndCaptured );

	if ( pCapturedWnd ) {

		pCapturedWnd->ShowWindow( SW_HIDE );

		DWORD style = m_dwStyle = GetWindowLong( m_hwndCaptured, GWL_STYLE );
		DWORD exStyle = m_dwExStyle = GetWindowLong( m_hwndCaptured, GWL_EXSTYLE );

		// remove unwanted styles

		exStyle &= ~( WS_EX_APPWINDOW | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE);

		style &= ~( WS_POPUP );
		style |= WS_CHILD;

		// change

		SetWindowLong( m_hwndCaptured, GWL_STYLE, style );
		SetWindowLong( m_hwndCaptured, GWL_EXSTYLE, exStyle );

		pCapturedWnd->SetParent( this );
		pCapturedWnd->SetOwner( this );

		// 

		pCapturedWnd->ShowWindow( SW_SHOW );

	}
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CThevoidView::ReleaseWindow()
{

	if ( m_hwndCaptured ) {

		CWnd * pWnd = CWnd::FromHandle( m_hwndCaptured );

		if ( pWnd ) {

			pWnd->ShowWindow( SW_HIDE );
	
			pWnd->SetParent( GetDesktopWindow() );
	
			pWnd->SetOwner( NULL );
	
			SetWindowLong( m_hwndCaptured, GWL_STYLE, m_dwStyle );

			SetWindowLong( m_hwndCaptured, GWL_EXSTYLE, m_dwExStyle );

			pWnd->ShowWindow( SW_SHOW );

			CThevoidApp * pVoidApp = (CThevoidApp *)AfxGetApp();

			if ( pVoidApp && pVoidApp->m_bCloseCapturedOnViewClose ) {

				pWnd->PostMessage( WM_CLOSE );

			}

		}

		m_hwndCaptured = 0;

	}
}

void CThevoidView::OnDestroy() 
{
	ReleaseWindow();

	CView::OnDestroy();
}

void CThevoidView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	CView::CalcWindowRect(lpClientRect, nAdjustType);
}

void CThevoidView::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	CView::OnRButtonDblClk(nFlags, point);
}

void CThevoidView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	if ( m_hwndCaptured ) {

		if ( !IsIconic() ) {

			CRect clientRect;
	
			GetClientRect( &clientRect );
	
			::MoveWindow( m_hwndCaptured, 0, 0, clientRect.Width(), clientRect.Height(), FALSE );

		}

	}
	
	// TODO: Add your message handler code here
	
}

void CThevoidView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
}
