//
// BMSファイルからデータを読み出す
//
#pragma once

namespace BMS {
	class FileReader
	{
	public:
		FileReader();
		~FileReader();

		void load(const char* filePath);
		void loadByStream(const char* filePath); // STLのifstreamによる読み込み
		void loadByDxLib(const char* filePath);	// DXライブラリ関数による読み込み
	};
}
