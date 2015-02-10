#pragma once
#include <tuple>
#include <string>
#include "BMSHeader.h"

using namespace std;

namespace BMS
{
	class Parser
	{
	public:
		Parser();
		~Parser();

		void parse(int type, const tuple<string, string> &words, Header &header);
	};
}
