#include "stdafx.h"
#include "FilePath.h"


CFilePath::CFilePath()
{
}


CFilePath::~CFilePath()
{
}

tstring CFilePath::ConvertRelativePath(const tstring & _strFullPath)
{
	TCHAR szRelativePath[MAX_PATH] = _T("");
	TCHAR szCurrentDir[MAX_PATH] = _T("");

	GetCurrentDirectory(MAX_PATH, szCurrentDir);
	PathRelativePathTo(szRelativePath, szCurrentDir, FILE_ATTRIBUTE_DIRECTORY, _strFullPath.c_str(), FILE_ATTRIBUTE_DIRECTORY);

	return tstring(szRelativePath);
}

//void CFilePath::DirInfoExtraction(const tstring & _strFilePath, list<FILEINFO*>& _listFileInfo)
//{
//	CFileFind find;
//	tstring strFullPath = _strFilePath + _T("\\*.*");
//	BOOL bLoop = find.FindFile(strFullPath.c_str());
//
//	while (bLoop)
//	{
//		bLoop = find.FindNextFile();
//
//		// 앞으로, 뒤로
//		if (find.IsDots())
//			continue;
//
//		// 폴더료시카
//		else if (find.IsDirectory())
//		{
//			DirInfoExtraction(find.GetFilePath().GetString(), _listFileInfo);
//		}
//
//		// 파일
//		else
//		{
//			if (find.IsSystem())
//				continue;
//
//			// 하나만 구해서 값 셋팅
//			FILEINFO* pFileInfo = new FILEINFO;
//			TCHAR szPathBuf[MAX_PATH];
//			ZeroMemory(szPathBuf, sizeof(szPathBuf));
//
//			StringCchCopy(szPathBuf, _countof(szPathBuf), find.GetFilePath());
//			PathRemoveFileSpec(szPathBuf);
//			pFileInfo->iCount = CFilePath::DirFileCount(szPathBuf);
//
//			tstring strTextureName = find.GetFileTitle().GetString();
//			strTextureName = strTextureName.substr(0, strTextureName.length() - 1) + _T("%d.png");
//
//			TCHAR szCompletePath[MAX_PATH] = _T("");
//			PathCombine(szCompletePath, szPathBuf, strTextureName.c_str());
//
//			pFileInfo->strFilePath = CFilePath::ConvertRelativePath(szCompletePath);
//
//			PathRemoveFileSpec(szCompletePath);
//			pFileInfo->strStateKey = PathFindFileName(szCompletePath);
//
//			PathRemoveFileSpec(szCompletePath);
//			pFileInfo->strObjectKey = PathFindFileName(szCompletePath);
//
//			_listFileInfo.emplace_back(pFileInfo);
//			bLoop = FALSE;
//		}
//	}
//}

int CFilePath::DirFileCount(const tstring & _strFilePath)
{
	CFileFind find;
	tstring strFullPath = _strFilePath + _T("\\*.*");
	BOOL bLoop = find.FindFile(strFullPath.c_str());
	int iCnt = 0;
	while (bLoop)
	{
		bLoop = find.FindNextFile();
		if (find.IsDots() || find.IsSystem())
			continue;

		++iCnt;
	}

	return iCnt;
}
