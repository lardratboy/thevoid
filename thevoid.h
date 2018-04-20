// thevoid.h : main header file for the THEVOID application
//

#if !defined(AFX_THEVOID_H__CF208414_B867_4EB4_84C7_A76B0C4E00DA__INCLUDED_)
#define AFX_THEVOID_H__CF208414_B867_4EB4_84C7_A76B0C4E00DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CThevoidApp:
// See thevoid.cpp for the implementation of this class
//

class CThevoidApp : public CWinApp
{
public:

	bool m_bCloseCapturedOnViewClose;
	bool m_bShowAllWindows;

	CThevoidApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThevoidApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CThevoidApp)
	afx_msg void OnAppAbout();
	afx_msg void OnCloseCapturedOnClose();
	afx_msg void OnUpdateCloseCapturedOnClose(CCmdUI* pCmdUI);
	afx_msg void OnShowAll();
	afx_msg void OnUpdateShowAll(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEVOID_H__CF208414_B867_4EB4_84C7_A76B0C4E00DA__INCLUDED_)
