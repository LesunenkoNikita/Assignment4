#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include "Text.h"
#include "CaesarCipher.h"
class TextEditor
{
public:
	void appendText(Text &text, char* input);
	void newLine(Text &text);
	void textPrint(Text &text);
	void saveToFile(Text &text, char* path);
	void loadFromFile(Text &text, char* path);
	void search(Text &text, char* word);
	void insertText(Text &text, int row, int idx);
	void caesar(Text &text, int command, char* inputPath, char* outputPath, int key);
};

#endif TEXTEDITOR_H