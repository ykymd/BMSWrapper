//
// BMS�t�@�C������f�[�^��ǂݏo��
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

		void loadByStream(const char* filePath); // STL��ifstream�ɂ��ǂݍ���
		void loadByDxLib(const char* filePath);	// DX���C�u�����֐��ɂ��ǂݍ���
	
		std::vector<std::string> data;
	};

}
