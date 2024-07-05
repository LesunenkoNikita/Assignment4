#include "Text.h"
using namespace std;
#include <iostream>

Text::Text()
{
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

char** Text::getText(void) const
{
	return text;
}

void Text::setText(char** newText)
{
	int i = 0;
	while (newText[i] != NULL)
	{
		strcpy(text[i], newText[i]);
		i++;
	}
	curRow = i;
	text[curRow - 1][strlen(text[curRow - 1])] = '\0';
}

int Text::getCurRow(void)
{
	return curRow;
}

void Text::setCurRow(int row)
{
	curRow = row;
}

int Text::getColumnAmount(void)
{
	return columnAmount;
}

void Text::setColumnAmount(int columns)
{
	columnAmount = columns;
}

int Text::getRowsAmount(void)
{
	return rowsAmount;
}

int Text::setRowsAmount(int rows)
{
	rowsAmount = rows;
}

int const Text::getBufferSize(void)
{
	return bufferSize;
}

void Text::reallocCollumns(void)
{
	columnAmount *= 2;
	for (int i = 0; i < rowsAmount; i++)
	{
		text[i] = (char*)realloc(text[i], columnAmount * sizeof(char));
	}
}

void Text::reallocRows(void)
{
	rowsAmount *= 2;
	text = (char**)realloc(text, rowsAmount * sizeof(char*));
	for (int i = curRow + 1; i < rowsAmount; i++)
	{
		text[i] = (char*)realloc(text[i], columnAmount * sizeof(char));
	}
}
