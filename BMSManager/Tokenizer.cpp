#include "Tokenizer.h"
#include "Commands.h"

using namespace BMS;
using namespace BMS::BM98;

Tokenizer::Tokenizer() {}

Tokenizer::~Tokenizer() {}

bool isNumber(const char* str, int size)
{
	// ��������5�łȂ���΋K�i�O�Ƃ݂Ȃ�
	if (size != 5) return false;

	for (auto i = 0; i<size; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}

	return true;
}

int Tokenizer::getType(string command)
{
	// �I�u�W�F�N�g�z�u�̌`('#iiiii')��
	// �R�}���h���������ׂĐ��l�ł���Ȃ�I�u�W�F�z�u�Ƃ��ĕԂ�
	if (isNumber(command.c_str(), command.size()))
		return OBJECT;

	// �K�肳�ꂽ�R�}���h�ł��邩
	auto cnt = 0;
	for (auto pattern : BMS_COMMANDS)
	{
		// �召������ʂ�����������r
		if (_strnicmp(pattern.c_str(), command.c_str(), pattern.length()) == 0)
			return cnt;

		cnt++;
	}

	// �ǂ�ɂ����Ă͂܂�Ȃ���Δ��ʕs�\�����Ƃ��ĕԂ�
	return UNKNOWN;
}