#include "Parser.h"
#include "Commands.h"

#include <string>

using namespace BMS::BM98;

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool isNumber(const char* str, int size)
{
	// ��������5�łȂ���΋K�i�O�Ƃ݂Ȃ�
	if (size != 5) return false;

	for (auto i = 0; i<size; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}

	return true;
}

int Parser::commandTypeInterface(const char* command, int size)
{
	// �I�u�W�F�N�g�z�u�̌`('#iiiii')��
	// �R�}���h���������ׂĐ��l�ł���Ȃ�I�u�W�F�z�u�Ƃ��ĕԂ�
	if (isNumber(command, size))
		return OBJECT;
	
	// �K�肳�ꂽ�R�}���h�ł��邩
	auto cnt = 0;
	for (auto pattern : BMS_COMMANDS)
	{
		// �召������ʂ�����������r
		if (_strnicmp(pattern.c_str(), command, pattern.length()) == 0)
			return cnt;

		cnt++;
	}

	// �ǂ�ɂ����Ă͂܂�Ȃ���Δ��ʕs�\�����Ƃ��ĕԂ�
	return UNKNOWN;
}
