#pragma once

#include <string>
#include <unordered_map>

namespace BMS {

	class Header
	{
	public:
		Header();
		~Header();

		int player;	// ƒvƒŒƒCl”
		std::string genre;
		std::string title;
		std::string artist;
		int bpm;
		int playLevel;
		int rank;
		int volWav;
		float total;
		std::unordered_map<int, std::string> wav;
		std::unordered_map<int, std::string> bmp;
		std::string stageFile;
		std::string midiFile;	// deprecated
	};

}
