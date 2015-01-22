/*
 * DecryptSAES.h
 *
 *      Author: eugene
 */

#ifndef DECRYPTSAES_H_
#define DECRYPTSAES_H_

#include "SAES.h"

class DecryptSAES: public SAES {
protected:
	static const uint8_t s_box_i[16];
	void invSubNibbles();
	void invMixColumns();
	void decryptSAES();
public:
	std::string decrypt(const std::vector<uint8_t> &key);
	void decrypt(std::string & resultDecrypt,const std::vector<uint8_t> &key);

	DecryptSAES();
	explicit DecryptSAES(const std::string &txt);
	~DecryptSAES();
};

#endif
