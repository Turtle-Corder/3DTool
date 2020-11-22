#pragma once



// CToolsFormView �� ���Դϴ�.

#include "Sheet.h"

class CToolsFormView : public CFormView
{
	DECLARE_DYNCREATE(CToolsFormView)

public:
	CSheet* m_pSheet = nullptr;

protected:
	CToolsFormView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CToolsFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOOLSFORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


