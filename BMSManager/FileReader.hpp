//
// BMS�t�@�C������f�[�^��ǂݏo��
//
#pragma once

namespace BMS {

	class FileReader
	{
	public:
		FileReader();
		~FileReader();

		void load(const char* filePath);
		void loadByStream(const char* filePath); // STL��ifstream�ɂ��ǂݍ���
		void loadByDxLib(const char* filePath);	// DX���C�u�����֐��ɂ��ǂݍ���
	};

}
