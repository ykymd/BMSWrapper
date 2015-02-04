#include "FileReader.hpp"
#include "Lexer.h"
#include "Parser.h"

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
	Parser parser;	// �\����͊�

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