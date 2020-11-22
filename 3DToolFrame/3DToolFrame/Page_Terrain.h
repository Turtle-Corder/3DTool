#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPage_Terrain 대화 상자입니다.

class CPage_Terrain : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage_Terrain)

public:
	CPage_Terrain();
	virtual ~CPage_Terrain();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_TERRAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();

	//----------------------------------------------------------------------------------------------------
	// Render Option
	//----------------------------------------------------------------------------------------------------
	
	//--------------------------------------------------
	// Render State
	//--------------------------------------------------
	int m_iViewMode = 0;
	CComboBox m_cbViewMode;
	CString m_strViewMode;
	afx_msg void OnCbnSelchangeComboViewmode();


	//--------------------------------------------------
	// Render Axis
	//--------------------------------------------------
	BOOL m_bViewAxis = FALSE;
	CButton m_CheckViewAxis;
	afx_msg void OnBnClickedCheckViewaxis();



	//----------------------------------------------------------------------------------------------------
	// Spin Control
	//----------------------------------------------------------------------------------------------------
	const float m_fSpinDelta = 0.01f;
	const float m_fEPS = (float)1.0e-9;

	// 초기 Spin 컨트롤의 범위 설정
	int GetSpinRangeFloatToInt(float lower, float upper, float delta);

	// flaot -> Spin
	// Spin 컨트롤에 입력용
	int GetSpinPosFloatToInt(float fPos, float fMin, float fMax, int iRange);

	// Spin -> float
	// Spin 컨트롤에서 값을 가져오는용
	float GetSpinValue(const CSpinButtonCtrl * spin);

	// Range Lock
	void CalculationSpinValue(float& fVal, BOOL bWrap, float fMin, float fMax, NM_UPDOWN* pNMHDSpin);



	//----------------------------------------------------------------------------------------------------
	// Vertex Option
	//----------------------------------------------------------------------------------------------------
	CString m_strVTXCountX;
	CString m_strVTXCountZ;
	CString m_strVTXInterval;
	CString m_strVTXDetail;

	CSpinButtonCtrl m_SpinVTXCountX;
	CSpinButtonCtrl m_SpinVTXCountZ;
	CSpinButtonCtrl m_SpinVTXInterval;
	CSpinButtonCtrl m_SpinVTXDetail;

	const int	m_iVTXCountMin = 1;
	const int	m_iVTXCountMax = 1000;
	int			m_iVTXCountX = 1;
	int			m_iVTXCountZ = 1;

	const float m_fVTXSpinMin = 0.0f;
	const float m_fVTXSpinMax = 1000.f;

	float	m_fVTXInterval = 1.f;
	float	m_fVTXDetail = 1.f;

	afx_msg void OnDeltaposSpinVtxX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinVtxZ(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinVtxInterval(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinVtxDetail(NMHDR *pNMHDR, LRESULT *pResult);
	
	afx_msg void OnBnClickedButtonApply();



	//----------------------------------------------------------------------------------------------------
	// Transform Option
	//----------------------------------------------------------------------------------------------------

	//--------------------------------------------------
	// Position
	//--------------------------------------------------
	CString m_strPositionX;
	CString m_strPositionY;
	CString m_strPositionZ;

	CSpinButtonCtrl m_SpinPosX;
	CSpinButtonCtrl m_SpinPosY;
	CSpinButtonCtrl m_SpinPosZ;

	const float m_fPosSpinMin = -1000.0f;
	const float m_fPosSpinMax = 1000.f;

	afx_msg void OnDeltaposSpinPosX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinPosY(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinPosZ(NMHDR *pNMHDR, LRESULT *pResult);


	//--------------------------------------------------
	// Rotation
	//--------------------------------------------------
	CString m_strRotationX;
	CString m_strRotationY;
	CString m_strRotationZ;

	CSpinButtonCtrl m_SpinRotX;
	CSpinButtonCtrl m_SpinRotY;
	CSpinButtonCtrl m_SpinRotZ;

	const float m_fRotSpinMin = -360.f;
	const float m_fRotSpinMax = 360.f;

	afx_msg void OnDeltaposSpinRotX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRotY(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRotZ(NMHDR *pNMHDR, LRESULT *pResult);



	//----------------------------------------------------------------------------------------------------
	// Texture Option
	//----------------------------------------------------------------------------------------------------
	CString m_strTexture;
	CTreeCtrl m_TreeTextures;

	void Setup_Resources();
	afx_msg void OnNMDblclkTreeTexture(NMHDR *pNMHDR, LRESULT *pResult);
};
