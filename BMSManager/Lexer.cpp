#include "Lexer.h"

#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}

tuple<string, string> Lexer::tokenize(const string &line, char delimiter, char head)
{
	tuple<string, string> t;
	// '#'�Ŏn�܂�s�ȊO�͑S�ăR�����g�s�Ƃ���
	//if (line.substr(0, 1).compare(head) != 0)
	if (line[0] != head)
		return t;

	// �R�}���h���ƃf�[�^���ɕ�������
	return split(line.substr(1), delimiter);
}

// �v�f��2�̃^�v���ɕ�������
// TODO: �^�v������ėp�I�ɂ���
tuple<string, string> Lexer::split(string &str, char delim)
{
	tuple<string, string> devide;
	
	auto length = str.length();

	for (auto i = 0; i < length; i++)
	{
		if (str[i] == delim || str[i] == ' ' || str[i] == '�@')
		{
			get<0>(devide) = str.substr(0, i);
			get<1>(devide) = str.substr(i + 1);
			break;
		}
	}

	return devide;
}
