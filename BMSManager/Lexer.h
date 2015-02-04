#pragma once
#include <string>
#include <tuple>

using namespace std;

class Lexer
{
public:
	Lexer();
	~Lexer();

	tuple<string, string> tokenize(const string &line, char delimiter, char head);

private:
	tuple<string, string> split(string &str, char delim);
};
