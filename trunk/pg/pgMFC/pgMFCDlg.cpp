// pgMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pgMFC.h"
#include "pgMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPgMFCDlg dialog

CPgMFCDlg::CPgMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPgMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPgMFCDlg)
	m_result = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPgMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPgMFCDlg)
	DDX_Control(pDX, IDC_BUTTON2, m_sql);
	DDX_Control(pDX, IDC_EDIT6, m_gid);
	DDX_Control(pDX, IDC_EDIT5, m_pwd);
	DDX_Control(pDX, IDC_EDIT4, m_user);
	DDX_Control(pDX, IDC_EDIT3, m_db);
	DDX_Control(pDX, IDC_EDIT2, m_port);
	DDX_Control(pDX, IDC_EDIT1, m_host);
	DDX_Control(pDX, IDC_EDIT7, m_info_cedit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPgMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CPgMFCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPgMFCDlg message handlers

BOOL CPgMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_host.SetWindowText("localhost");
	m_port.SetWindowText("5432");
	m_db.SetWindowText("postgis");
	m_user.SetWindowText("postgres");
	m_pwd.SetWindowText("osgis");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPgMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPgMFCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPgMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPgMFCDlg::QueryString()
{
	char host[20];
	char port[20];
	char dbname[20];
	char user[20];
	char pword[20];
	//char querystring[100];
	m_host.GetWindowText(host, 20);
	m_port.GetWindowText(port, 20);
	m_db.GetWindowText(dbname, 20);
	m_user.GetWindowText(user, 20);
	m_pwd.GetWindowText(pword, 20);

	strcpy(querystring, "");
	strcat(querystring, "host=");
	strcat(querystring, host);
	strcat(querystring, " port=");
	strcat(querystring, port);
	strcat(querystring, " dbname=");
	strcat(querystring, dbname);
	strcat(querystring, " user=");
	strcat(querystring, user);
	strcat(querystring, " password=");
	strcat(querystring, pword);
}
void CPgMFCDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	PGconn *conn;
	QueryString();
	conn = PQconnectdb(querystring);
	if(PQstatus(conn) == CONNECTION_BAD){
		m_info_cedit.SetWindowText("connection error");
		m_sql.EnableWindow(false);
	}
	else
	{
		m_info_cedit.SetWindowText("connection successful");
		m_sql.EnableWindow(true);
	}
	
}

void CPgMFCDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	PGconn *conn;
	PGresult *res;
	char qstring[100];
	char id[20];
	char qresult[200];

	QueryString();

	conn = PQconnectdb(querystring);
	if(PQstatus(conn) == CONNECTION_BAD)
		m_info_cedit.SetWindowText("connection error");
	else
		m_info_cedit.SetWindowText("connection successful");

	PQsetClientEncoding(conn, "gbk");

	strcpy(qstring, "");
	strcat(qstring, "SELECT gid, pinyin,cityname,st_astext(the_geom) FROM cities WHERE gid =");
	m_gid.GetWindowText(id, 20);
	strcat(qstring, id);

	res = PQexec(conn,qstring);
	if(PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		m_info_cedit.SetWindowText("Query fail!");			
	}
	strcpy(qresult, "");
	if(PQntuples(res)==0)
		m_info_cedit.SetWindowText("Query not result!");
	else//m_info_cedit.SetWindowText("cities information gid pinyin name lonlat:");
	{
		for(int i=0;i<PQntuples(res);i++)
		{
 			strcat(qresult, PQgetvalue(res,i,0));
			strcat(qresult, " ");
 			strcat(qresult, PQgetvalue(res,i,1));
			strcat(qresult, " ");
 			strcat(qresult, PQgetvalue(res,i,2));
			strcat(qresult, " ");
 			strcat(qresult, PQgetvalue(res,i,3));
		}
		m_info_cedit.SetWindowText(qresult);
	}
	PQclear(res);
	PQfinish(conn);
}
