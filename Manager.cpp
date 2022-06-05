#include "fstream"
#include "Encrypter.h"
#include "Manager.h"

	
manager::manager(encrypter _enc)
{
	enc = _enc;
}

manager::~manager(){}

//format: name, password, category, url, login
void manager::addPassword(std::string name, std::string password, std::string category)
{
	std::ofstream stream("UserData.txt", std::ofstream::app);
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category) << "$" << "$" << "\n";
	stream.close();
}

void manager::addPassword(std::string name, std::string password, std::string category, std::string url, std::string login)
{
	std::ofstream stream("UserData.txt", std::ofstream::app);
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category) << enc.encrypt(url) << enc.encrypt(login) << "\n";
}

void manager::addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category)
{
}

void manager::addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category, std::string url, std::string login)
{
}

