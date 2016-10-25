#pragma once

// BackStagePageInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackStagePageInfo dialog

class CBackStagePageInfo : public CBCGPDialog
{
	DECLARE_DYNCREATE(CBackStagePageInfo)

// Construction
public:
	CBackStagePageInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBackStagePageInfo)
	enum { IDD = IDD_FORM_INFO };
	CBCGPButton	m_btnPreview;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackStagePageInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBackStagePageInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnPreview();
	//}}AFX_MSG
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

	void OnDraw(CDC* pDC);
	void PreparePreviewBitmap();

	CString	m_strDocName;
	CString	m_strPath;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

