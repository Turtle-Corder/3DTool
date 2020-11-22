// Page_Terrain.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "3DToolFrame.h"
#include "Page_Terrain.h"
#include "afxdialogex.h"


// CPage_Terrain 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPage_Terrain, CPropertyPage)

CPage_Terrain::CPage_Terrain()
	: CPropertyPage(IDD_PAGE_TERRAIN)
	, m_strVTXCountX(_T(""))
	, m_strVTXCountZ(_T(""))
	, m_strVTXInterval(_T(""))
	, m_strVTXDetail(_T(""))
	, m_strPositionX(_T(""))
	, m_strPositionY(_T(""))
	, m_strPositionZ(_T(""))
	, m_strRotationX(_T(""))
	, m_strRotationY(_T(""))
	, m_strRotationZ(_T(""))
	, m_strTexture(_T(""))
{

}

CPage_Terrain::~CPage_Terrain()
{
}

void CPage_Terrain::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TERRAIN_VIEWMODE, m_cbViewMode);
	DDX_Text(pDX, IDC_STATIC_TERRAIN_VIEW, m_strViewMode);
	DDX_Control(pDX, IDC_CHECK_VIEWAXIS, m_CheckViewAxis);
	DDX_Text(pDX, IDC_EDIT_VTX_X, m_strVTXCountX);
	DDX_Text(pDX, IDC_EDIT_VTX_Z, m_strVTXCountZ);
	DDX_Text(pDX, IDC_EDIT_VTX_INTERVAL, m_strVTXInterval);
	DDX_Text(pDX, IDC_EDIT_VTX_DETAIL, m_strVTXDetail);
	DDX_Control(pDX, IDC_SPIN_VTX_X, m_SpinVTXCountX);
	DDX_Control(pDX, IDC_SPIN_VTX_Z, m_SpinVTXCountZ);
	DDX_Control(pDX, IDC_SPIN_VTX_INTERVAL, m_SpinVTXInterval);
	DDX_Control(pDX, IDC_SPIN_VTX_DETAIL, m_SpinVTXDetail);
	DDX_Text(pDX, IDC_EDIT_POS_X, m_strPositionX);
	DDX_Text(pDX, IDC_EDIT_POS_Y, m_strPositionY);
	DDX_Text(pDX, IDC_EDIT_POS_Z, m_strPositionZ);
	DDX_Text(pDX, IDC_EDIT_ROT_X, m_strRotationX);
	DDX_Text(pDX, IDC_EDIT_ROT_Y, m_strRotationY);
	DDX_Text(pDX, IDC_EDIT_ROT_Z, m_strRotationZ);
	DDX_Control(pDX, IDC_SPIN_POS_X, m_SpinPosX);
	DDX_Control(pDX, IDC_SPIN_POS_Y, m_SpinPosY);
	DDX_Control(pDX, IDC_SPIN_POS_Z, m_SpinPosZ);
	DDX_Control(pDX, IDC_SPIN_ROT_X, m_SpinRotX);
	DDX_Control(pDX, IDC_SPIN_ROT_Y, m_SpinRotY);
	DDX_Control(pDX, IDC_SPIN_ROT_Z, m_SpinRotZ);
	DDX_Control(pDX, IDC_TREE_TEXTURE, m_TreeTextures);
	DDX_Text(pDX, IDC_STATIC_TEXTURE, m_strTexture);
}


BEGIN_MESSAGE_MAP(CPage_Terrain, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_TERRAIN_VIEWMODE, &CPage_Terrain::OnCbnSelchangeComboViewmode)
	ON_BN_CLICKED(IDC_CHECK_VIEWAXIS, &CPage_Terrain::OnBnClickedCheckViewaxis)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_VTX_X, &CPage_Terrain::OnDeltaposSpinVtxX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_VTX_Z, &CPage_Terrain::OnDeltaposSpinVtxZ)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_VTX_INTERVAL, &CPage_Terrain::OnDeltaposSpinVtxInterval)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_VTX_DETAIL, &CPage_Terrain::OnDeltaposSpinVtxDetail)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_X, &CPage_Terrain::OnDeltaposSpinPosX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_Y, &CPage_Terrain::OnDeltaposSpinPosY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POS_Z, &CPage_Terrain::OnDeltaposSpinPosZ)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_X, &CPage_Terrain::OnDeltaposSpinRotX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_Y, &CPage_Terrain::OnDeltaposSpinRotY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ROT_Z, &CPage_Terrain::OnDeltaposSpinRotZ)
	ON_BN_CLICKED(IDC_BUTTON_APPLY, &CPage_Terrain::OnBnClickedButtonApply)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_TEXTURE, &CPage_Terrain::OnNMDblclkTreeTexture)
