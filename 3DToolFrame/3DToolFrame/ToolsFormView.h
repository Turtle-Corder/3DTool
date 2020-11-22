#pragma once



// CToolsFormView 폼 뷰입니다.

#include "Sheet.h"

class CToolsFormView : public CFormView
{
	DECLARE_DYNCREATE(CToolsFormView)

public:
	CSheet* m_pSheet = nullptr;

protected:
	CToolsFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


