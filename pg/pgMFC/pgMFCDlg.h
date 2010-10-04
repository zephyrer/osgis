// pgMFCDlg.h : header file
//

#if !defined(AFX_PGMFCDLG_H__E0846DF0_8766_489C_A013_9AB5DC0C8757__INCLUDED_)
#define AFX_PGMFCDLG_H__E0846DF0_8766_489C_A013_9AB5DC0C8757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPgMFCDlg dialog

class CPgMFCDlg : public CDialog
{
// Construction
public:
	CPgMFCDlg(CWnd* pParent = NULL);	// standard constructor
	void QueryString();
// Dialog Data
	//{{AFX_DATA(CPgMFCDlg)
	enum { IDD = IDD_PGMFC_DIALOG };
	CButton	m_sql;
	CEdit	m_gid;
	CEdit	m_pwd;
	CEdit	m_user;
	CEdit	m_db;
	CEdit	m_port;
	CEdit	m_host;
	CEdit	m_info_cedit;
	CString	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPgMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	char querystring[100];

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPgMFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGMFCDLG_H__E0846DF0_8766_489C_A013_9AB5DC0C8757__INCLUDED_)
