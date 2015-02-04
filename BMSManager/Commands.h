//
// BMSのコマンド一覧
//
#pragma once
#include <string>

namespace BMS
{
	namespace BM98
	{
		const int COMMAND_NUMBER = 13;

		// enumにすべきか？
		const int PLAYER	= 0;
		const int GENRE		= 1;
		const int TITLE		= 2;
		const int ARTIST	= 3;
		const int BPM		= 4;
		const int PLAYLEVEL = 5;
		const int RANK		= 6;
		const int VOLWAV	= 7;
		const int TOTAL		= 8;
		const int WAV		= 9;
		const int BMP		= 10;
		const int STAGEFILE = 11;
		const int MIDIFILE	= 12;
		const int OBJECT	= -1;
		const int UNKNOWN	= -2;

		const std::string BMS_COMMANDS[COMMAND_NUMBER] = {
			"PLAYER",
			"GENRE",
			"TITLE",
			"ARTIST",
			"BPM",
			"PLAYLEVEL",
			"RANK",
			"VOLWAV",
			"TOTAL",
			"WAV",
			"BMP",
			"STAGEFILE",
			"MIDIFILE",
		};
	}
}