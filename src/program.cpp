// usage: ./s_aes <mode> <key_file> <input_file> <outpu_file>

#include <iostream>
#include <fstream>
#include <iterator>
#include "EncryptSAES.h"
#include "DecryptSAES.h"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 5) {
		cerr
				<< "Error. Usage: ./s_aes <mode> <key_file> <input_file> <outpu_file>.\n";
		exit(EXIT_FAILURE);
	}
	bool flagMode;
	string mode = string(argv[1]);
	if (mode == "-encrypt")
		flagMode = true;
	else if (mode == "-decrypt")
		flagMode = false;
	else {
		cerr << "Error with arguments. Mode not correct.\n";
		exit(EXIT_FAILURE);
	}

	string keyFile = string(argv[2]);
	ifstream kf(keyFile);
	if (!kf.is_open()) {
		cerr << "Error opening the key file: " << keyFile << endl;
		exit(EXIT_FAILURE);
	}
	vector<uint8_t> key(2);
	unsigned int tmp;
	kf >> hex >> tmp;
	key[0] = (tmp & 0xff);
	kf >> hex >> tmp;
	key[1] = (tmp & 0xff);
	kf.close();

	string inFile = string(argv[3]);
	ifstream input(inFile);
	if (!input.is_open()) {
		cerr << "Error opening the input file: " << inFile << endl;
		exit(EXIT_FAILURE);
	}
	input.unsetf(ios::skipws);
	std::istream_iterator<char> eos;
	string data(istream_iterator<char>(input), eos);
	input.close();

	string outFile = string(argv[4]);
	ofstream output(outFile);
	if (!output.is_open()) {
		cerr << "Error opening the output file: " << outFile << endl;
		exit(EXIT_FAILURE);
	}

	if (flagMode) {
		EncryptSAES encrypt(data);
		output << encrypt.encrypt(key);
	}
	else {
		DecryptSAES decrypt(data);
		output << decrypt.decrypt(key);
	}
	cout << "Data length: " << data.length() << endl;
	output.close();

	return 0;
}
