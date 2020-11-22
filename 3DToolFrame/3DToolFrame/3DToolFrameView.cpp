
// 3DToolFrameView.cpp : CMy3DToolFrameView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy3DToolFrameView ����/�Ҹ�

CMy3DToolFrameView::CMy3DToolFrameView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy3DToolFrameView::~CMy3DToolFrameView()
{
}

BOOL CMy3DToolFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy3DToolFrameView �׸���

void CMy3DToolFrameView::OnDraw(CDC* /*pDC*/)
{
	CMy3DToolFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy3DToolFrameView �μ�

BOOL CMy3DToolFrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy3DToolFrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy3DToolFrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy3DToolFrameView ����

#ifdef _DEBUG
void CMy3DToolFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CMy3DToolFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3DToolFrameDoc* CMy3DToolFrameView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3DToolFrameDoc)));
	return (CMy3DToolFrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy3DToolFrameView �޽��� ó����


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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDown(nFlags, point);
}
