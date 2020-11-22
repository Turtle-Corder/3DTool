
// 3DToolFrameView.h : CMy3DToolFrameView 클래스의 인터페이스
//

#pragma once

class CMy3DToolFrameDoc;
class CMy3DToolFrameView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy3DToolFrameView();
	DECLARE_DYNCREATE(CMy3DToolFrameView)

// 특성입니다.
public:
	CMy3DToolFrameDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy3DToolFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3DToolFrameView.cpp의 디버그 버전
inline CMy3DToolFrameDoc* CMy3DToolFrameView::GetDocument() const
   { return reinterpret_cast<CMy3DToolFrameDoc*>(m_pDocument); }
#endif

