#include "Encrypter.h"
#include "string"

encrypter::encrypter(int m_seed)
{
	seed = m_seed;
}

encrypter::encrypter(){}

encrypter::~encrypter(){}

std::string encrypter::encrypt(std::string unEncrypted)
{
	std::string encrypted;
	for (int i = 0; i < unEncrypted.size(); i++) {
		encrypted.push_back(unEncrypted[i]);
	}
	return encrypted;
}

std::string encrypter::decrypt(std::string encrypted)
{	
	std::string decrypted;
	for (int i = 0; i < encrypted.size(); i++) {
		decrypted.push_back(encrypted[i]);
	}
	return decrypted;
}
