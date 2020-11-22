#pragma once
#ifndef __FILEPATH_H__
#define __FILEPATH_H__


class CFilePath final
{
public:
	CFilePath();
	~CFilePath();

public:
	static tstring	ConvertRelativePath(const tstring& _strFullPath);
//	static void		DirInfoExtraction(const tstring& _strFilePath, list<FILEINFO*>& _listFileInfo);
	static int		DirFileCount(const tstring& _strFilePath);
};


#endif // !__FILEPATH_H__
