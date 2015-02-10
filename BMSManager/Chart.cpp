#include "Chart.h"
#include "FileReader.hpp"
#include "Lexer.h"
#include "Tokenizer.h"
#include "Commands.h"
#include <ctype.h>

#include <iostream>

using namespace BMS;
using namespace BMS::BM98;
using namespace std;

const int DIGIT = 36;	//0~9,A~Zの36進数を利用する

int getChannel(string command)
{
	string str = command.substr(3, 2);
	int channel = 0;

	for (auto c : str)
	{
		// 文字がラテン数字の場合
		if (c >= '0' && c <= '9')
			channel += c - '0';
		// 文字が大文字アルファベットの場合
		else if (isupper(c) != 0)
			channel += c - 'A' + 10;
		else if (islower(c) != 0)
			channel += c - 'a' + 10;

		channel *= DIGIT;
	}

	return channel;
}

Chart::Chart(const char* fileName)
{
	FileReader file(fileName); // ファイルの読み出し
	Lexer lexer;	// 字句解析器
	Tokenizer tokenizer;	// トークン分割器

	tuple<string, string> words;	// 各行をコマンド部とデータ部に分割したもの
	string command, data;			// 各行のコマンド部とデータ部

	// 読み取りファイルの文字列の解析
	for (auto line : file.data)
	{
		// 単語分割
		words = lexer.tokenize(line, ':', '#');
		command = get<0>(words);
		data = get<1>(words);

		// 空文字列は除外する
		if (command.size() == 0)
			continue;

		// 型判定
		auto type = tokenizer.getType(command);

		// チャンネル指定が必要なものは、チャンネル取得を行う
		auto channel = 0;
		if (type == WAV || type == BMP || type == OBJECT)
			channel = getChannel(command);

		// データ格納
		// オブジェクトのみ特殊な処理を行う
		if (type == OBJECT)
			setObject(stoi(command.substr(0, 3)), channel, data);
		else
			setData(type, channel, data);
	}
}

Chart::~Chart()
{
}

void Chart::setData(int type, int channel, string data)
{
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
		bpmChange.push_back(tuple<int, int>(0, stoi(data)));
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
		header.total = stof(data);
		break;
	case WAV:
		header.wav[channel] = data;
		break;
	case BMP:
		header.bmp[channel] = data;
		break;
	case STAGEFILE:
		header.stageFile = data;
		break;
	case MIDIFILE:
		header.midiFile = data;
		break;
	}
}

void Chart::setObject(int measure, int channel, string data)
{

}