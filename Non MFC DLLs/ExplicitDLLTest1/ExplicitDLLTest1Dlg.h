
// ExplicitDLLTest1Dlg.h : header file
//

#pragma once


// CExplicitDLLTest1Dlg dialog
class CExplicitDLLTest1Dlg : public CDialogEx
{
// Construction
public:
	CExplicitDLLTest1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPLICITDLLTEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_GetNumber;
	CString m_Number;
	afx_msg void OnClickedGetNumberBtn();
};
