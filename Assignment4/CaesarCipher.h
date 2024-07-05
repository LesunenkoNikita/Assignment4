#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <Windows.h>


class CaesarCipher
{
public:
	CaesarCipher();
	~CaesarCipher();
	char* encryptText(char* rawText, int key);
	char* decryptText(char* encryptedText, int key);
private:
	typedef char* (*encrypt_ptr_t)(char*, int);
	typedef char* (*decrypt_ptr_t)(char*, int);
	HINSTANCE handle;
	encrypt_ptr_t encrypt_ptr;
	decrypt_ptr_t decrypt_ptr;
};
#endif CAESARCIPHER_H
