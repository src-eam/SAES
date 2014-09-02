#include "EncryptSAES.h"

void EncryptSAES::subNibbles() {
	for (uint8_t ind = 0; ind < Nk; ind++) {
		state[ind] = subNib(state[ind])
				| (subNib((state[ind] & 0b11110000) >> 4) << 4);
	}
}

void EncryptSAES::mixColumns() {
	uint8_t a, b, e, d;
	a = (state[0] & 0xf) ^ g_mul(4, ((state[0] & 0b11110000) >> 4));
	b = g_mul(4, state[0] & 0xf) ^ ((state[0] & 0b11110000) >> 4);
	e = (state[1] & 0xf) ^ g_mul(4, ((state[1] & 0b11110000) >> 4));
	d = g_mul(4, state[1] & 0xf) ^ ((state[1] & 0b11110000) >> 4);
	state[0] = (a | (b << 4));
	state[1] = (e | (d << 4));
}

void EncryptSAES::encryptSAES() {
	addRoundKey(0);
	subNibbles();
	shiftRows();
	mixColumns();
	addRoundKey(1);
	subNibbles();
	shiftRows();
	addRoundKey(2);
}

EncryptSAES::EncryptSAES() {
	this->text = "";
}

EncryptSAES::EncryptSAES(const std::string &txt) {
	this->text = txt;
	if (this->text.size() & 1)
		text += " ";
}

std::string EncryptSAES::encrypt(const int &k) {
	std::string result = "";
	encrypt(result,k);
	return result;
}

void EncryptSAES::encrypt(std::string &resultEncrypt, const int &key) {
	if (this->text == "")
		resultEncrypt = "";
	else {
		keyExpand(key);
		if(resultEncrypt.capacity() < text.size() )
			resultEncrypt.reserve(this->text.size());
		for (auto iter = this->text.begin(); iter != this->text.end(); iter +=
				2) {
			state[0] = (*iter);
			state[1] = (*(iter + 1));
			encryptSAES();
			resultEncrypt += std::string(state, state + Nk);
		}
	}
}
