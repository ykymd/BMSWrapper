//
// 譜面データを格納するクラス
//

#pragma once
#include "BMSHeader.h"
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef tuple<int, string> BackChorus;
typedef tuple<int, float> BarMagni;
typedef tuple<int, int> BPMChange;
typedef tuple<int, string> BGAChange;
typedef tuple<int, string> BMPChange;


namespace BMS {

	class Chart
	{
	public:
		Chart(const char* fileName);
		~Chart();

		int getPlayer(){ return header.player; };
		string getGenre(){ return header.genre; };
		string getTitle(){ return header.title; };
		string getArtist(){ return header.artist; };
		int getIndexBPM(){ return header.bpm; };
		int getPlayLevel(){ return header.playLevel; };
		int getRank(){ return header.rank; };
		int getVolWav(){ return header.volWav; };
		float getTotal(){ return header.total; };
		const unordered_map<int,string>& getWav(){ return header.wav; };
		const unordered_map<int,string>& getBMP(){ return header.bmp; };
		string getStageFile(){ return header.stageFile; };
		string getMidiFile(){ return header.midiFile; };
	private:
		std::string fileName;
		Header header;

		void setData(int type, int channel, std::string data);
		void setObject(int measure, int channel, std::string data);

		vector<BackChorus> backChorus;	// チャンネル01
		vector<BarMagni> barMagni;		// チャンネル02
		vector<BPMChange> bpmChange;	// チャンネル03
		vector<BMPChange> poorBmpChange;// チャンネル06

	};
}
