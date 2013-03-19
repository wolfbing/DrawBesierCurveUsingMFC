// PaintTestDoc.h : interface of the CPaintTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINTTESTDOC_H__0607A81B_427C_4577_BD00_68A658252584__INCLUDED_)
#define AFX_PAINTTESTDOC_H__0607A81B_427C_4577_BD00_68A658252584__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using namespace std;


class CPaintTestDoc : public CDocument
{
protected: // create from serialization only
	CPaintTestDoc();
	DECLARE_DYNCREATE(CPaintTestDoc)

// Attributes
public:
	CPoint * p1;
	CPoint * p2;
	vector<CPoint> points;
	double t;
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPaintTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaintTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTTESTDOC_H__0607A81B_427C_4577_BD00_68A658252584__INCLUDED_)
