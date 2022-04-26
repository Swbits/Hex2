// hex2.h : main header file for the HEX2 application
//

#if !defined(AFX_TEST2_H__C96E5011_698D_4542_8709_22897178A18F__INCLUDED_)
#define AFX_TEST2_H__C96E5011_698D_4542_8709_22897178A18F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHex2App:
// See hex2.cpp for the implementation of this class
//

class CHex2App : public CWinApp
{
public:
	CHex2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHex2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHex2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2_H__C96E5011_698D_4542_8709_22897178A18F__INCLUDED_)
