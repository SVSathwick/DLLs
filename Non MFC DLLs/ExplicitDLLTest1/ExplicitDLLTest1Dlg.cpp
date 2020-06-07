
// ExplicitDLLTest1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ExplicitDLLTest1.h"
#include "ExplicitDLLTest1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef double (*LPGETNUMBER)(double Nbr);
HINSTANCE hDLL = NULL;
LPGETNUMBER lpGetNumber;

typedef int (*LPADDANDSQUARE)(int x, int y);
HINSTANCE hDLL2 = NULL;
LPADDANDSQUARE lpAddAndSquare;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExplicitDLLTest1Dlg dialog



CExplicitDLLTest1Dlg::CExplicitDLLTest1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXPLICITDLLTEST1_DIALOG, pParent)
	, m_GetNumber(_T(""))
	, m_Number(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplicitDLLTest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_GETNUMBER, m_GetNumber);
	DDX_Text(pDX, IDC_NUMBER, m_Number);
}

BEGIN_MESSAGE_MAP(CExplicitDLLTest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_NUMBER_BTN, &CExplicitDLLTest1Dlg::OnClickedGetNumberBtn)
END_MESSAGE_MAP()


// CExplicitDLLTest1Dlg message handlers

BOOL CExplicitDLLTest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	hDLL = LoadLibrary(L"ExplicitDLL1");

	if (hDLL == NULL)
		MessageBox(L"Could not load the DLL", L"Hi", MB_OK);
	else
	{
		lpGetNumber = (LPGETNUMBER)GetProcAddress(hDLL, "GetNumber");
	}

	hDLL2 = LoadLibrary(L"MathLibrary");

	if (hDLL2 == NULL)
		MessageBox(L"Could not load the DLL2", L"Hi", MB_OK);
	else
	{
		lpAddAndSquare = (LPADDANDSQUARE)GetProcAddress(hDLL2, "addAndSquare");
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExplicitDLLTest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExplicitDLLTest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExplicitDLLTest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExplicitDLLTest1Dlg::OnClickedGetNumberBtn()
{
	double Number, GetNbr;
	UpdateData();

	if (hDLL == NULL)
	{
		MessageBox(L"Could not find the DLL", L"Hi", MB_OK);
		return;
	}

	Number = 10;// atof(m_Number);
	GetNbr = lpGetNumber(Number);
	char message[100];
	sprintf_s(message, 100, "Result: %f", GetNbr);	
	MessageBoxA(NULL, message, "Hello", MB_OK);

	if (hDLL2 == NULL)
	{
		MessageBox(L"Could not find the Math Library", L"Hi", MB_OK);
		return;
	}

	/*int val1 = 3, val2 = 4;
	int result = (lpAddAndSquare)(val1, val2);
	sprintf_s(message, 100, "AddAndSquare of %d and %d is %d", val1, val2, result);
	MessageBoxA(NULL, message, "Hello", MB_OK);*/

	UpdateData(FALSE);
}
