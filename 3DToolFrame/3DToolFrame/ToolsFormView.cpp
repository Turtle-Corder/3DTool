// ToolsFormView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "3DToolFrame.h"
#include "ToolsFormView.h"


// CToolsFormView

IMPLEMENT_DYNCREATE(CToolsFormView, CFormView)

CToolsFormView::CToolsFormView()
	: CFormView(IDD_TOOLSFORMVIEW)
{

}

CToolsFormView::~CToolsFormView()
{
	if (m_pSheet)
		delete m_pSheet;
}

void CToolsFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CToolsFormView, CFormView)
END_MESSAGE_MAP()


// CToolsFormView 진단입니다.

#ifdef _DEBUG
void CToolsFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CToolsFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CToolsFormView 메시지 처리기입니다.


void CToolsFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CWnd* pWndSheetHolder = GetDlgItem(IDC_SHEET_HOLDER);
	m_pSheet = new CSheet(pWndSheetHolder);
	if (!m_pSheet->Create(pWndSheetHolder, WS_CHILD | WS_VISIBLE, 0))
	{
		delete m_pSheet;
		m_pSheet = nullptr;
		return;
	}

	// fit size
	CRect rcSheet;
	pWndSheetHolder->GetWindowRect(rcSheet);
	m_pSheet->SetWindowPos(NULL, 0, 0, rcSheet.Width(), rcSheet.Height(), SWP_NOZORDER | SWP_NOACTIVATE);

}
