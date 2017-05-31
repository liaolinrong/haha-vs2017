// hahaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "haha.h"
#include "hahaDlg.h"
#include <windows.h>

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
// CHahaDlg dialog

CHahaDlg::CHahaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHahaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHahaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHahaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHahaDlg)
	DDX_Control(pDX, IDC_BUTTON_NOT_LOVE, m_notLoveBtn);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHahaDlg, CDialog)
	//{{AFX_MSG_MAP(CHahaDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NOT_LOVE, OnButtonNotLove)
	ON_BN_CLICKED(IDC_BUTTON_LOVE, OnButtonLove)
	//ON_WM_MOUSEMOVE()
	//ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHahaDlg message handlers

DWORD WINAPI BtnRunThread(LPVOID lpParameter)
{
	CHahaDlg* poHahaDlg = (CHahaDlg*)lpParameter;
	RECT r;
	RECT rDlg;
 	CPoint   point;
	int i = 0;
	unsigned int rd;
	unsigned int rs = 0;
	time_t t;

	CPoint pt1(20,20);
	CPoint pt2(400,20);
	CPoint pt3(20,260);
	CPoint pt4(400,260);
	CPoint pt5(227,119);

	CPoint ap[5] = {pt1, pt2, pt3, pt4, pt5};

	time(&t);
	rs = (unsigned int)t;

	poHahaDlg->GetClientRect(&rDlg);
	CWnd *pWnd;
	pWnd = poHahaDlg->GetDlgItem( IDC_BUTTON_NOT_LOVE );    //获取控件指针，IDC_BUTTON1为控件ID号
	
	while (1)
	{		
		poHahaDlg->m_notLoveBtn.GetWindowRect(&r);
		poHahaDlg->ScreenToClient(&r);

		for (i=0; i<5; i++)
		{
			if (PtInRect(&r, ap[i]))
			{
				break;
			}
		}

		GetCursorPos(&point);
		poHahaDlg->ScreenToClient(&point);
		if (PtInRect(&r,point))
		{			
			do 
			{
				srand(rs);
				rd = ((unsigned int)rand()) % 5;
				rs++;
			} while (rd == i);

			pWnd->SetWindowPos( NULL, ap[rd].x, ap[rd].y, 0, 0, SWP_NOZORDER | SWP_NOSIZE );    //把按钮移到窗口的(50,80)处
		}

		Sleep(1);
	}
	

	return 0;
}


BOOL CHahaDlg::OnInitDialog()
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


	CreateThread(NULL, 0, BtnRunThread, this, 0, NULL);
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHahaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHahaDlg::OnPaint() 
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
HCURSOR CHahaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHahaDlg::OnButtonNotLove() 
{
	// TODO: Add your control notification handler code here
	
}

void CHahaDlg::OnButtonLove() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("恭喜你，回答正确！^_^");
}

// void CHahaDlg::OnMouseMove(UINT nFlags, CPoint point) 
// {
// 	// TODO: Add your message handler code here and/or call default
// 	
// 	CDialog::OnMouseMove(nFlags, point);
// }

// void CHahaDlg::OnMove(int x, int y) 
// {
// 	CDialog::OnMove(x, y);
// 	
// }
