// FixedSplitterWnd.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "3DToolFrame.h"
#include "FixedSplitterWnd.h"


// CFixedSplitterWnd

IMPLEMENT_DYNAMIC(CFixedSplitterWnd, CSplitterWnd)

CFixedSplitterWnd::CFixedSplitterWnd()
{

}

CFixedSplitterWnd::~CFixedSplitterWnd()
{
}


BEGIN_MESSAGE_MAP(CFixedSplitterWnd, CSplitterWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CFixedSplitterWnd �޽��� ó�����Դϴ�.



void CFixedSplitterWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	//CSplitterWnd::OnMouseMove(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	//CSplitterWnd::OnLButtonDown(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	//CSplitterWnd::OnLButtonUp(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	//CSplitterWnd::OnLButtonDblClk(nFlags, point);
}


