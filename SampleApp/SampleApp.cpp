// SampleApp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "FileReader.hpp"
#include "Lexer.h"

using namespace std;
using namespace BMS;

//void math();

int main()
{
	FileReader file;
	file.loadByStream("kotohurunushi_hard.bme");

	//string str = "#PLAYER 1";
	//Lexer lexer;
	//lexer.split(str,' ');

	//cout << get<0>(lexer.tokenize("#PLAYER 1", ":", '#')) << endl;

	return 0;
}

/*
void math()
{
	double a = 7.4;
	int b = 99;

	cout << "a + b = " <<
		MathFuncs::MyMathFuncs::Add(a, b) << endl;
	cout << "a - b = " <<
		MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
	cout << "a * b = " <<
		MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
	cout << "a / b = " <<
		MathFuncs::MyMathFuncs::Divide(a, b) << endl;
}
*/