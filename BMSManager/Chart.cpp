#include "Chart.h"
#include "FileReader.hpp"
#include "Lexer.h"

using namespace BMS;
using namespace std;

Chart::Chart(const char* fileName)
{
	FileReader file(fileName); // ファイルの読み出し
	Lexer lexer;	// 字句解析器
	tuple<string, string> words;	// 各行をコマンド部とデータ部に分割したもの

	// 読み取りファイルの文字列の解析
	for (auto line : file.data)
	{
		// 字句解析
		words = lexer.tokenize(line, ':', '#');

		// 空文字列は除外する
		if (get<0>(words).size() == 0)
			continue;

		// 構文解析

	}


}

Chart::~Chart()
{
}
