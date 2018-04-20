// thevoidDoc.cpp : implementation of the CThevoidDoc class
//

#include "stdafx.h"
#include "thevoid.h"

#include "thevoidDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThevoidDoc

IMPLEMENT_DYNCREATE(CThevoidDoc, CDocument)

BEGIN_MESSAGE_MAP(CThevoidDoc, CDocument)
	//{{AFX_MSG_MAP(CThevoidDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThevoidDoc construction/destruction

CThevoidDoc::CThevoidDoc()
{
	// TODO: add one-time construction code here

}

CThevoidDoc::~CThevoidDoc()
{
}

BOOL CThevoidDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CThevoidDoc serialization

void CThevoidDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CThevoidDoc diagnostics

#ifdef _DEBUG
void CThevoidDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThevoidDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
