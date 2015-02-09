#pragma once

class Parser
{
public:
	Parser();
	~Parser();

	void parse();

	// コマンド部分の型推論を行う
	int commandTypeInterface(const char* command, int size);
};
