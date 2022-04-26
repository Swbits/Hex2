// hex2Dlg.h : header file
//

#if !defined(AFX_TEST2DLG_H__84B3C087_A77A_414A_A5FF_FEA1BE1F572E__INCLUDED_)
#define AFX_TEST2DLG_H__84B3C087_A77A_414A_A5FF_FEA1BE1F572E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHex2Dlg dialog

class CHex2Dlg : public CDialog
{
// Construction
public:
	void dispDiffNum(int x,int y,int num1,int num2,int foot);
	CHex2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHex2Dlg)
	enum { IDD = IDD_TEST2_DIALOG };
	CEdit	mEdHex2;
	CEdit	mEdHex1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHex2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHex2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeEdithex1();
	afx_msg void OnChangeEdithex2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2DLG_H__84B3C087_A77A_414A_A5FF_FEA1BE1F572E__INCLUDED_)
