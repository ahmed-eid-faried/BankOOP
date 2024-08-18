#include <iostream>

int main()
{
	std::cout << "Hello World!\n";
}

#pragma once
#include <string>
using namespace std;
const string  ClientsFileName = "clients.txt";
const string  UsersFileName = "users.txt";
const string  Seperator = "#%&#";

struct sClient {
	string  AccountNumber;
	string  PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};

struct sUser {
	string  Name;
	string  Password;
	int Permissions;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};
