#pragma once



// CSheet

#include "Page_Terrain.h"
#include "Page_Mesh.h"


class CSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSheet)

public:
	CPage_Terrain	m_clPgTerrain;
	CPage_Mesh		m_clPgMesh;

public:
	CSheet(CWnd* pParentWnd = NULL);
	CSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSheet();

protected:
	DECLARE_MESSAGE_MAP()
};


