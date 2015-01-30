#pragma once
#include <string>
#include <queue>

class Tokenizer
{
public:
	Tokenizer();
	~Tokenizer();

private:
	std::queue<std::string> wordList;
	void bmsTokenize(std::string str);
};

