#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer()
{
}


Tokenizer::~Tokenizer()
{
}

// BMS�`���̎����͂��s��
void bmsTokenize(std::string str)
{
	// '#'�Ŏn�܂�s�ȊO�͑S�ăR�����g�s�Ƃ���
	if (str.substr(0, 1).compare("#") != 0)
		return;


}