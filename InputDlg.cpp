// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PaintTest.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputDlg dialog


InputDlg::InputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputDlg)
	m_T = _T("");
	//}}AFX_DATA_INIT
}


void InputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputDlg)
	DDX_Text(pDX, IDC_EDIT_T, m_T);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InputDlg, CDialog)
	//{{AFX_MSG_MAP(InputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputDlg message handlers

void InputDlg::OnOK() 
{
	// TODO: Add extra validation here
	//t=atof(this->m_T);
	//s=this->m_T;
	GetDlgItemText(IDC_EDIT_T,s); 
	t=atof(s);
	CDialog::OnOK();
}
