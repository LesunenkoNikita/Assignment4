#include "CaesarCipher.h"
#include <iostream>
using namespace std;

CaesarCipher::CaesarCipher() 
{
	handle = LoadLibrary(TEXT("C:\\Users\\User\\source\\repos\\Assignment3\\Assignment3\\Assignment3\\caesar.dll"));
	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		cout << "Lib not found" << endl;
	}
	encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
	if (encrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
	}
	decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
	if (decrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
	}	
}

CaesarCipher::~CaesarCipher() 
{
	FreeLibrary(handle);
}

char* CaesarCipher::encryptText(char* rawText, int key) 
{
	char* text = encrypt_ptr(rawText, key);
	text[strlen(text)] = '\0';
	return text;
}
char* CaesarCipher::decryptText(char* encryptedText, int key)
{
	char* text = decrypt_ptr(encryptedText, key);
	text[strlen(text)] = '\0';
	return text;
}