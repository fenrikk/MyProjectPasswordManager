#ifndef MANAGER_H
#define MANAGER_H

#include "Encrypter.h"

class manager {
private:
	encrypter enc;
public:
	manager(encrypter _enc);
	~manager();

	void addPassword(std::string name, std::string password, std::string category);
	void addPassword(std::string name, std::string password, std::string category, std::string url, std::string login);
	void addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category);
	void addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category, std::string url, std::string login);
};
#endif // !MANAGER_H