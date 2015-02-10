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

const int DIGIT = 36;	//0~9,A~Z��36�i���𗘗p����

int getChannel(string command)
{
	string str = command.substr(3, 2);
	int channel = 0;

	for (auto c : str)
	{
		// ���������e�������̏ꍇ
		if (c >= '0' && c <= '9')
			channel += c - '0';
		// �������啶���A���t�@�x�b�g�̏ꍇ
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
	FileReader file(fileName); // �t�@�C���̓ǂݏo��
	Lexer lexer;	// �����͊�
	Tokenizer tokenizer;	// �g�[�N��������

	tuple<string, string> words;	// �e�s���R�}���h���ƃf�[�^���ɕ�����������
	string command, data;			// �e�s�̃R�}���h���ƃf�[�^��

	// �ǂݎ��t�@�C���̕�����̉��
	for (auto line : file.data)
	{
		// �P�ꕪ��
		words = lexer.tokenize(line, ':', '#');
		command = get<0>(words);
		data = get<1>(words);

		// �󕶎���͏��O����
		if (command.size() == 0)
			continue;

		// �^����
		auto type = tokenizer.getType(command);

		// �`�����l���w�肪�K�v�Ȃ��̂́A�`�����l���擾���s��
		auto channel = 0;
		if (type == WAV || type == BMP || type == OBJECT)
			channel = getChannel(command);

		// �f�[�^�i�[
		// �I�u�W�F�N�g�̂ݓ���ȏ������s��
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