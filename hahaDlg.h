// hahaDlg.h : header file
//

#if !defined(AFX_HAHADLG_H__9601E760_D227_45B5_921D_268EA5BE2993__INCLUDED_)
#define AFX_HAHADLG_H__9601E760_D227_45B5_921D_268EA5BE2993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHahaDlg dialog

class CHahaDlg : public CDialog
{
// Construction
public:
	CHahaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHahaDlg)
	enum { IDD = IDD_HAHA_DIALOG };
	CButton	m_notLoveBtn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHahaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHahaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonNotLove();
	afx_msg void OnButtonLove();
// 	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
// 	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAHADLG_H__9601E760_D227_45B5_921D_268EA5BE2993__INCLUDED_)