END_MESSAGE_MAP()


// CPage_Terrain 메시지 처리기입니다.

BOOL CPage_Terrain::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	UpdateData(TRUE);

	//--------------------------------------------------
	// Render State
	//--------------------------------------------------
	m_cbViewMode.InsertString(0, _T("Mixed"));
	m_cbViewMode.InsertString(1, _T("Wireframe"));
	m_cbViewMode.InsertString(2, _T("Off"));
//	m_cbViewMode.InsertString(2, _T("Unlit"));
//	m_cbViewMode.InsertString(3, _T("Lighting Only"));

	m_cbViewMode.SetCurSel(0);
	m_strViewMode = _T("Mixed");


	//--------------------------------------------------
	// Render Axis
	//--------------------------------------------------
	m_CheckViewAxis.SetCheck(m_bViewAxis);


	//--------------------------------------------------
	// Vertex
	//--------------------------------------------------
	m_SpinVTXCountX.SetRange(m_iVTXCountMin, m_iVTXCountMax);
	m_strVTXCountX.Format(_T("%d"), m_iVTXCountMin);

	m_SpinVTXCountZ.SetRange(m_iVTXCountMin, m_iVTXCountMax);
	m_strVTXCountZ.Format(_T("%d"), m_iVTXCountMin);

	int iSpinMax = GetSpinRangeFloatToInt(m_fVTXSpinMin, m_fVTXSpinMax, m_fSpinDelta);
	m_SpinVTXInterval.SetRange((int)m_fVTXSpinMin, iSpinMax);
	m_strVTXInterval.Format(_T("%.2f"), 1.f);

	m_SpinVTXDetail.SetRange((int)m_fVTXSpinMin, iSpinMax);
	m_strVTXDetail.Format(_T("%.2f"), 1.f);


	//--------------------------------------------------
	// Transform
	//--------------------------------------------------
	iSpinMax = GetSpinRangeFloatToInt(m_fPosSpinMin, m_fPosSpinMax, m_fSpinDelta);
	m_SpinPosX.SetRange(-iSpinMax, iSpinMax);
	m_strPositionX.Format(_T("%.2f"), 0.f);

	m_SpinPosY.SetRange(-iSpinMax, iSpinMax);
	m_strPositionY.Format(_T("%.2f"), 0.f);

	m_SpinPosZ.SetRange(-iSpinMax, iSpinMax);
	m_strPositionZ.Format(_T("%.2f"), 0.f);


	iSpinMax = GetSpinRangeFloatToInt(m_fRotSpinMin, m_fRotSpinMax, m_fSpinDelta);
	m_SpinRotX.SetRange(-iSpinMax, iSpinMax);
	m_strRotationX.Format(_T("%.2f"), 0.f);

	m_SpinRotY.SetRange(-iSpinMax, iSpinMax);
	m_strRotationY.Format(_T("%.2f"), 0.f);

	m_SpinRotZ.SetRange(-iSpinMax, iSpinMax);
	m_strRotationZ.Format(_T("%.2f"), 0.f);

	m_strTexture.SetString(_T("TextureName.format"));

	Setup_Resources();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPage_Terrain::OnCbnSelchangeComboViewmode()
{
	UpdateData(TRUE);

	int iSelect = m_cbViewMode.GetCurSel();
	if (0 > iSelect || m_cbViewMode.GetCount() <= iSelect)
		return;

	CString strName;
	m_cbViewMode.GetLBText(iSelect, strName);
	m_iViewMode = iSelect;

	m_strViewMode = strName;

	UpdateData(FALSE);
}


void CPage_Terrain::OnBnClickedCheckViewaxis()
{
	UpdateData(TRUE);

	m_bViewAxis = m_CheckViewAxis.GetCheck();

	UpdateData(FALSE);
}

int CPage_Terrain::GetSpinRangeFloatToInt(float lower, float upper, float delta)
{
	int iResultRange;
	if (delta == 0.0f)
		return 0;

	float fRange = fabs((upper - lower) / delta);
	if (fRange > (float)UD_MAXVAL)	iResultRange = UD_MAXVAL;
	else							iResultRange = (int)fRange;
	
	return iResultRange;
}

int CPage_Terrain::GetSpinPosFloatToInt(float fPos, float fMin, float fMax, int iRange)
{
	float fPosInRange = (fPos - fMin) / (fMax - fMin);
	int iPos = (int)(iRange * fPosInRange + 0.5);
	return iPos;
}

