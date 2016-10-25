// NebulaDoc.h : interface of the CNebulaDoc class
//


#pragma once


class CNebulaDoc : public CDocument
{
protected: // create from serialization only
	CNebulaDoc();
	DECLARE_DYNCREATE(CNebulaDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CNebulaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


