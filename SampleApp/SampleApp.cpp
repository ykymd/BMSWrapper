// SampleApp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
	Lexer lexer;	// 字句解析器
	tuple<string, string> words;

	for (auto line : file.data)
	{
		// 字句解析
		words = lexer.tokenize(line, ':', '#');

		// 空文字列は除外する
		if (get<0>(words).size() == 0)
			continue;

		cout << get<0>(words) << endl;
		cout << get<1>(words) << endl;
	}


	return 0;
}
