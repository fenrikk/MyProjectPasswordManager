#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include "string"

class encrypter {
private: 
	int seed;
public:
	encrypter(int m_seed);
	encrypter();
	~encrypter();

	std::string encrypt(std::string unEncrypted);
	std::string decrypt(std::string encrypted);
};
#endif // !ENCRYPTER_H