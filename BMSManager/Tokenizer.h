#pragma once

#include <string>
#include <tuple>

using namespace std;

namespace BMS
{
	class Tokenizer
	{
	public:
		Tokenizer();
		~Tokenizer();

		int getType(string command); // �\����͂����s����
	};
}
