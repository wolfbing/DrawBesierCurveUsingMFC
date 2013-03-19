// PaintTestDoc.cpp : implementation of the CPaintTestDoc class
//

#include "stdafx.h"
#include "PaintTest.h"

#include "PaintTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintTestDoc

IMPLEMENT_DYNCREATE(CPaintTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaintTestDoc, CDocument)
	//{{AFX_MSG_MAP(CPaintTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintTestDoc construction/destruction

CPaintTestDoc::CPaintTestDoc()
{
	// TODO: add one-time construction code here
	p1=new CPoint(50,50);
	p2=new CPoint(60,60);
}

CPaintTestDoc::~CPaintTestDoc()
{
}

BOOL CPaintTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPaintTestDoc serialization

void CPaintTestDoc::Serialize(CArchive& ar)
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
// CPaintTestDoc diagnostics

#ifdef _DEBUG
void CPaintTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaintTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintTestDoc commands
