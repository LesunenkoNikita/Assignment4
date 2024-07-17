#define _CRT_SECURE_NO_WARNINGS
#include "TextEditor.h"
#include "CaesarCipher.h"
using namespace std;
#include <iostream>


void TextEditor::appendText(Text &text, char* input)
{
	if (sizeof(input) > (text.getColumnAmount() - sizeof(text.getText()[text.getCurRow()])))
	{
		text.reallocCollumns();
	}
	int idx = 0;
	for (idx; idx < strlen(text.getText()[text.getCurRow()]); idx++)
	{
		if (text.getText()[text.getCurRow()][idx] == '\0')
		{
			break;
		}
	}
	for (int i = 0; i < strlen(input) - 1; i++)
	{
		text.getText()[text.getCurRow()][idx] = input[i];
		idx++;
	}
	text.getText()[text.getCurRow()][idx] = '\0';
	free(input);
}

void TextEditor::newLine(Text &text)
{
	if (text.getCurRow() + 1 == text.getRowsAmount())
	{
		text.reallocRows();
	}
	text.setCurRow((text.getCurRow())+1);
	text.getText()[text.getCurRow()][0] = '\0';
	printf("New line is started!\n");
}

void TextEditor::textPrint(Text &text)
{
	for (int r = 0; r <= text.getCurRow(); r++)
	{
		printf(text.getText()[r]);
		printf("\n");
	}
}

void TextEditor::saveToFile(Text &text, char* path)
{
	FILE* file = fopen(path, "w");
	if (file != NULL)
	{
		for (int r = 0; r <= text.getCurRow(); r++)
		{
			fputs(text.getText()[r], file);
			fputs("\n", file);
		}
	}
	fclose(file);
}

void TextEditor::loadFromFile(Text &text, char* path)
{
	char lineFromFile[256];
	int row = 0;
	FILE* file = fopen(path, "r");
	while (fgets(lineFromFile, 256, file) != NULL)
	{
		strcpy(text.getText()[row], lineFromFile);
		row++;
	}
	text.setCurRow(row);
	text.getText()[text.getCurRow() - 1][strlen(text.getText()[text.getCurRow() - 1])] = '\0';
	fclose(file);
}

void TextEditor::search(Text &text, char* word)
{
	int i = 0;
	for (int r = 0; r <= text.getCurRow(); r++)
	{
		for (int j = 0; j < strlen(text.getText()[r]); j++)
		{
			if (text.getText()[r][j] == word[i])
			{
				if (i == strlen(word) - 1)
				{
					printf("The word you search is in row %d starting on index %d\n", r, j - strlen(word) + 1);
					i = 0;
				}
				else
				{
					i++;
				}
			}
			else
			{
				i = 0;
			}
		}
	}
}

void TextEditor::insertText(Text &text, int row, int idx)
{
	if (row > text.getRowsAmount() || row < 0 || idx < 0 || idx > text.getColumnAmount())
	{
		printf("Wrong input! Exiting...");
		exit(1);
	}
	printf("Enter text to insert: ");
	char word[256];
	fgets(word, 256, stdin);
	word[strcspn(word, "\n")] = '\0';
	if (sizeof(word) > (text.getColumnAmount() - sizeof(text.getText()[row])))
	{
		text.setColumnAmount((text.getColumnAmount())*2);
		for (int i = 0; i < text.getRowsAmount(); i++)
		{
			text.getText()[i] = (char*)realloc(text.getText()[i], text.getColumnAmount() * sizeof(char));
		}
	}
	int len = strlen(word);
	for (int i = strlen(text.getText()[row]); i >= idx; i--)
	{
		text.getText()[row][i + len] = text.getText()[row][i];
	}
	for (int n = 0; n < len; n++)
	{
		text.getText()[row][idx] = word[n];
		idx++;
	}
}

void TextEditor::caesar(Text& text, int command, char* inputPath, char* outputPath, int key)
{
	try
	{
		CaesarCipher cipher;
		if (command == 1)
		{
			FILE* outputFile = fopen(outputPath, "r");
			FILE* inputFile = fopen(inputPath, "w");
			char lineFromFile[256];
			while (fgets(lineFromFile, 256, outputFile) != NULL)
			{
				fputs(cipher.encryptText(lineFromFile, key), inputFile);
				fputs("\n", inputFile);
			}
			fclose(inputFile);
			fclose(outputFile);
		}
		else if (command == 2)
		{
			FILE* outputFile = fopen(outputPath, "r");
			FILE* inputFile = fopen(inputPath, "w");
			char lineFromFile[256];
			while (fgets(lineFromFile, 256, outputFile) != NULL)
			{
				fputs(cipher.decryptText(lineFromFile, key), inputFile);
			}
			fclose(inputFile);
			fclose(outputFile);
		}
	}
	catch (...)
	{
		cout << "Caesar cipher functions are not available!" << endl;
	}
}
