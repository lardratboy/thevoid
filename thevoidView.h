// thevoidView.h : interface of the CThevoidView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEVOIDVIEW_H__FEABAE57_A37D_45A6_BE73_FB07F241D2C4__INCLUDED_)
#define AFX_THEVOIDVIEW_H__FEABAE57_A37D_45A6_BE73_FB07F241D2C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CThevoidView : public CView
{

protected: // create from serialization only

	CThevoidView();
	DECLARE_DYNCREATE(CThevoidView)

// Attributes
public:

	CThevoidDoc* GetDocument();

	HWND m_hwndCaptured;

	DWORD m_dwStyle;

	DWORD m_dwExStyle;

	void ReleaseWindow();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThevoidView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CThevoidView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CThevoidView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in thevoidView.cpp
inline CThevoidDoc* CThevoidView::GetDocument()
   { return (CThevoidDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEVOIDVIEW_H__FEABAE57_A37D_45A6_BE73_FB07F241D2C4__INCLUDED_)
