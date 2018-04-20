#if !defined(AFX_LISTWINDOWSDLG_H__CCB91800_2E50_42F2_BB5C_F83DF1CD497B__INCLUDED_)
#define AFX_LISTWINDOWSDLG_H__CCB91800_2E50_42F2_BB5C_F83DF1CD497B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListWindowsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListWindowsDlg dialog

class CListWindowsDlg : public CDialog
{
// Construction
public:

	CListWindowsDlg(CWnd* pParent = NULL);   // standard constructor

	bool m_bShowAll;

	HWND m_hSelectedWindow;

// Dialog Data
	//{{AFX_DATA(CListWindowsDlg)
	enum { IDD = IDD_TOP_LEVEL };
	CListBox	m_Windows;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListWindowsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListWindowsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTWINDOWSDLG_H__CCB91800_2E50_42F2_BB5C_F83DF1CD497B__INCLUDED_)
