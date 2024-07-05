#include <Windows.h>
#ifndef CAESARCIPHER_H
#define CAEASARCIPHER_H
class CaesarCipher
{
public:
	CaesarCipher();
	~CaesarCipher();
	char* encrypt(char* rawText, int key);
	char* decrypt(char* encryptedText, int key);
private:
	typedef char* (*encrypt_ptr_t)(char*, int);
	typedef char* (*decrypt_ptr_t)(char*, int);
	HINSTANCE handle;
	encrypt_ptr_t encrypt_ptr;
	decrypt_ptr_t decrypt_ptr;
};
#endif CAESARCIPHER_H
