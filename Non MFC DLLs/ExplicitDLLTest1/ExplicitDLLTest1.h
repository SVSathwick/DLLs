
// ExplicitDLLTest1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExplicitDLLTest1App:
// See ExplicitDLLTest1.cpp for the implementation of this class
//

class CExplicitDLLTest1App : public CWinApp
{
public:
	CExplicitDLLTest1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CExplicitDLLTest1App theApp;
