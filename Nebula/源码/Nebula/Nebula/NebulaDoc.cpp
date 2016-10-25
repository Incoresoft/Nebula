// NebulaDoc.cpp : implementation of the CNebulaDoc class
//

#include "stdafx.h"
#include "Nebula.h"

#include "NebulaDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNebulaDoc

IMPLEMENT_DYNCREATE(CNebulaDoc, CDocument)

BEGIN_MESSAGE_MAP(CNebulaDoc, CDocument)
END_MESSAGE_MAP()


// CNebulaDoc construction/destruction

CNebulaDoc::CNebulaDoc()
{
	// TODO: add one-time construction code here

}

CNebulaDoc::~CNebulaDoc()
{
}

BOOL CNebulaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CNebulaDoc serialization

void CNebulaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CNebulaDoc diagnostics

#ifdef _DEBUG
void CNebulaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNebulaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNebulaDoc commands
