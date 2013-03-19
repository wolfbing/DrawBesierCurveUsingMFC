// PaintTestView.cpp : implementation of the CPaintTestView class
//

#include "stdafx.h"
#include "PaintTest.h"

#include "PaintTestDoc.h"
#include "PaintTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView

IMPLEMENT_DYNCREATE(CPaintTestView, CView)

BEGIN_MESSAGE_MAP(CPaintTestView, CView)
	//{{AFX_MSG_MAP(CPaintTestView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_MENU_T, OnMenuT)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView construction/destruction

CPaintTestView::CPaintTestView()
{
	// TODO: add construction code here

}

CPaintTestView::~CPaintTestView()
{
}

BOOL CPaintTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView drawing

void CPaintTestView::OnDraw(CDC* pDC)
{
	CPaintTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*
	if (!pDoc)
	{
		return ;
	}
	CRect rect;
	this->GetClientRect(rect);
	pDC->Ellipse(rect);
	*/
}

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView printing

BOOL CPaintTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView diagnostics

#ifdef _DEBUG
void CPaintTestView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintTestDoc* CPaintTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintTestDoc)));
	return (CPaintTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintTestView message handlers

void CPaintTestView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages

}

void CPaintTestView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPaintTestDoc * doc = GetDocument();
	doc->points.push_back(point);

	Invalidate();
	UpdateWindow();
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,0,0));
	for (vector<CPoint>::iterator ite=doc->points.begin();ite!=doc->points.end();++ite)
	{
		dc.FillRect(CRect(ite->x-3,ite->y-3,ite->x+3,ite->y+3),&brush);
	}
	
	vector<CPoint> p;
	CPen pen;
	CPen *oldpen;
	pen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	oldpen=dc.SelectObject(&pen);
	
	if (doc->points.size()>1)
	{
		//p.push_back(doc->points[0]);
		for (double t=0;t<=1;t+=0.001)
		{
			p.push_back(GetBezierPoint(t,doc->points));
		}

		//p.push_back(doc->points[doc->points.size()-1]);

		for (int j=0;j<p.size()-1;++j)
		{
			dc.MoveTo(p[j]);
			dc.LineTo(p[j+1]);
		}
	}
	/*
	for (int i=0;i<doc->points.size()-1;++i)
	{
		dc.MoveTo(doc->points[i]);
		dc.LineTo(doc->points[i+1]);
	}
	*/

	CView::OnLButtonDown(nFlags, point);
}


typedef struct TP
{
	double x;
	double y;
}TmpPoint;


CPoint CPaintTestView::GetBezierPoint(double t,vector<CPoint> points)
{
	vector<TmpPoint> tmps;
	for (int j=0;j<points.size();++j)
	{
		TmpPoint t=* new TmpPoint();
		t.x=points[j].x;
		t.y=points[j].y;
		tmps.push_back(t);
	}

	while (tmps.size() > 1)
	{
		for (int i=0;i<tmps.size()-1;i++)
		{
			tmps[i].x=(1.0-t)*tmps[i].x+t*tmps[i+1].x;
			tmps[i].y=(1.0-t)*tmps[i].y+t*tmps[i+1].y;
		}
		tmps.pop_back();
	}
	return CPoint(int(tmps[0].x),int(tmps[0].y));
}

void CPaintTestView::OnMenuT() 
{
	// TODO: Add your command handler code here
	//MessageBox(_T("here"),_T(""),MB_ICONQUESTION);
	CPaintTestDoc * doc=GetDocument();
	InputDlg dlg;
	dlg.DoModal();
	//CString str;
	//str.Format(_T("%s"),dlg.s);
	//MessageBox(str);
	//CPaintTestDoc doc=GetDocument();
	//doc
	double t=dlg.t;
	CClientDC dc(this);
	CPoint p=GetBezierPoint(t,doc->points);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,0,255));
	dc.FillRect(CRect(p.x-3,p.y-3,p.x+3,p.y+3),&brush);
}
