#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace BMS;
using namespace std;

// ファイル名を指定して読み込み
FileReader::FileReader(){}

FileReader::~FileReader(){}

// ファイルパスを指定して読み込み
void FileReader::load(const char* filePath)
{
	loadByStream(filePath);
}

// STLのifstreamによる読み込み
void loadByStream(const char* filePath)
{
	ifstream ifs(filePath);
	if (ifs.fail())
	{
		throw "Can't open file";
	}

	string line;	// 読み込み用文字列

	while (getline(ifs, line))
	{
		// 読み込んだ行から解析を行う
	}

	ifs.close();
}