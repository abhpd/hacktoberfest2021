#include "crypto.h"

static int rotateCharacterForowardBy(int character, int rotations) {
	if (character + rotations > CHARSET_LENGTH) {
		character = character - CHARSET_LENGTH + rotations;
	}
	else {
		character = character + rotations;
	}
	return character;
}

static int rotateCharacterBackwardBy(int character, int rotations) {
	if (character - rotations < 0) {
		character = character + CHARSET_LENGTH - rotations;
	}
	else {
		character = character - rotations;
	}
	return character;
}

static int getRandomCharacter() {
	return (32 + rand() % 60);
}

static void swapCipherSetBlock(char* cipherset, int begin, int end) {
	char swapTemp;
	while (end > begin)
	{
		swapTemp = cipherset[begin];
		cipherset[begin] = cipherset[end];
		cipherset[end] = swapTemp;
		begin++;
		end--;
	}
}

static int findIndex(char* list, int length, char value) {
	for (int i = 0; i < length; i++) {
		if (list[i] == value)
			return i;
	}
	return -1;
}

void crypto_enc_caeser(crypto_data &data) {
	// Validation
	if (data.keys.private_key.length() == 0) {
		data.err_code = CRYPTO_KEY_FORMAT_ERROR;
		data.err_msg = "Private key not provided!";
	}
	// Algorithm
	std::string msg = data.message;
	if (data.salted) {
		crypto_add_salt(msg);
	}
	const std::string key = data.keys.private_key;
	for (int charIndex = 0, keyIndex = 0; charIndex < msg.length(); charIndex++, keyIndex++) {
		if (keyIndex == key.length())
			keyIndex = 0;
		int shift = int(key[keyIndex]);
		msg[charIndex] = (unsigned char)(rotateCharacterForowardBy(msg[charIndex], shift));		
	}
	data.message = msg;
}

void crypto_dec_caeser(crypto_data &data) {
	// Validation
	if (data.keys.private_key.length() == 0) {
		data.err_code = CRYPTO_KEY_FORMAT_ERROR;
		data.err_msg = "Private key not provided!";
	}
	// Algorithm
	std::string msg = data.message;
	const std::string key = data.keys.private_key;
	for (int charIndex = 0, keyIndex = 0; charIndex < msg.length(); charIndex++, keyIndex++) {
		if (keyIndex == key.length())
			keyIndex = 0;
		int shift = int(key[keyIndex]);
		msg[charIndex] = (unsigned char)(rotateCharacterBackwardBy(msg[charIndex], shift));
	}
	if (data.salted) {
		crypto_rem_salt(msg);
	}
	data.message = msg;
}


void crypto_add_salt(std::string &msg) {
	std::string msg_final = "";
	for (int charIndex = 0; charIndex < msg.length(); charIndex++) {
		msg_final += (unsigned char)(msg[charIndex]);
		msg_final += (unsigned char)(getRandomCharacter());
	}
	msg = msg_final;
}

void crypto_rem_salt(std::string& msg) {
	std::string msg_final = "";
	for (int charIndex = 0; charIndex < msg.length(); charIndex+=2) {
		msg_final += (unsigned char)(msg[charIndex]);
	}
	msg = msg_final;
}