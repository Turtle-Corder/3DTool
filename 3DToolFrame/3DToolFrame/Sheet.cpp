// Sheet.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "3DToolFrame.h"
#include "Sheet.h"


// CSheet

IMPLEMENT_DYNAMIC(CSheet, CPropertySheet)

CSheet::CSheet(CWnd * pParentWnd)
	:CPropertySheet(AFX_IDS_APP_TITLE, pParentWnd)
{
	CPropertySheet::AddPage(&m_clPgTerrain);
	CPropertySheet::AddPage(&m_clPgMesh);
}

CSheet::CSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	CPropertySheet::AddPage(&m_clPgTerrain);
	CPropertySheet::AddPage(&m_clPgMesh);
}

CSheet::CSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	CPropertySheet::AddPage(&m_clPgTerrain);
	CPropertySheet::AddPage(&m_clPgMesh);
}

CSheet::~CSheet()
{

}


BEGIN_MESSAGE_MAP(CSheet, CPropertySheet)
END_MESSAGE_MAP()


// CSheet 메시지 처리기입니다.
