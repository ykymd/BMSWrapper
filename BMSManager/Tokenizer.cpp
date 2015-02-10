#include "Tokenizer.h"
#include "Commands.h"

using namespace BMS;
using namespace BMS::BM98;

Tokenizer::Tokenizer() {}

Tokenizer::~Tokenizer() {}

bool isNumber(const char* str, int size)
{
	// 文字数が5でなければ規格外とみなす
	if (size != 5) return false;

	for (auto i = 0; i<size; i++) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}

	return true;
}

int Tokenizer::getType(string command)
{
	// オブジェクト配置の形('#iiiii')か
	// コマンド部分がすべて数値であるならオブジェ配置として返す
	if (isNumber(command.c_str(), command.size()))
		return OBJECT;

	// 規定されたコマンドであるか
	auto cnt = 0;
	for (auto pattern : BMS_COMMANDS)
	{
		// 大小文字区別せず文字列を比較
		if (_strnicmp(pattern.c_str(), command.c_str(), pattern.length()) == 0)
			return cnt;

		cnt++;
	}

	// どれにも当てはまらなければ判別不可能文字として返す
	return UNKNOWN;
}