// SampleApp.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include "FileReader.hpp"
#include "Lexer.h"

#include <iostream>
#include <tuple>

using namespace std;
using namespace BMS;

//void math();

int main()
{
	FileReader file("kotohurunushi_hard.bme");
	Lexer lexer;	// �����͊�
	tuple<string, string> words;

	for (auto line : file.data)
	{
		// ������
		words = lexer.tokenize(line, ':', '#');

		// �󕶎���͏��O����
		if (get<0>(words).size() == 0)
			continue;

		cout << get<0>(words) << endl;
		cout << get<1>(words) << endl;
	}


	return 0;
}
