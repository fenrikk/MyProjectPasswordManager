#include "fstream"
#include "Encrypter.h"
#include "Manager.h"
#include <iostream>
#include <vector>

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

void manager::getAllPasswords()
{
	std::ifstream inputStream("UserData.txt");
	std::string line;
	while (inputStream.good()) {
		std::string name, password, category, url, login;
		inputStream >> name >> password >> category >> url >> login;
		std::cout << enc.decrypt(name) << " " << enc.decrypt(password) << " " << enc.decrypt(category) << " " << enc.decrypt(url) << " " << enc.decrypt(login) << std::endl;
	}
	inputStream.close();
}

void manager::getPasswordByName(std::string _name)
{
	std::ifstream inputStream("UserData.txt");
	std::string line;
	while (inputStream.good()) {
		std::string name, password, category, url, login;
		inputStream >> name >> password >> category >> url >> login;
		if (_name == enc.decrypt(name)) {
			std::cout << enc.decrypt(password) << std::endl;
		}
	}
	inputStream.close();
}

void manager::editPasswordByName(std::string _name, std::string newPassword)
{
	std::ifstream inputStream("UserData.txt");
	std::string line;
	std::vector<std::string> names;
	std::vector<std::string> passwords;
	std::vector<std::string> categorys;
	std::vector<std::string> urls;
	std::vector<std::string> logins;
	int lineNumber = -1;
	for (int i = 0; inputStream.good(); i++) {
		std::string name, password, category, url, login;
		inputStream >> name >> password >> category >> url >> login;
		name = enc.decrypt(name);
		password = enc.decrypt(password);
		category = enc.decrypt(category);
		url = enc.decrypt(url);
		login = enc.decrypt(login);
		names.push_back(name);
		passwords.push_back(password);
		categorys.push_back(category);
		urls.push_back(url);
		logins.push_back(login);
		if (_name == name) {
			lineNumber = i;
		}
	};
	inputStream.close();
	std::ofstream clearStream("UserData.txt", std::ios::trunc);
	clearStream.close();
	passwords.at(lineNumber) = newPassword;
	std::ofstream stream("UserData.txt", std::ofstream::app);
	for (int i = 0; i < names.size(); i++) {
		stream << enc.encrypt(names.at(i)) << " " << enc.encrypt(passwords.at(i)) << " " << enc.encrypt(categorys.at(i)) << " " << enc.encrypt(urls.at(i)) << " " << enc.encrypt(logins.at(i)) << "\n";
	}
	stream.close();
}

void manager::removePasswordByName(std::string _name)
{
	std::ifstream inputStream("UserData.txt");
	std::string line;
	std::vector<std::string> names;
	std::vector<std::string> passwords;
	std::vector<std::string> categorys;
	std::vector<std::string> urls;
	std::vector<std::string> logins;
	int lineNumber = -1;
	for (int i = 0; inputStream.good(); i++) {
		std::string name, password, category, url, login;
		inputStream >> name >> password >> category >> url >> login;
		name = enc.decrypt(name);
		password = enc.decrypt(password);
		category = enc.decrypt(category);
		url = enc.decrypt(url);
		login = enc.decrypt(login);
		names.push_back(name);
		passwords.push_back(password);
		categorys.push_back(category);
		urls.push_back(url);
		logins.push_back(login);
		if (_name == name) {
			lineNumber = i;
		}
	};
	inputStream.close();
	std::ofstream clearStream("UserData.txt", std::ios::trunc);
	clearStream.close();
	names.erase(names.begin() + lineNumber);
	passwords.erase(passwords.begin() + lineNumber);
	categorys.erase(categorys.begin() + lineNumber);
	urls.erase(urls.begin() + lineNumber);
	logins.erase(logins.begin() + lineNumber);
	std::ofstream stream("UserData.txt", std::ofstream::app);
	for (int i = 0; i < names.size(); i++) {
		stream << enc.encrypt(names.at(i)) << " " << enc.encrypt(passwords.at(i)) << " " << enc.encrypt(categorys.at(i)) << " " << enc.encrypt(urls.at(i)) << " " << enc.encrypt(logins.at(i)) << "\n";
	}
	stream.close();
}
