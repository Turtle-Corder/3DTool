// Page_Mesh.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "3DToolFrame.h"
#include "Page_Mesh.h"
#include "afxdialogex.h"


// CPage_Mesh 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPage_Mesh, CPropertyPage)

CPage_Mesh::CPage_Mesh()
	: CPropertyPage(IDD_PAGE_MESH)
	, m_strScaleX(_T(""))
	, m_strScaleY(_T(""))
	, m_strScaleZ(_T(""))
	, m_strPosX(_T(""))
	, m_strPosY(_T(""))
	, m_strPosZ(_T(""))
	, m_strRotX(_T(""))
	, m_strRotY(_T(""))
	, m_strRotZ(_T(""))
	, m_strSelectMesh(_T(""))
{

}

CPage_Mesh::~CPage_Mesh()
{
}

void CPage_Mesh::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_STATICOBJ, m_strStaticObjViewMode);
	DDX_Control(pDX, IDC_COMBO_STATICOBJ_VIEWMODE, m_cbStaticObjViewMode);
	DDX_Control(pDX, IDC_TREE_MESH, m_TreeMeshes);
	DDX_Text(pDX, IDC_EDIT_SCALE_X, m_strScaleX);
	DDX_Text(pDX, IDC_EDIT_SCALE_Y, m_strScaleY);
	DDX_Text(pDX, IDC_EDIT_SCALE_Z, m_strScaleZ);
	DDX_Text(pDX, IDC_EDIT_POS_X, m_strPosX);
	DDX_Text(pDX, IDC_EDIT_POS_Y, m_strPosY);
	DDX_Text(pDX, IDC_EDIT_POS_Z, m_strPosZ);
	DDX_Text(pDX, IDC_EDIT_ROT_X, m_strRotX);
	DDX_Text(pDX, IDC_EDIT_ROT_Y, m_strRotY);
	DDX_Text(pDX, IDC_EDIT_ROT_Z, m_strRotZ);
	DDX_Control(pDX, IDC_SPIN_SCALE_X, m_SpinScaleX);
	DDX_Control(pDX, IDC_SPIN_SCALE_Y, m_SpinScaleY);
	DDX_Control(pDX, IDC_SPIN_SCALE_Z, m_SpinScaleZ);
	DDX_Control(pDX, IDC_SPIN_POS_X, m_SpinPosX);
	DDX_Control(pDX, IDC_SPIN_POS_Y, m_SpinPosY);
	DDX_Control(pDX, IDC_SPIN_POS_Z, m_SpinPosZ);
	DDX_Control(pDX, IDC_SPIN_ROT_X, m_SpinRotX);
	DDX_Control(pDX, IDC_SPIN_ROT_Y, m_SpinRotY);
	DDX_Control(pDX, IDC_SPIN_ROT_Z, m_SpinRotZ);
	DDX_Control(pDX, IDC_RADIO_SELECT_OBJ_STATIC, m_RadioSelector[0]);
	DDX_Control(pDX, IDC_RADIO_SELECT_OBJ_DYNAMIC, m_RadioSelector[1]);
	DDX_Control(pDX, IDC_RADIO_SELECT_OBJ_NAVI, m_RadioSelector[2]);
	DDX_Control(pDX, IDC_TREE_STATICOBJ, m_TreeStaticObject);
	DDX_Control(pDX, IDC_STATIC_DYNAMIC_OBJ, m_strDynamicObjViewMode);
	DDX_Control(pDX, IDC_COMBO_DYNAMICOBJ_VIEWMODE, m_cbDynamicObjViewMode);
	DDX_Control(pDX, IDC_TREE_DYNAMICOBJ, m_TreeDynamicObject);
	DDX_Control(pDX, IDC_STATIC_NAVI_OBJ, m_strNavMeshViewMode);
	DDX_Control(pDX, IDC_COMBO_NAVIOBJ_VIEWMODE, m_cbNavMeshViewMode);
	DDX_Control(pDX, IDC_TREE_NAVIOBJ, m_TreeNavMesh);
	DDX_Control(pDX, IDC_CHECK_NAVMESH_SNAP, m_CheckNavMeshSnap);
	DDX_Text(pDX, IDC_STATIC_SELECT_STATIC, m_strSelectStatic);
	DDX_Text(pDX, IDC_STATIC_SELECT_DYNAMIC, m_strSelectDynamic);
	DDX_Text(pDX, IDC_STATIC_SELECT_NAVMESH, m_strSelectNavMesh);
	DDX_Text(pDX, IDC_STATIC_SELECT_MESH, m_strSelectMesh);
}


