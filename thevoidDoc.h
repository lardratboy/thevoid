// thevoidDoc.h : interface of the CThevoidDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEVOIDDOC_H__9BD58EB5_38F8_4A7B_B3BB_97803B6FAB43__INCLUDED_)
#define AFX_THEVOIDDOC_H__9BD58EB5_38F8_4A7B_B3BB_97803B6FAB43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CThevoidDoc : public CDocument
{
protected: // create from serialization only
	CThevoidDoc();
	DECLARE_DYNCREATE(CThevoidDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThevoidDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CThevoidDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CThevoidDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEVOIDDOC_H__9BD58EB5_38F8_4A7B_B3BB_97803B6FAB43__INCLUDED_)
