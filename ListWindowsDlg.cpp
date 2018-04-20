// ListWindowsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "thevoid.h"
#include "ListWindowsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListWindowsDlg dialog


CListWindowsDlg::CListWindowsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListWindowsDlg::IDD, pParent)
{
	m_hSelectedWindow = NULL;
	m_bShowAll = false;

	//{{AFX_DATA_INIT(CListWindowsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CListWindowsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListWindowsDlg)
	DDX_Control(pDX, IDC_LIST1, m_Windows);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CListWindowsDlg, CDialog)
	//{{AFX_MSG_MAP(CListWindowsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListWindowsDlg message handlers

//
//	EnumDesktopWindowsProc()
//

static BOOL CALLBACK 
EnumDesktopWindowsProc( HWND hwnd, LPARAM lParam )
{
	CListWindowsDlg * pDlg = (CListWindowsDlg *) lParam;
	
	if ( pDlg ) {

		if ( (!pDlg->m_bShowAll) && (FALSE == IsWindowVisible( hwnd )) ) {

			return TRUE;

		}

		char name[ _MAX_PATH ];

		::GetWindowText( hwnd, name, sizeof(name) - 1 );

		DWORD dwExStyle = GetWindowLong( hwnd, GWL_EXSTYLE );

		if ( strlen( name ) ) {

			int index = pDlg->m_Windows.AddString( name );

			if ( LB_ERR != index ) {

				pDlg->m_Windows.SetItemData( index, (DWORD)hwnd );

			}

		}

	}

	return TRUE;
}

//
//	CListWindowsDlg::OnInitDialog()
//

BOOL 
CListWindowsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

//	EnumDesktopWindows( NULL, EnumDesktopWindowsProc, (LPARAM)(this) );
	EnumWindows( EnumDesktopWindowsProc, (LPARAM)(this) );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CListWindowsDlg::OnOK() 
{
	int index = m_Windows.GetCurSel();

	if ( LB_ERR != index ) {

		m_hSelectedWindow = (HWND)m_Windows.GetItemData( index );

	}
	
	CDialog::OnOK();
}
