// hex2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "hex2.h"
#include "hex2Dlg.h"

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
// CHex2Dlg dialog

CHex2Dlg::CHex2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHex2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHex2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHex2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHex2Dlg)
	DDX_Control(pDX, IDC_EDITHEX2, mEdHex2);
	DDX_Control(pDX, IDC_EDITHEX1, mEdHex1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHex2Dlg, CDialog)
	//{{AFX_MSG_MAP(CHex2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDITHEX1, OnChangeEdithex1)
	ON_EN_CHANGE(IDC_EDITHEX2, OnChangeEdithex2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHex2Dlg message handlers

BOOL CHex2Dlg::OnInitDialog()
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
	OnChangeEdithex2();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHex2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHex2Dlg::OnPaint() 
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
		OnChangeEdithex1();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHex2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


char * firstNonSpace(char *p)
{
	while(*p)
	{
		if( !isspace(*p) )
			return p;
		p++;
	}
	return NULL;
}

unsigned long str2num(char * str)
{
	char   *string, *stopstring;
	unsigned long val=0;

	string = firstNonSpace(str);
	if(string == NULL ) {
		return 0;
	}
	
	int len = strlen(string);
	
	if( len )  {
		if( string[1] == 'X' || string[len-1] == 'H' ||
			string[1] == 'x' || string[len-1] == 'h' ) {
			val = strtoul( string, &stopstring, 16 );
		}
		else {
			val = atoi(string);
		}
	}
	return val;
}


void CHex2Dlg::OnChangeEdithex1() 
{
	char buf[256];
	int num1,num2;

	mEdHex1.GetWindowText(buf,sizeof(buf));
	num1 = str2num(buf);

	mEdHex2.GetWindowText(buf,sizeof(buf));
	num2 = str2num(buf);

	dispDiffNum(0,30,num1,num2,0);
	dispDiffNum(0,70,num2,num1,1);

	
	sprintf(buf,"0x%08x (%d)",num1,num1);
	SetDlgItemText(IDC_ST_NUM1,buf);
}

void CHex2Dlg::OnChangeEdithex2() 
{
	char buf[256];
	int num1,num2;

	mEdHex1.GetWindowText(buf,sizeof(buf));
	num1 = str2num(buf);

	mEdHex2.GetWindowText(buf,sizeof(buf));
	num2 = str2num(buf);

	dispDiffNum(0,30,num1,num2,0);
	dispDiffNum(0,70,num2,num1,1);

	sprintf(buf,"0x%08x (%d)",num2,num2);
	SetDlgItemText(IDC_ST_NUM2,buf);
}

void CHex2Dlg::dispDiffNum(int x, int y, int num1, int num2,int foot)
{
#define CHAR_WIDTH 10
#define CHAR_HEIGHT 20
	
	char hexbuf2[256];
	CRect dlgRect;
	COLORREF crRed = RGB(255,0,0);
	COLORREF crRed1 = RGB(255,128,0);
	COLORREF crWhite = RGB(255,255,255);
	COLORREF crBlue1 = RGB(128,255,255);
	COLORREF cl;
	COLORREF bkCr = GetSysColor(COLOR_BTNFACE);


	int i,t;
	char * pStr;

	CDC * pDC = GetDC();
	this->GetClientRect( &dlgRect);

	x += dlgRect.Width() - (CHAR_WIDTH*2);

	t = num1;
	for(i=0;i<32;i++) {

		if( ((num1 >> i) & 1) == ((num2 >> i) & 1) ) {
			cl = crWhite;
		}
		else {
			cl = crRed;
		}
		
		if( t & 1 ) {
			pStr = "1";
		}
		else {
			pStr = "0";
		}

		pDC->SetBkColor(cl);
		pDC->TextOut(x,y,pStr);
	
		if(i%4 == 0) {
			if( ((num1 >> i) & 0xf) == ((num2 >> i) & 0xf) ) {
				cl = crBlue1;
			}
			else {
				cl = crRed1;
			}

			pDC->SetBkColor(bkCr);
			pDC->TextOut(x-CHAR_WIDTH-CHAR_WIDTH/2,y-CHAR_HEIGHT,"   ");

			if( foot ) {
CFont font;
VERIFY(font.CreatePointFont(90, _T("Arial"), pDC));
// Use the font you just created.
CFont* def_font = pDC->SelectObject(&font);

				sprintf(hexbuf2,"%d",i);
				pDC->TextOut(x- ( i < 10 ? 0 : CHAR_WIDTH/2)+1,y+CHAR_HEIGHT,hexbuf2);


pDC->SelectObject(def_font);
// Finished with the font, now delete the font object.
font.DeleteObject();

			}

			pDC->SetBkColor(cl);
			sprintf(hexbuf2,"%X",(num1>>i)&0xf);
			pDC->TextOut(x-CHAR_WIDTH-CHAR_WIDTH/2,y-CHAR_HEIGHT,hexbuf2);
		}

		x -= CHAR_WIDTH;
		if(i%4 == 3) {
			x -= 4;
		}

		if(i%8 == 7) {
			x -= 4;
		}

		if(i%16 == 15) {
			x -= 4;
		}

        t = t >> 1;
	}


}
