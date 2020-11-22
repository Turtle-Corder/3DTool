
// 3DToolFrameView.cpp : CMy3DToolFrameView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "3DToolFrame.h"
#endif

#include "MainFrm.h"
#include "3DToolFrameDoc.h"
#include "3DToolFrameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3DToolFrameView
HWND g_hWnd = nullptr;

IMPLEMENT_DYNCREATE(CMy3DToolFrameView, CView)

BEGIN_MESSAGE_MAP(CMy3DToolFrameView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3DToolFrameView 생성/소멸

CMy3DToolFrameView::CMy3DToolFrameView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy3DToolFrameView::~CMy3DToolFrameView()
{
}

BOOL CMy3DToolFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy3DToolFrameView 그리기

void CMy3DToolFrameView::OnDraw(CDC* /*pDC*/)
{
	CMy3DToolFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy3DToolFrameView 인쇄

BOOL CMy3DToolFrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy3DToolFrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy3DToolFrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy3DToolFrameView 진단

#ifdef _DEBUG
void CMy3DToolFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3DToolFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3DToolFrameDoc* CMy3DToolFrameView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3DToolFrameDoc)));
	return (CMy3DToolFrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy3DToolFrameView 메시지 처리기


void CMy3DToolFrameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	g_hWnd = m_hWnd;

	//--------------------------------------------------
	// TODO : Device Setup
	//--------------------------------------------------


	//--------------------------------------------------
	// TODO : Resources Load
	//--------------------------------------------------


	//--------------------------------------------------
	// Windows Resizing
	//--------------------------------------------------
	CMainFrame* pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	RECT rcMain = {};
	RECT rcView = {};

	pMainFrm->GetWindowRect(&rcMain);
	SetRect(&rcMain, 0, 0, rcMain.right - rcMain.left, rcMain.bottom - rcMain.top);

	GetClientRect(&rcView);

	int iWidth = rcMain.right - rcView.right;
	int iHeight = rcMain.bottom - rcView.bottom;

	pMainFrm->SetWindowPos(nullptr, 0, 0, TOOLCX + iWidth, TOOLCY + iHeight, SWP_NOZORDER);
}


void CMy3DToolFrameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
}
