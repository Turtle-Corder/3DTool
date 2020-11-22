#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPage_Mesh 대화 상자입니다.

class CPage_Mesh : public CPropertyPage
{
	DECLARE_DYNAMIC(CPage_Mesh)

public:
	CPage_Mesh();
	virtual ~CPage_Mesh();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_MESH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();

	void InitResourceSection();
	void InitTransformSection();
	void InitSelector();
	void InitStaticObjectSection();
	void InitDynamicObjectSection();
	void InitNaviMeshObjectSection();


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

	const float m_fSpinMin = -1000.f;
	const float m_fSpinMax = 1000.f;
	const float m_fSpinRotMin = -360.f;
	const float m_fSpinRotMax = 360.f;





	//----------------------------------------------------------------------------------------------------
	// Transform 변경해야 하므로
	//----------------------------------------------------------------------------------------------------
	class CGameObject* m_pSelectObject = nullptr;
	int m_iSelector = 0;
	CButton m_RadioSelector[3];
	afx_msg void OnBnClickedRadio(UINT uiID);





	//----------------------------------------------------------------------------------------------------
	// Mesh (Resourece) 
	//----------------------------------------------------------------------------------------------------
	CString m_strSelectMesh;
	CTreeCtrl m_TreeMeshes;
	afx_msg void OnNMDblclkTreeMesh(NMHDR *pNMHDR, LRESULT *pResult);





	//----------------------------------------------------------------------------------------------------
	// Transform
	//----------------------------------------------------------------------------------------------------
	
	//--------------------------------------------------
	// Scale
	//--------------------------------------------------
	CString m_strScaleX;
	CString m_strScaleY;
	CString m_strScaleZ;

	CSpinButtonCtrl m_SpinScaleX;
	CSpinButtonCtrl m_SpinScaleY;
	CSpinButtonCtrl m_SpinScaleZ;

	afx_msg void OnDeltaposSpinScaleX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinScaleY(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinScaleZ(NMHDR *pNMHDR, LRESULT *pResult);


	//--------------------------------------------------
	// Position
	//--------------------------------------------------
	CString m_strPosX;
	CString m_strPosY;
	CString m_strPosZ;

	CSpinButtonCtrl m_SpinPosX;
	CSpinButtonCtrl m_SpinPosY;
	CSpinButtonCtrl m_SpinPosZ;

	afx_msg void OnDeltaposSpinPosX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinPosY(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinPosZ(NMHDR *pNMHDR, LRESULT *pResult);


	//--------------------------------------------------
	// Rotation
	//--------------------------------------------------
	CString m_strRotX;
	CString m_strRotY;
	CString m_strRotZ;

	CSpinButtonCtrl m_SpinRotX;
	CSpinButtonCtrl m_SpinRotY;
	CSpinButtonCtrl m_SpinRotZ;

	afx_msg void OnDeltaposSpinRotX(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRotY(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinRotZ(NMHDR *pNMHDR, LRESULT *pResult);





	//----------------------------------------------------------------------------------------------------
	// Static Object
	//----------------------------------------------------------------------------------------------------
	int m_iStaticObjViewMode = 0;
	CStatic m_strStaticObjViewMode;
	CComboBox m_cbStaticObjViewMode;
	afx_msg void OnCbnSelchangeComboStaticobjViewmode();

	CString m_strSelectStatic;
	CTreeCtrl m_TreeStaticObject;
	afx_msg void OnNMDblclkTreeStaticobj(NMHDR *pNMHDR, LRESULT *pResult);

	int m_iStaticGroupCounter = 0;
	afx_msg void OnBnClickedButtonStaticAddgroup();
	afx_msg void OnBnClickedButtonStaticAddobj();
	afx_msg void OnBnClickedButtonStaticDelobj();





	//----------------------------------------------------------------------------------------------------
	// Dynamic Object
	//----------------------------------------------------------------------------------------------------
	int m_iDynamicObjViewMode = 0;
	CStatic m_strDynamicObjViewMode;
	CComboBox m_cbDynamicObjViewMode;
	afx_msg void OnCbnSelchangeComboDynamicobjViewmode();

	CString m_strSelectDynamic;
	CTreeCtrl m_TreeDynamicObject;
	afx_msg void OnNMDblclkTreeDynamicobj(NMHDR *pNMHDR, LRESULT *pResult);

	int m_iDynamicGroupCounter = 0;
	afx_msg void OnBnClickedButtonDynamicAddgroup();
	afx_msg void OnBnClickedButtonDynamicAddobj();
	afx_msg void OnBnClickedButtonDynamicDelobj();





	//----------------------------------------------------------------------------------------------------
	// Navi-Mesh
	//----------------------------------------------------------------------------------------------------
	int m_iNavMeshObjViewMode = 0;
	CStatic m_strNavMeshViewMode;
	CComboBox m_cbNavMeshViewMode;
	afx_msg void OnCbnSelchangeComboNaviobjViewmode();

	CString m_strSelectNavMesh;
	CTreeCtrl m_TreeNavMesh;
	afx_msg void OnNMDblclkTreeNaviobj(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnBnClickedButtonNaviDelobj();

	BOOL	m_bPickingSnap;
	CButton m_CheckNavMeshSnap;
	afx_msg void OnBnClickedCheckNavmeshSnap();

};
