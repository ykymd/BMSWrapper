// SampleApp.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "Chart.h"
#include <iostream>

using namespace std;
using namespace BMS;

int main()
{
	Chart chart("kotohurunushi_hard.bme");

	cout << "TITLE:" << chart.getTitle() << endl;
	cout << "ARTIST:" << chart.getArtist() << endl;
	cout << "GENRE:" << chart.getGenre() << endl;

	return 0;
}
