#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen {

private:
	static void _ShowResultDelete(string AccountNumber, bool state) {
		if (state) {
			cout << AccountNumber << " is deleted." << endl;
		}
		else {
			cout << "it failed to delete " << AccountNumber << endl;
		}
	}

public:
	static void DeleteClient() {
		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber = clsBankClient::ReadAccountNumber("\nPlease enter AccountNumber? ");
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ShowResultDelete(AccountNumber, Client.Delete());

	}
};