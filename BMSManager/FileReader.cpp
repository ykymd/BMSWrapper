#include "FileReader.hpp"
#include "Lexer.h"

#include <fstream>
#include <iostream>
#include <string>
#include <list>

using namespace BMS;
using namespace std;

// �t�@�C�������w�肵�ēǂݍ���
FileReader::FileReader(){}

FileReader::~FileReader(){}

// �t�@�C���p�X���w�肵�ēǂݍ���
void FileReader::load(const char* filePath)
{
	loadByStream(filePath);
}

// STL��ifstream�ɂ��ǂݍ���
void FileReader::loadByStream(const char* filePath)
{
	ifstream ifs(filePath);
	Lexer lexer;	// �����͊�

	if (ifs.fail())
	{
		cout << "Can't open file" << endl;
		return;
	}

	string line;	// �ǂݍ��ݗp������
	list<string> word;	//�����͌㕶����

	while (getline(ifs, line))
	{
		// �ǂݍ��񂾍s�����͂��s��
		cout << line << endl;

		// �����͂��s��
		cout << get<0>(lexer.tokenize(line, ':', '#')) << endl;
		//word = lexer.tokenize(line, " �@:", '#');
		//cout << word.front() << endl;
	}

	ifs.close();
}

void FileReader::loadByDxLib(const char* filePath)
{
}