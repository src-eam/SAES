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
	std::string encrypt(const int &key);
	void encrypt(std::string & resultEncrypt,const int &k);
	EncryptSAES();
	explicit EncryptSAES(const std::string &txt);
	~EncryptSAES() { };
};

#endif
