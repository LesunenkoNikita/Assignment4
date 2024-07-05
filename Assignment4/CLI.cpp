#include "CLI.h"
using namespace std;
#include <iostream>
#include "Text.h"
#include "CaesarCipher.h"
#include "TextEditor.h"
#include <string>

CLI::CLI()
{
	Text text;
	CaesarCipher cipher;
	TextEditor editor;
	printf("All available commands:\n\
1 - To append text symbols to the end\n\
2 - To start a new line\n\
3 - To save the text into a file\n\
4 - To load the text from the file\n\
5 - To print current text to console\n\
6 - To search text\n\
7 - To insert the text by line and symbol index\n\
8 - To encrypt or decrypt text\n");
	while (1)
	{
		printf("Enter the command: ");
		int command = commandOrKey();
		if (command == 1)
		{
			editor.appendText(text);
			continue;
		}
		else if (command == 2)
		{
			editor.newLine(text);
			continue;
		}
		else if (command == 3)
		{
			editor.saveToFile(text);
			continue;
		}
		else if (command == 4)
		{
			editor.loadFromFile(text);
			continue;
		}
		else if (command == 5)
		{
			editor.textPrint(text);
			continue;
		}
		else if (command == 6)
		{
			editor.search(text);
			continue;
		}
		else if (command == 7)
		{
			editor.insertText(text);
			continue;
		}
		else if (command == 8)
		{
			printf("1 - encrypt text, 2 - decrypt text\n");
			command = commandOrKey();
			printf("Enter input file path: ");
			char* inputPath = file();
			printf("Enter output file path: ");
			char* outputPath = file();
			printf("Enter the key: ");
			int key = commandOrKey();
			editor.caesar(text, cipher, command, inputPath, outputPath, key);
			continue;
		}
		else
		{
			printf("Wrong input! Exiting...");
			exit(1);
		}
	}
}

int CLI::commandOrKey(void)
{
	char key_input[16];
	fgets(key_input, 16, stdin);
	key_input[strcspn(key_input, "\n")] = '\0';
	int key = atoi(key_input);
	return key;
}

char* CLI::file(void)
{
	char* path = new char[256];
	fgets(path, 256, stdin);
	path[strcspn(path, "\n")] = '\0';
	return path;
}