float CPage_Terrain::GetSpinValue(const CSpinButtonCtrl * spin)
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

void CPage_Terrain::CalculationSpinValue(float & fVal, BOOL bWrap, float fMin, float fMax, NM_UPDOWN * pNMHDSpin)
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


void CPage_Terrain::OnDeltaposSpinVtxX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	int iSpinValue = (int)GetSpinValue(&m_SpinVTXCountX);
	int iValue = iSpinValue + pNMUpDown->iDelta;
	if (m_iVTXCountMin > iValue) iValue = m_iVTXCountMin;
	if (m_iVTXCountMax < iValue) iValue = m_iVTXCountMax;

	m_strVTXCountX.Format(_T("%d"), iValue);

	//float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	//CalculationSpinValue(fValue, UDS_WRAP & m_SpinVTXCountX.GetStyle(), m_iVTXCountMin, m_iVTXCountMax, pNMUpDown);
	//m_strVTXCountX.Format(_T("%.3f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}

void CPage_Terrain::OnDeltaposSpinVtxZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	int iSpinValue = (int)GetSpinValue(&m_SpinVTXCountZ);
	int iValue = iSpinValue + pNMUpDown->iDelta;
	if (m_iVTXCountMin > iValue) iValue = m_iVTXCountMin;
	if (m_iVTXCountMax < iValue) iValue = m_iVTXCountMax;

	m_strVTXCountZ.Format(_T("%d"), iValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinVtxInterval(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	float fSpinValue = GetSpinValue(&m_SpinVTXInterval);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinVTXInterval.GetStyle(), m_fVTXSpinMin, m_fVTXSpinMax, pNMUpDown);
	m_strVTXInterval.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinVtxDetail(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinVTXDetail);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinVTXDetail.GetStyle(), m_fVTXSpinMin, m_fVTXSpinMax, pNMUpDown);
	m_strVTXDetail.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinPosX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosX);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosX.GetStyle(), m_fPosSpinMin, m_fPosSpinMax, pNMUpDown);
	m_strPositionX.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinPosY(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosY);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosY.GetStyle(), m_fPosSpinMin, m_fPosSpinMax, pNMUpDown);
	m_strPositionY.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinPosZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinPosZ);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinPosZ.GetStyle(), m_fPosSpinMin, m_fPosSpinMax, pNMUpDown);
	m_strPositionZ.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinRotX(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotX);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotX.GetStyle(), m_fRotSpinMin, m_fRotSpinMax, pNMUpDown);
	m_strRotationX.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinRotY(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotY);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotY.GetStyle(), m_fRotSpinMin, m_fRotSpinMax, pNMUpDown);
	m_strRotationY.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnDeltaposSpinRotZ(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	float fSpinValue = GetSpinValue(&m_SpinRotZ);
	float fValue = fSpinValue + (pNMUpDown->iDelta * m_fSpinDelta);
	CalculationSpinValue(fValue, UDS_WRAP & m_SpinRotZ.GetStyle(), m_fRotSpinMin, m_fRotSpinMax, pNMUpDown);
	m_strRotationZ.Format(_T("%.2f"), fValue);

	*pResult = 0;

	UpdateData(FALSE);
}


void CPage_Terrain::OnBnClickedButtonApply()
{
	UpdateData(TRUE);

	// TODO ..


	UpdateData(FALSE);
}


void CPage_Terrain::Setup_Resources()
{
	// resourece manager or filepath에서 가져와서 셋팅하자

	HTREEITEM root;
	root = m_TreeTextures.InsertItem(_T("Root"), TVI_ROOT, TVI_LAST);

	HTREEITEM hChild1, hChild2;
	hChild1 = m_TreeTextures.InsertItem(_T("Child1"), root, TVI_LAST);
	hChild2 = m_TreeTextures.InsertItem(_T("Child2"), root, TVI_LAST);

	m_TreeTextures.InsertItem(_T("Child1 Child"), hChild1, TVI_LAST);
	m_TreeTextures.InsertItem(_T("Child2 Child"), hChild2, TVI_LAST);
}


void CPage_Terrain::OnNMDblclkTreeTexture(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);

	HTREEITEM hItem = m_TreeTextures.GetSelectedItem();
	BOOL bHasChild = m_TreeTextures.ItemHasChildren(hItem);
	if (!bHasChild)
	{
		m_strTexture = m_TreeTextures.GetItemText(hItem);
	}

	*pResult = 0;

	UpdateData(FALSE);
}
