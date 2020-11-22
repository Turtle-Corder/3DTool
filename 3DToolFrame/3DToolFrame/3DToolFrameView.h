
// 3DToolFrameView.h : CMy3DToolFrameView Ŭ������ �������̽�
//

#pragma once

class CMy3DToolFrameDoc;
class CMy3DToolFrameView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy3DToolFrameView();
	DECLARE_DYNCREATE(CMy3DToolFrameView)

// Ư���Դϴ�.
public:
	CMy3DToolFrameDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy3DToolFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3DToolFrameView.cpp�� ����� ����
inline CMy3DToolFrameDoc* CMy3DToolFrameView::GetDocument() const
   { return reinterpret_cast<CMy3DToolFrameDoc*>(m_pDocument); }
#endif