BEGIN_MESSAGE_MAP(CPage_Mesh, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_STATICOBJ_VIEWMODE, &CPage_Mesh::OnCbnSelchangeComboStaticobjViewmode)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_MESH, &CPage_Mesh::OnNMDblclkTreeMesh)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SCALE_X, &CPage_Mesh::OnDeltaposSpinScaleX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SCALE_Y, &CPage_Mesh::OnDeltaposSpinScaleY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SCALE_Z, &CPage_Mesh::OnDeltaposSpinScaleZ)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_X, &CPage_Mesh::OnDeltaposSpinPosX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_Y, &CPage_Mesh::OnDeltaposSpinPosY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_Z, &CPage_Mesh::OnDeltaposSpinPosZ)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_X, &CPage_Mesh::OnDeltaposSpinRotX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_Y, &CPage_Mesh::OnDeltaposSpinRotY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_Z, &CPage_Mesh::OnDeltaposSpinRotZ)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO_STATICOBJ, IDC_RADIO_NAVIOBJ, &CPage_Mesh::OnBnClickedRadio)
	ON_BN_CLICKED(IDC_BUTTON_STATIC_ADDGROUP, &CPage_Mesh::OnBnClickedButtonStaticAddgroup)
	ON_BN_CLICKED(IDC_BUTTON_STATIC_ADDOBJ, &CPage_Mesh::OnBnClickedButtonStaticAddobj)
	ON_BN_CLICKED(IDC_BUTTON_STATIC_DELOBJ, &CPage_Mesh::OnBnClickedButtonStaticDelobj)
	ON_CBN_SELCHANGE(IDC_COMBO_DYNAMICOBJ_VIEWMODE, &CPage_Mesh::OnCbnSelchangeComboDynamicobjViewmode)
	ON_BN_CLICKED(IDC_BUTTON_DYNAMIC_ADDGROUP, &CPage_Mesh::OnBnClickedButtonDynamicAddgroup)
	ON_BN_CLICKED(IDC_BUTTON_DYNAMIC_ADDOBJ, &CPage_Mesh::OnBnClickedButtonDynamicAddobj)
	ON_BN_CLICKED(IDC_BUTTON_DYNAMIC_DELOBJ, &CPage_Mesh::OnBnClickedButtonDynamicDelobj)
	ON_CBN_SELCHANGE(IDC_COMBO_NAVIOBJ_VIEWMODE, &CPage_Mesh::OnCbnSelchangeComboNaviobjViewmode)
	ON_BN_CLICKED(IDC_BUTTON_NAVI_DELOBJ, &CPage_Mesh::OnBnClickedButtonNaviDelobj)
	ON_BN_CLICKED(IDC_CHECK_NAVMESH_SNAP, &CPage_Mesh::OnBnClickedCheckNavmeshSnap)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_STATICOBJ, &CPage_Mesh::OnNMDblclkTreeStaticobj)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_DYNAMICOBJ, &CPage_Mesh::OnNMDblclkTreeDynamicobj)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_NAVIOBJ, &CPage_Mesh::OnNMDblclkTreeNaviobj)
END_MESSAGE_MAP()


// CPage_Mesh 메시지 처리기입니다.


BOOL CPage_Mesh::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	UpdateData(TRUE);

	//--------------------------------------------------
	// Resources
	//--------------------------------------------------
	InitResourceSection();

	//--------------------------------------------------
	// Transform
	//--------------------------------------------------
	InitTransformSection();


	//--------------------------------------------------
	// Modify Selector
	//--------------------------------------------------
	InitSelector();


	//--------------------------------------------------
	// Static Object
	//--------------------------------------------------
	InitStaticObjectSection();


	//--------------------------------------------------
	// Dynamic Object
	//--------------------------------------------------
	InitDynamicObjectSection();


	//--------------------------------------------------
	// Navi-Mesh Object
	//--------------------------------------------------
	InitNaviMeshObjectSection();




	//m_cbDynamicObjViewMode.InsertString(0, _T("Mixed"));
	//m_cbDynamicObjViewMode.InsertString(1, _T("WireFrame"));
	//m_cbDynamicObjViewMode.InsertString(2, _T("Off"));
	//m_cbDynamicObjViewMode.SetCurSel(0);
	//m_strDynamicObjViewMode.SetWindowText(_T("Mixed"));


	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CPage_Mesh::InitResourceSection()
{
	// TODO :
	HTREEITEM hRoot = m_TreeMeshes.InsertItem(_T("Root"), TVI_ROOT, TVI_LAST);
	HTREEITEM hChild1 = m_TreeMeshes.InsertItem(_T("Child1"), hRoot, TVI_LAST);
	HTREEITEM hChild2 = m_TreeMeshes.InsertItem(_T("Child2"), hRoot, TVI_LAST);

	m_TreeMeshes.InsertItem(_T("Child1 Child"), hChild1, TVI_LAST);
	m_TreeMeshes.InsertItem(_T("Child2 Child"), hChild2, TVI_LAST);
}

