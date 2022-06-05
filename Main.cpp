#define _CRT_SECURE_NO_WARNINGS

#include "Encrypter.h"
#include "Manager.h"
#include "iostream"
#include "string"
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

const int ENCRYPTING_KEY = 40;

void clear() {
	cout << "\x1B[2J\x1B[H";
}

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);

	bool isLogged = false;

	cout << "Hello! I am password manager created by Nikita Stukalov, s24518, 99c" << endl;
	cout << "Write \"login\" to log in or \"create\" to create profile " << endl;
	string entered;
	cin >> entered;

	encrypter encrypterProfile(ENCRYPTING_KEY);

	if (entered == "login") {
		clear();
		string login, password;
		cout << "Login ";
		cin >> login;
		cout << "Password ";
		cin >> password;

		string encryptedLogin, encryptedPassword;
		time_t lastLogin;
		ifstream inputStream("Profile.txt");
		inputStream >> encryptedLogin >> encryptedPassword >> lastLogin;

		if (login == encrypterProfile.decrypt(encryptedLogin) && password == encrypterProfile.decrypt(encryptedPassword)) {
			clear();
			cout << "Welcome back " << login << endl;
			cout << "Last login: " << put_time(localtime(&lastLogin), "%c") << endl;
			inputStream.close();
			ofstream outStream("Profile.txt");
			time_t result = std::time(nullptr);
			outStream << encrypterProfile.encrypt(login) << " " << encrypterProfile.encrypt(password) << " " << result;
			outStream.close();
			isLogged = true;
		}
		else {
			clear();
			cout << "Invalide login or password" << endl;
			return -1;
		}
	}

	else if (entered == "create") {
		clear();
		string login, password;
		cout << "Login ";
		cin >> login;
		cout << "Password ";
		cin >> password;

		time_t result = std::time(nullptr);
		ofstream outStream("Profile.txt");
		outStream << encrypterProfile.encrypt(login) << " " << encrypterProfile.encrypt(password) << " " << result;
		outStream.close();
		clear();
		cout << login <<" profile created" << endl;
		isLogged = true;
	}
	else {
		cout << "Unnown command";
		return -1;
	}
	if (isLogged) {
		cout << "Choose you want" << endl;
		cout << "1: Find password by service name" << endl;
		cout << "2: Add password" << endl;
		cout << "3: Edit password" << endl;
		cout << "4: Remove password" << endl;
		encrypter encrypterData(ENCRYPTING_KEY);
		manager manager(encrypterData);
		int action;
		cin >> action;
		if (action == 1) {}
		else if(action == 2){
			clear();
			int actionOnSecond;
			cout << "Choose you want" << endl;
			cout << "1: Enter data with your password" << endl;
			cout << "2: Enter data with auto generated password" << endl;
			cin >> actionOnSecond;
			if(actionOnSecond == 1){
				clear();
				string name, password, category, url, login;
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter password: ";
				cin >> password;
				cout << "Enter category: ";
				cin >> category;
				cout << "(optionaly, enter \"no\" to set empty value)Enter url: ";
				cin >> url;
				cout << "(optionaly, enter \"no\" to set empty value)Enter login: ";
				cin >> login;
				if(url != "no" && login != "no"){
					manager.addPassword(name, password, category, url, login);
				}
				else{
					manager.addPassword(name, password, category);
				}
			}
			else if(actionOnSecond == 2){
				clear();
				string name, category, url, login;
				int length;
				bool useUpperCase, useSymbols;
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter password length: ";
				cin >> length;
				cout << "Use upper case(0|1): ";
				cin >> useUpperCase;
				cout << "Use symbols(0|1) : ";
				cin >> useSymbols;
				cout << "Enter category: ";
				cin >> category;
				cout << "(optionaly, enter \"no\" to set empty value)Enter url: ";
				cin >> url;
				cout << "(optionaly, enter \"no\" to set empty value)Enter login: ";
				cin >> login;
				if (url != "no" && login != "no") {
					manager.addPassword(length, useUpperCase, useSymbols, name, category, url, login);

				}
				else {
					manager.addPassword(length, useUpperCase, useSymbols, name, category);
				}

			}
			else {
				return -1;
			}
		}
		else if(action == 3){}
		else if(action == 4){}
		else {
			return -1;
		}
	}
}
