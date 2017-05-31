// haha.h : main header file for the HAHA application
//

#if !defined(AFX_HAHA_H__ACFF078A_FABB_420B_8E77_CC791E9ACA8A__INCLUDED_)
#define AFX_HAHA_H__ACFF078A_FABB_420B_8E77_CC791E9ACA8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHahaApp:
// See haha.cpp for the implementation of this class
//

class CHahaApp : public CWinApp
{
public:
	CHahaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHahaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHahaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAHA_H__ACFF078A_FABB_420B_8E77_CC791E9ACA8A__INCLUDED_)