void CPage_Mesh::InitTransformSection()
{
	int iSpinMax = 0;

	//--------------------------------------------------
	// Scale
	//--------------------------------------------------
	iSpinMax = GetSpinRangeFloatToInt(m_fSpinMin, m_fSpinMax, m_fSpinDelta);;
	m_SpinScaleX.SetRange(-iSpinMax, iSpinMax);
	m_strScaleX.Format(_T("%.2f"), 1.f);

	m_SpinScaleY.SetRange(-iSpinMax, iSpinMax);
	m_strScaleY.Format(_T("%.2f"), 1.f);

	m_SpinScaleZ.SetRange(-iSpinMax, iSpinMax);
	m_strScaleZ.Format(_T("%.2f"), 1.f);


	//--------------------------------------------------
	// Position
	//--------------------------------------------------
	m_SpinPosX.SetRange(-iSpinMax, iSpinMax);
	m_strPosX.Format(_T("%.2f"), 0.f);

	m_SpinPosY.SetRange(-iSpinMax, iSpinMax);
	m_strPosY.Format(_T("%.2f"), 0.f);

	m_SpinPosZ.SetRange(-iSpinMax, iSpinMax);
	m_strPosZ.Format(_T("%.2f"), 0.f);


	//--------------------------------------------------
	// Rotation
	//--------------------------------------------------
	iSpinMax = GetSpinRangeFloatToInt(m_fSpinRotMin, m_fSpinRotMax, m_fSpinDelta);
	m_SpinRotX.SetRange(-iSpinMax, iSpinMax);
	m_strRotX.Format(_T("%.2f"), 0.f);

	m_SpinRotY.SetRange(-iSpinMax, iSpinMax);
	m_strRotY.Format(_T("%.2f"), 0.f);

	m_SpinRotZ.SetRange(-iSpinMax, iSpinMax);
	m_strRotZ.Format(_T("%.2f"), 0.f);
}

void CPage_Mesh::InitSelector()
{
	m_iSelector = 0;
	m_RadioSelector[0].SetCheck(TRUE);
	m_RadioSelector[1].SetCheck(FALSE);
	m_RadioSelector[2].SetCheck(FALSE);
}

void CPage_Mesh::InitStaticObjectSection()
{
	//--------------------------------------------------
	// Render Option
	//--------------------------------------------------
	m_cbStaticObjViewMode.InsertString(0, _T("Mixed"));
	m_cbStaticObjViewMode.InsertString(1, _T("WireFrame"));
	m_cbStaticObjViewMode.InsertString(2, _T("Off"));
	m_cbStaticObjViewMode.SetCurSel(0);
	m_strStaticObjViewMode.SetWindowText(_T("Mixed"));


	//--------------------------------------------------
	// Tree Items
	//--------------------------------------------------
	HTREEITEM hRoot = m_TreeStaticObject.InsertItem(_T("Root"), TVI_ROOT, TVI_LAST);
}

void CPage_Mesh::InitDynamicObjectSection()
{
	//--------------------------------------------------
	// Render Option
	//--------------------------------------------------
	m_cbDynamicObjViewMode.InsertString(0, _T("Mixed"));
	m_cbDynamicObjViewMode.InsertString(1, _T("WireFrame"));
	m_cbDynamicObjViewMode.InsertString(2, _T("Off"));
	m_cbDynamicObjViewMode.SetCurSel(0);
	m_strDynamicObjViewMode.SetWindowText(_T("Mixed"));


	//--------------------------------------------------
	// Tree Items
	//--------------------------------------------------
	HTREEITEM hRoot = m_TreeDynamicObject.InsertItem(_T("Root"), TVI_ROOT, TVI_LAST);
}

