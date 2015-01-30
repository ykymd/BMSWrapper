//
// 譜面データを格納するクラス
//

#pragma once
#include "BMSHeader.h"

namespace BMS {

	class Chart
	{
	public:
		Chart(const char* fileName);
		~Chart();
	private:
		Header header;

		bool openFile();
	};

}
