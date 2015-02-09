#include "Chart.h"
#include "FileReader.hpp"
#include "Lexer.h"

using namespace BMS;
using namespace std;

Chart::Chart(const char* fileName)
{
	FileReader file(fileName); // �t�@�C���̓ǂݏo��
	Lexer lexer;	// �����͊�
	tuple<string, string> words;	// �e�s���R�}���h���ƃf�[�^���ɕ�����������

	// �ǂݎ��t�@�C���̕�����̉��
	for (auto line : file.data)
	{
		// ������
		words = lexer.tokenize(line, ':', '#');

		// �󕶎���͏��O����
		if (get<0>(words).size() == 0)
			continue;

		// �\�����

	}


}

Chart::~Chart()
{
}