void CPage_Mesh::InitNaviMeshObjectSection()
{
	//--------------------------------------------------
	// Render Option
	//--------------------------------------------------
	m_cbNavMeshViewMode.InsertString(0, _T("Mixed"));
	m_cbNavMeshViewMode.InsertString(1, _T("WireFrame"));
	m_cbNavMeshViewMode.InsertString(2, _T("Off"));
	m_cbNavMeshViewMode.SetCurSel(0);
	m_strNavMeshViewMode.SetWindowText(_T("Mixed"));


	//--------------------------------------------------
	// Tree Items
	//--------------------------------------------------
	HTREEITEM hRoot = m_TreeNavMesh.InsertItem(_T("Root"), TVI_ROOT, TVI_LAST);
}

int CPage_Mesh::GetSpinRangeFloatToInt(float lower, float upper, float delta)
{
	int iResultRange;
	if (delta == 0.0f)
		return 0;

	float fRange = fabs((upper - lower) / delta);
	if (fRange > (float)UD_MAXVAL)	iResultRange = UD_MAXVAL;
	else							iResultRange = (int)fRange;

	return iResultRange;
}

int CPage_Mesh::GetSpinPosFloatToInt(float fPos, float fMin, float fMax, int iRange)
{
	float fPosInRange = (fPos - fMin) / (fMax - fMin);
	int iPos = (int)(iRange * fPosInRange + 0.5);
	return iPos;
}

float CPage_Mesh::GetSpinValue(const CSpinButtonCtrl * spin)
{
	float fRetVal = 0.f;
	CWnd* pEdit = spin->GetBuddy();
	if (pEdit)
	{
		CString str;
		pEdit->GetWindowText(str);
		fRetVal = (float)(_ttof(str));
	}

	return fRetVal;
}

void CPage_Mesh::CalculationSpinValue(float & fVal, BOOL bWrap, float fMin, float fMax, NM_UPDOWN * pNMHDSpin)
{
	if (pNMHDSpin->iDelta < 0)
	{
		float fAbsEPS = fabs(m_fEPS * (fVal > fMin ? fVal : fMin));
		if (fAbsEPS < m_fEPS) fAbsEPS = m_fEPS;
		if (fMin - fVal > fAbsEPS)
		{
			if (bWrap)	fVal = fMax;
			else		fVal = fMin;
		}
	}
	else
	{
		float fAbsEPS = fabs(m_fEPS * (fVal > fMax ? fVal : fMax));
		if (fAbsEPS < m_fEPS) fAbsEPS = m_fEPS;
		if (fVal - fMax > fAbsEPS)
		{
			if (bWrap)	fVal = fMin;
			else		fVal = fMax;
		}
	}
}


void CPage_Mesh::OnBnClickedRadio(UINT uiID)
{
	switch (uiID)
	{
	case IDC_RADIO_STATICOBJ:
		m_iSelector = 0;
		break;

	case IDC_RADIO_DYNAMICOBJ:
		m_iSelector = 1;
		break;

	case IDC_RADIO_NAVIOBJ:
		m_iSelector = 2;
		break;
	}
}

void CPage_Mesh::OnCbnSelchangeComboStaticobjViewmode()
{
	UpdateData(TRUE);

	int iSelect = m_cbStaticObjViewMode.GetCurSel();
	if (0 > iSelect || m_cbStaticObjViewMode.GetCount() <= iSelect)
		return;

	CString strName;
	m_cbStaticObjViewMode.GetLBText(iSelect, strName);
	m_iStaticObjViewMode = iSelect;

	m_strStaticObjViewMode.SetWindowText(strName);

	UpdateData(FALSE);
}


