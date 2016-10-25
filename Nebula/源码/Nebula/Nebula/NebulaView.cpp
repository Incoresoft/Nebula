// NebulaView.cpp : implementation of the CNebulaView class
//

#include "stdafx.h"
#include "Nebula.h"

#include "NebulaDoc.h"
#include "NebulaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNebulaView

IMPLEMENT_DYNCREATE(CNebulaView, CView)

BEGIN_MESSAGE_MAP(CNebulaView, CView)
	ON_WM_ERASEBKGND()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_MESSAGE(WM_PRINTCLIENT, OnPrintClient)
END_MESSAGE_MAP()

// CNebulaView construction/destruction

CNebulaView::CNebulaView()
{
	m_pGM = NULL;

	// TODO: add construction code here

}

CNebulaView::~CNebulaView()
{
	if (m_pGM != NULL)
	{
		delete m_pGM;
	}
}

void CNebulaView::EnsureGraphicsManager()
{
	if (m_pGM == NULL)
	{
		m_pGM = CBCGPGraphicsManager::CreateInstance();
	}
}

BOOL CNebulaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNebulaView drawing

void CNebulaView::OnDraw(CDC* pDC)
{
	CNebulaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	EnsureGraphicsManager();
	if (m_pGM == NULL)
	{
		return;
	}

	if (pDC->GetWindow() == NULL)
	{
		CRect rectClient;
		GetClientRect(&rectClient);

		m_pGM->BindDC(pDC, rectClient);
	}
	else
	{
		m_pGM->BindDC(pDC);
	}

	if (!m_pGM->BeginDraw())
	{
		return;
	}

	m_pGM->Clear();

	CRect rectDraw;
	if (pDC->IsPrinting() && m_pGM->GetPrintInfo() != NULL)
	{
		rectDraw = m_pGM->GetPrintInfo()->m_rectDraw;
	}
	else
	{
		GetClientRect(rectDraw);
	}

	// TODO: add calls to CBCGPGraphicsManager drawing methods here (e.g, m_pGM->FillRectangle(...);)

	m_pGM->EndDraw();
}


// CNebulaView printing

void CNebulaView::OnFilePrintPreview()
{
	BCGPPrintPreview (this);
}

BOOL CNebulaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNebulaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
	EnsureGraphicsManager();
	if (m_pGM != NULL)
	{
		m_pGM->SetPrintInfo(pInfo);
	}
	// TODO: add extra initialization before printing
}

void CNebulaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	if (m_pGM != NULL)
	{
		m_pGM->SetPrintInfo(NULL);
	}
	// TODO: add cleanup after printing
}


// CNebulaView diagnostics

#ifdef _DEBUG
void CNebulaView::AssertValid() const
{
	CView::AssertValid();
}

void CNebulaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNebulaDoc* CNebulaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNebulaDoc)));
	return (CNebulaDoc*)m_pDocument;
}
#endif //_DEBUG


// CNebulaView message handlers

BOOL CNebulaView::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;
}

LRESULT CNebulaView::OnPrintClient(WPARAM wp, LPARAM lp)
{
	if ((lp & PRF_CLIENT) == PRF_CLIENT)
	{
		CDC* pDC = CDC::FromHandle((HDC) wp);
		ASSERT_VALID(pDC);
		
		OnDraw(pDC);
	}
	
	return 0;
}

