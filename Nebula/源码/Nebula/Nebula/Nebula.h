// Nebula.h : main header file for the Nebula application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CNebulaApp:
// See Nebula.cpp for the implementation of this class
//

class CNebulaApp : public CBCGPWinApp
{
public:
	CNebulaApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState ();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNebulaApp theApp;