void CPage_Mesh::OnNMDblclkTreeMesh(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	HTREEITEM hItem = m_TreeMeshes.GetSelectedItem();
	BOOL bHasChild = m_TreeMeshes.ItemHasChildren(hItem);
	if (!bHasChild)
	{
		m_strSelectMesh = m_TreeMeshes.GetItemText(hItem);
		// TODO :
		// m_pSelectObject = ;
	}

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinScaleX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	float fSpinValue = GetSpinValue(&m_SpinScaleX);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinScaleX.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strScaleX.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinScaleY(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinScaleY);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinScaleY.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strScaleY.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinScaleZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinScaleZ);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinScaleZ.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strScaleZ.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinPosX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosX);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosX.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strPosX.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinPosY(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosY);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosY.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strPosY.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinPosZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosZ);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosZ.GetStyle(), m_fSpinMin, m_fSpinMax, pNMUpDown);
	m_strPosZ.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinRotX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotX);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotX.GetStyle(), m_fSpinRotMin, m_fSpinRotMax, pNMUpDown);
	m_strRotX.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinRotY(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotY);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotY.GetStyle(), m_fSpinRotMin, m_fSpinRotMax, pNMUpDown);
	m_strRotY.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnDeltaposSpinRotZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotZ);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotZ.GetStyle(), m_fSpinRotMin, m_fSpinRotMax, pNMUpDown);
	m_strRotZ.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonStaticAddgroup()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeStaticObject.GetSelectedItem();
	HTREEITEM hRootItem = m_TreeStaticObject.GetRootItem();
	CString strName;

	// 선택 x || root
	if (NULL == hSelectItem || hRootItem == hSelectItem)
	{
		strName.Format(_T("Group_%02d"), m_iStaticGroupCounter++);
		m_TreeStaticObject.InsertItem(strName, hRootItem, TVI_LAST);
	}
	
	// child 
	else
	{
		// child x
		if (!m_TreeStaticObject.ItemHasChildren(hSelectItem))
		{
			strName = m_TreeStaticObject.GetItemText(hSelectItem);
			strName.AppendFormat(_T("_00"));
			m_TreeStaticObject.InsertItem(strName, hSelectItem, TVI_LAST);
		}
		
		// child o
		else
		{
			HTREEITEM hChild = m_TreeStaticObject.GetChildItem(hSelectItem);
			HTREEITEM hLast = hChild;
			while (NULL != hChild)
			{
				hLast = hChild;
				hChild = m_TreeStaticObject.GetNextSiblingItem(hChild);
			}

			strName = m_TreeStaticObject.GetItemText(hLast);
			int iIndex = _ttoi(strName.Right(2));
			strName.Delete(strName.GetLength() - 2, 2);
			strName.AppendFormat(_T("%02d"), ++iIndex);

			m_TreeStaticObject.InsertItem(strName, hSelectItem, TVI_LAST);
		}
	}

	m_TreeStaticObject.Invalidate();

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonStaticAddobj()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeStaticObject.GetSelectedItem();
	if (NULL == hSelectItem)
		hSelectItem = m_TreeStaticObject.GetRootItem();

	// TODO : 오브젝트 넘버링
	if(!m_strSelectMesh.IsEmpty())
		m_TreeStaticObject.InsertItem(m_strSelectMesh, hSelectItem, TVI_LAST);

	m_TreeStaticObject.Invalidate();

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonStaticDelobj()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeStaticObject.GetSelectedItem();
	do 
	{
		if (NULL == hSelectItem) break;
		if (m_TreeStaticObject.GetRootItem() == hSelectItem) break;
		if (m_TreeStaticObject.ItemHasChildren(hSelectItem)) break;

		m_TreeStaticObject.DeleteItem(hSelectItem);

		m_TreeStaticObject.Invalidate();

	} while (0);

	UpdateData(FALSE);
}


void CPage_Mesh::OnCbnSelchangeComboDynamicobjViewmode()
{
	UpdateData(TRUE);

	int iSelect = m_cbDynamicObjViewMode.GetCurSel();
	if (0 > iSelect || m_cbDynamicObjViewMode.GetCount() <= iSelect)
		return;

	CString strName;
	m_cbDynamicObjViewMode.GetLBText(iSelect, strName);
	m_iDynamicObjViewMode = iSelect;

	m_strDynamicObjViewMode.SetWindowText(strName);

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonDynamicAddgroup()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeDynamicObject.GetSelectedItem();
	HTREEITEM hRootItem = m_TreeDynamicObject.GetRootItem();
	CString strName;

	// 선택 x || root
	if (NULL == hSelectItem || hRootItem == hSelectItem)
	{
		strName.Format(_T("Group_%02d"), m_iDynamicGroupCounter++);
		m_TreeDynamicObject.InsertItem(strName, hRootItem, TVI_LAST);
	}

	// child 
	else
	{
		// child x
		if (!m_TreeDynamicObject.ItemHasChildren(hSelectItem))
		{
			strName = m_TreeDynamicObject.GetItemText(hSelectItem);
			strName.AppendFormat(_T("_00"));
			m_TreeDynamicObject.InsertItem(strName, hSelectItem, TVI_LAST);
		}

		// child o
		else
		{
			HTREEITEM hChild = m_TreeDynamicObject.GetChildItem(hSelectItem);
			HTREEITEM hLast = hChild;
			while (NULL != hChild)
			{
				hLast = hChild;
				hChild = m_TreeDynamicObject.GetNextSiblingItem(hChild);
			}

			strName = m_TreeDynamicObject.GetItemText(hLast);
			int iIndex = _ttoi(strName.Right(2));
			strName.Delete(strName.GetLength() - 2, 2);
			strName.AppendFormat(_T("%02d"), ++iIndex);

			m_TreeDynamicObject.InsertItem(strName, hSelectItem, TVI_LAST);
		}
	}

	m_TreeDynamicObject.Invalidate();

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonDynamicAddobj()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeDynamicObject.GetSelectedItem();
	if (NULL == hSelectItem)
		hSelectItem = m_TreeDynamicObject.GetRootItem();

	// TODO : 오브젝트 넘버링
	if (!m_strSelectMesh.IsEmpty())
		m_TreeDynamicObject.InsertItem(m_strSelectMesh, hSelectItem, TVI_LAST);

	m_TreeDynamicObject.Invalidate();

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonDynamicDelobj()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeDynamicObject.GetSelectedItem();
	do
	{
		if (NULL == hSelectItem) break;
		if (m_TreeDynamicObject.GetRootItem() == hSelectItem) break;
		if (m_TreeDynamicObject.ItemHasChildren(hSelectItem)) break;

		m_TreeDynamicObject.DeleteItem(hSelectItem);

		m_TreeDynamicObject.Invalidate();

	} while (0);

	UpdateData(FALSE);
}


