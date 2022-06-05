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
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category) << " " << "$" << " " << "$" << "\n";
	stream.close();
}

void manager::addPassword(std::string name, std::string password, std::string category, std::string url, std::string login)
{
	std::ofstream stream("UserData.txt", std::ofstream::app);
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category)<< " " << enc.encrypt(url)<< " " << enc.encrypt(login) << "\n";
	stream.close();
}

void manager::addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category)
{
	std::string password;
	srand(time(0));
	for (int i = 0; i < length; i++) {
		if(useUpperCase){
			if (useSympols) {
				int symbol = rand() % 38 + 58;
				password.push_back(symbol);
			}
			else {
				int symbol = rand() % 32 + 58;
				password.push_back(symbol);;
			}
		}
		else{
			if(useSympols){
				int symbol = rand() % 31 + 91;
				password.push_back(symbol);
			}
			else{
				int symbol = rand() % 25 + 97;
				password.push_back(symbol);
			}
		}
	}
	std::ofstream stream("UserData.txt", std::ofstream::app);
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category) << " " << "$" << " " << "$" << "\n";
	stream.close();
}

void manager::addPassword(int length, bool useUpperCase, bool useSympols, std::string name, std::string category, std::string url, std::string login)
{
	std::string password;
	srand(time(0));
	for (int i = 0; i < length; i++) {
		if (useUpperCase) {
			if (useSympols) {
				int symbol = rand() % 38 + 58;
				password.push_back(symbol);
			}
			else {
				int symbol = rand() % 32 + 58;
				password.push_back(symbol);
			}
		}
		else {
			if (useSympols) {
				int symbol = rand() % 31 + 91;
				password.push_back(symbol);
			}
			else {
				int symbol = rand() % 25 + 97;
				password.push_back(symbol);
			}
		}
	}
	std::ofstream stream("UserData.txt", std::ofstream::app);
	stream << enc.encrypt(name) << " " << enc.encrypt(password) << " " << enc.encrypt(category) << " " << enc.encrypt(url) << " " << enc.encrypt(login) << "\n";
	stream.close();
}

