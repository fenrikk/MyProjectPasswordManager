#define _CRT_SECURE_NO_WARNINGS

#include "Encrypter.h"
#include "Manager.h"
#include "iostream"
#include "string"
#include <fstream>
#include <iomanip>

using namespace std;

const int ENCRYPTING_KEY = 40;

int main() {
	bool isLogged = false;

	cout << "Hello! I am password manager created by Nikita Stukalov, s24518, 99c" << endl;
	cout << "Write \"login\" to log in or \"create\" to create profile " << endl;
	string entered;
	cin >> entered;

	encrypter encrypterProfile(ENCRYPTING_KEY);

	if (entered == "login") {
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
			cout << "\x1B[2J\x1B[H";
			cout << "Welcome back " << login << endl;
			cout << "Last login: " << put_time(localtime(&lastLogin), "%c");
			inputStream.close();
			ofstream outStream("Profile.txt");
			time_t result = std::time(nullptr);
			outStream << encrypterProfile.encrypt(login) << " " << encrypterProfile.encrypt(password) << " " << result;
			outStream.close();
			isLogged = true;
		}
		else {
			cout << "Invalide login or password" << endl;
			return -1;
		}
	}

	else if (entered == "create") {
		string login, password;
		cout << "Login ";
		cin >> login;
		cout << "Password ";
		cin >> password;

		time_t result = std::time(nullptr);
		ofstream outStream("Profile.txt");
		outStream << encrypterProfile.encrypt(login) << " " << encrypterProfile.encrypt(password) << " " << result;
		outStream.close();
		cout << "\x1B[2J\x1B[H";
		cout << login <<" profile created" << endl;
		isLogged = true;
	}
	else {
		cout << "Unnown command";
		return -1;
	}
	if (isLogged) {
		cout << "Choose a you want" << endl;
		cout << "1: Find password by service name" << endl;
		cout << "2: Add password" << endl;
		cout << "3: Edit password" << endl;
		cout << "4: Remove password" << endl;
		encrypter encrypterData(ENCRYPTING_KEY);
		manager manager(encrypterData);
		int action;
		cin >> action;
		string name, password, category;
		switch (action) {
		case(1):
			break;
		case(2):
			cout << "Enter name : " << endl;
			cin >> name;
			cout << "Enter password: " << endl;
			cin >> password;
			cout << "Enter category: " << endl;
			cin >> category;
			manager.addPassword(name, password, category);
			break;
		case(3):
			break;
		case(4):
			break;
		default:
			break;
		}
	}
}