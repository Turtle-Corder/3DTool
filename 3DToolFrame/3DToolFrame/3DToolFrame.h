
// 3DToolFrame.h : 3DToolFrame ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy3DToolFrameApp:
// �� Ŭ������ ������ ���ؼ��� 3DToolFrame.cpp�� �����Ͻʽÿ�.
//

class CMy3DToolFrameApp : public CWinAppEx
{
public:
	CMy3DToolFrameApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy3DToolFrameApp theApp;
