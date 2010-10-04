// pgMFC.h : main header file for the PGMFC application
//

#if !defined(AFX_PGMFC_H__DFEB4517_B4DB_44AF_854C_43A7C09A9FDD__INCLUDED_)
#define AFX_PGMFC_H__DFEB4517_B4DB_44AF_854C_43A7C09A9FDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPgMFCApp:
// See pgMFC.cpp for the implementation of this class
//

class CPgMFCApp : public CWinApp
{
public:
	CPgMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPgMFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPgMFCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PGMFC_H__DFEB4517_B4DB_44AF_854C_43A7C09A9FDD__INCLUDED_)
