#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>

#ifdef CRYPTO_UNICODE
#define CHARSET_LENGTH 143859
#elifdef CRYPTO_ASCII
#define CHARSET_LENGTH 256
#else
#define CHARSET_LENGTH 128

#endif

// Error Codes

#define CRYPTO_UNKNOWN_CIPHER 0
#define CRYPTO_INVALID_KEY 1
#define CRYPTO_FORMAT_ERROR 2
#define CRYPTO_CHARSET_NOT_DEFINED 3
#define CRYPTO_DATA_NOT_ALLOWED 4
#define CRYPTO_INVALID 5
#define CRYPTO_UNKNOWN_ERROR 6
#define CRYPTO_STATE_NOT_SET 7
#define CRYPTO_OVERFLOW 8
#define CRYPTO_KEY_FORMAT_ERROR 9


// Types

#define CRYPTO_CAESER 0


struct crypto_keys {
	std::string private_key;
};

struct crypto_data {
	std::string message;
	unsigned int err_code;
	std::string err_msg;
	bool cleanup;
	bool salted;
	crypto_keys keys;
};

void crypto_enc_caeser(crypto_data &data);

void crypto_dec_caeser(crypto_data &data);

void crypto_add_salt(std::string &data);

void crypto_rem_salt(std::string &data);