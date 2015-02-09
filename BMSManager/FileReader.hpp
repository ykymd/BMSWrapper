//
// BMSファイルからデータを読み出す
//
#pragma once
#include <vector>
#include <string>

namespace BMS {

	class FileReader
	{
	public:
		FileReader(const char* filePath);
		~FileReader();

		void loadByStream(const char* filePath); // STLのifstreamによる読み込み
		void loadByDxLib(const char* filePath);	// DXライブラリ関数による読み込み
	
		std::vector<std::string> data;
	};

}
