#include "CaesarCipher.h"
#include <iostream>
using namespace std;

CaesarCipher::CaesarCipher()
{
	handle = LoadLibrary(TEXT("C:\\Users\\User\\source\\repos\\Assignment3\\Assignment3\\Assignment3\\caesar.dll"));
	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		throw "Function not found";
	}
	encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
	if (encrypt_ptr == nullptr)
	{
		throw "Function not found";
	}
	decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
	if (decrypt_ptr == nullptr)
	{
		throw "Function not found";
	}
}

CaesarCipher::~CaesarCipher() 
{
	FreeLibrary(handle);
}

char* CaesarCipher::encryptText(char* rawText, int key) 
{
	char* text = encrypt_ptr(rawText, key);
	return text;
}
char* CaesarCipher::decryptText(char* encryptedText, int key)
{
	char* text = decrypt_ptr(encryptedText, key);
	return text;
}