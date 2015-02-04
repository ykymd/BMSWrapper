#include "Lexer.h"
#include "Commands.h"

#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;
using namespace BMS::BM98;

Lexer::Lexer()
{
}


Lexer::~Lexer()
{
}

tuple<string, string> Lexer::tokenize(const string &line, char delimiter, char head)
{
	tuple<string, string> t;
	// '#'で始まる行以外は全てコメント行とする
	//if (line.substr(0, 1).compare(head) != 0)
	if (line[0] != head)
		return t;

	// コマンド部とデータ部に分割する
	return split(line.substr(1), delimiter);
}

// 要素数2つのタプルに分割する
// TODO: タプル数を汎用的にする
tuple<string, string> Lexer::split(string &str, char delim)
{
	tuple<string, string> devide;
	
	auto length = str.length();

	for (auto i = 0; i < length; i++)
	{
		if (str[i] == delim || str[i] == ' ' || str[i] == '　')
		{
			get<0>(devide) = str.substr(0, i);
			get<1>(devide) = str.substr(i + 1);
			break;
		}
	}

	return devide;
}
