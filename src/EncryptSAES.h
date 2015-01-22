#ifndef _ENCRYPT_SAES_H_
#define _ENCRYPT_SAES_H_
#include "SAES.h"

/**
 * Зашифрование SAES.
 */

class EncryptSAES : public SAES {
protected:
	void subNibbles();
	void mixColumns();
	void encryptSAES();
public:
	std::string encrypt(const std::vector<uint8_t> &key);
	void encrypt(std::string & resultEncrypt,const std::vector<uint8_t> &key);
	EncryptSAES();
	explicit EncryptSAES(const std::string &txt);
	~EncryptSAES() { };
};

#endif
