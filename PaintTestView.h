// PaintTestView.h : interface of the CPaintTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTTESTVIEW_H__FCE41AB7_ECFA_4095_9F71_072F706AAE5F__INCLUDED_)
#define AFX_PAINTTESTVIEW_H__FCE41AB7_ECFA_4095_9F71_072F706AAE5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "InputDlg.h"


class CPaintTestView : public CView
{
protected: // create from serialization only
	CPaintTestView();
	DECLARE_DYNCREATE(CPaintTestView)

// Attributes
public:
	CPaintTestDoc* GetDocument();

// Operations
public:
	CPoint GetBezierPoint(double t,vector<CPoint> p);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaintTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaintTestView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenuT();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

#ifndef _DEBUG  // debug version in PaintTestView.cpp
inline CPaintTestDoc* CPaintTestView::GetDocument()
   { return (CPaintTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTTESTVIEW_H__FCE41AB7_ECFA_4095_9F71_072F706AAE5F__INCLUDED_)
