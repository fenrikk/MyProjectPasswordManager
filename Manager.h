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

	void getAllPasswords();

	void getPasswordByName(std::string _name);

	void editPasswordByName(std::string _name, std::string newPassword);

	void removePasswordByName(std::string _name);
};
#endif // !MANAGER_H