#if !defined(AFX_INPUTDLG_H__6C6120C8_35DA_474F_9066_37AB436BEA57__INCLUDED_)
#define AFX_INPUTDLG_H__6C6120C8_35DA_474F_9066_37AB436BEA57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputDlg dialog

class InputDlg : public CDialog
{
// Construction
public:
	InputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputDlg)
	enum { IDD = IDD_DIALOG_T };
	CString	m_T;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	double t;
	CString s;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__6C6120C8_35DA_474F_9066_37AB436BEA57__INCLUDED_)
