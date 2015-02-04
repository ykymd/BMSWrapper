#include "FileReader.hpp"
#include "Lexer.h"
#include "Parser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <list>

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
void FileReader::loadByStream(const char* filePath)
{
	ifstream ifs(filePath);
	Lexer lexer;	// 字句解析器
	Parser parser;	// 構文解析器

	if (ifs.fail())
	{
		cout << "Can't open file" << endl;
		return;
	}

	string line;	// 読み込み用文字列
	list<string> word;	//字句解析後文字列

	while (getline(ifs, line))
	{
		// 読み込んだ行から解析を行う
		cout << line << endl;

		// 字句解析を行う
		string cmd = get<0>(lexer.tokenize(line, ':', '#'));

		auto num = parser.commandTypeInterface(cmd.c_str(), cmd.length());
		
		if (num != -1 && num != -2){
			cout << "	" <<cmd << endl;
			cout << "	" <<num << endl;
		}
	}

	ifs.close();
}

void FileReader::loadByDxLib(const char* filePath)
{
}