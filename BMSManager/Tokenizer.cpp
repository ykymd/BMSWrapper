#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer()
{
}


Tokenizer::~Tokenizer()
{
}

// BMS形式の字句解析を行う
void bmsTokenize(std::string str)
{
	// '#'で始まる行以外は全てコメント行とする
	if (str.substr(0, 1).compare("#") != 0)
		return;


}