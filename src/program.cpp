#include <iostream>
#include <assert.h>
#include "EncryptSAES.h"
#include "DecryptSAES.h"
using namespace std;

int main() {
	string testStr = "ababq";
	int key = 100;
	EncryptSAES enS(testStr);
	DecryptSAES deS(enS.encrypt(key));
	assert(deS.decrypt(key) == testStr + " ");

	string res = "";
	string encr = enS.encrypt(key + 5);
	DecryptSAES des_2(encr);
	des_2.decrypt(res, key + 5);
	assert(res == testStr + " ");

	cout << "OK!" << endl;
	return 0;
}