void CPage_Mesh::OnCbnSelchangeComboNaviobjViewmode()
{
	UpdateData(TRUE);

	int iSelect = m_cbNavMeshViewMode.GetCurSel();
	if (0 > iSelect || m_cbNavMeshViewMode.GetCount() <= iSelect)
		return;

	CString strName;
	m_cbNavMeshViewMode.GetLBText(iSelect, strName);
	m_iNavMeshObjViewMode = iSelect;

	m_strNavMeshViewMode.SetWindowText(strName);

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedButtonNaviDelobj()
{
	UpdateData(TRUE);

	HTREEITEM hSelectItem = m_TreeNavMesh.GetSelectedItem();
	do
	{
		if (NULL == hSelectItem) break;
		if (m_TreeNavMesh.GetRootItem() == hSelectItem)	 break;
		if (!m_TreeNavMesh.ItemHasChildren(hSelectItem)) break;

		HTREEITEM hChild[3];
		hChild[0] = m_TreeNavMesh.GetChildItem(hSelectItem);
		hChild[1] = m_TreeNavMesh.GetNextSiblingItem(hChild[0]);
		hChild[2] = m_TreeNavMesh.GetNextSiblingItem(hChild[1]);

		for (int iCnt = 0; iCnt < 3; ++iCnt)
		{
			// TODO : 해제 작업
		}

		m_TreeNavMesh.DeleteItem(hSelectItem);
		m_TreeNavMesh.Invalidate();

	} while (0);

	UpdateData(FALSE);
}


void CPage_Mesh::OnBnClickedCheckNavmeshSnap()
{
	m_bPickingSnap = m_CheckNavMeshSnap.GetCheck();
}


void CPage_Mesh::OnNMDblclkTreeStaticobj(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	HTREEITEM hItem = m_TreeStaticObject.GetSelectedItem();
	BOOL bHasChild = m_TreeStaticObject.ItemHasChildren(hItem);
	if (!bHasChild)
	{
		m_strSelectStatic = m_TreeStaticObject.GetItemText(hItem);
		// TODO :
		// m_pSelectObject = ;
		// Set Transform
	}

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnNMDblclkTreeDynamicobj(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	HTREEITEM hItem = m_TreeDynamicObject.GetSelectedItem();
	BOOL bHasChild = m_TreeDynamicObject.ItemHasChildren(hItem);
	if (!bHasChild)
	{
		m_strSelectDynamic = m_TreeDynamicObject.GetItemText(hItem);
		// TODO :
		// m_pSelectObject = ;
		// Set Transform
	}

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Mesh::OnNMDblclkTreeNaviobj(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	HTREEITEM hItem = m_TreeNavMesh.GetSelectedItem();
	BOOL bHasChild = m_TreeNavMesh.ItemHasChildren(hItem);
	if (!bHasChild)
	{
		m_strSelectNavMesh = m_TreeNavMesh.GetItemText(hItem);
		// TODO :
		// m_pSelectObject = ;
		// Set Transform
	}

	*pResult = 0;

	UpdateData(FALSE);
}
