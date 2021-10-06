#include "crypto.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	crypto_data data;
	std::cout << "Enter a Message : ";
	getline(std::cin, data.message);
	crypto_keys keys;
	std::cout << "\n\nEnter Key : ";
	getline(std::cin, keys.private_key);
	data.keys = keys;
	crypto_enc_caeser(data);
	std::cout << "Encrypted data : \n";
	std::cout << data.message;
	crypto_dec_caeser(data);
	std::cout << "\n\nDecrypted data : \n";
	std::cout << data.message;
	return 0;
}