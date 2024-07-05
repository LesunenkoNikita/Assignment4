#include "Text.h"
using namespace std;
#include <iostream>

Text::Text()
{
	bufferSize = 256;
	columnAmount = 256;
	rowsAmount = 10;
	curRow = 0;
	text = (char**)calloc(rowsAmount, sizeof(char*));
	for (int i = 0; i < rowsAmount; i++)
	{
		text[i] = (char*)calloc(columnAmount, sizeof(char));
		if (text[i] == 0)
		{
			cout << "Memory callocation failed! Exiting..." << endl;
			exit(1);
		}
	}
	text[0][0] = '\0';
}

Text::~Text()
{
	for (int i = 0; i < rowsAmount; i++)
	{
		free(text[i]);
	}
	free(text);
}