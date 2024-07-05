#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include "Text.h"
#include "CaesarCipher.h"
class TextEditor
{
public:
	void appendText(Text &text);
	void newLine(Text &text);
	void textPrint(Text &text);
	void saveToFile(Text &text);
	void loadFromFile(Text &text);
	void search(Text &text);
	void insertText(Text &text);
	void caesar(Text &text, CaesarCipher cipher, int command, char* inputPath, char* outputPath, int key);
};

#endif TEXTEDITOR_H