//
// 譜面データを格納するクラス
//

#pragma once
#include "BMSHeader.h"
#include <vector>
#include <tuple>

namespace BMS {

	class Chart
	{
	public:
		Chart(const char* fileName);
		~Chart();
	private:
		std::string fileName;
		Header header;

		void setData(int type, int channel, std::string data);
		void setObject(int measure, int channel, std::string data);

		vector<tuple<int,std::string>> backChorus;	// チャンネル01
		vector<tuple<int, float>> barMagni;			// チャンネル02
		vector<tuple<int, int>> bpmChange;			// チャンネル03
	};
}
