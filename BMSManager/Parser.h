#pragma once

class Parser
{
public:
	Parser();
	~Parser();

	void parse();

	// �R�}���h�����̌^���_���s��
	int commandTypeInterface(const char* command, int size);
};
