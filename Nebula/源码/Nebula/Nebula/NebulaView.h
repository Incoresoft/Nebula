// NebulaView.h : interface of the CNebulaView class
//


#pragma once


class CNebulaView : public CView
{
protected: // create from serialization only
	CNebulaView();
	DECLARE_DYNCREATE(CNebulaView)

// Attributes
public:
	CNebulaDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CNebulaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnFilePrintPreview();
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()

	void EnsureGraphicsManager();
	CBCGPGraphicsManager* m_pGM;
};

#ifndef _DEBUG  // debug version in NebulaView.cpp
inline CNebulaDoc* CNebulaView::GetDocument() const
   { return reinterpret_cast<CNebulaDoc*>(m_pDocument); }
#endif

