#include "Parser.h"
#include "Commands.h"

using namespace BMS;
using namespace BMS::BM98;

Parser::Parser()
{
}

Parser::~Parser()
{
}

void Parser::parse(int type, const tuple<string, string> &words, Header &header)
{
	/*
	auto data = get<1>(words);
	switch (type)
	{
	case PLAYER:
		header.player = stoi(data);
		break;
	case GENRE:
		header.genre = data;
		break;
	case TITLE:
		header.title = data;
		break;
	case ARTIST:
		header.artist = data;
		break;
	case BPM:
		header.bpm = stoi(data);
		break;
	case PLAYLEVEL:
		header.playLevel = stoi(data);
		break;
	case RANK:
		header.rank = stoi(data);
		break;
	case VOLWAV:
		header.volWav = stoi(data);
		break;
	case TOTAL:
		header.total = stoi(data);
		break;
	case WAV:
		auto index = get<0>(words).substr(3,2);
		header.wav.at(index) = stoi(data);
		break;
	case BMP:
		auto index = get<0>(words).substr(3, 2);
		header.bmp.at(index) = stoi(data);
		break;
	case STAGEFILE:
		header.stageFile = data;
		break;
	case MIDIFILE:
		break;
	case OBJECT:
		break;
	default:
		
	}
	*/
}
