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
	static void _ShowResultDelete(string AccountNumber) {
		if (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\t\t\t\tYou have successfully deleted the user." << endl;
			cout << "\t\t\t\t"<<AccountNumber << " is deleted." << endl;
		}
		else {
			cout << "\t\t\t\tit failed to delete " << AccountNumber << endl;
		}
	}

public:
	static void DeleteClient() {
		_DrawScreenHeader("Delete Client Screen");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\n\t\t\t\tPlease enter AccountNumber? ");;
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Delete();
		_ShowResultDelete(AccountNumber);
		Client.Save();
	}
};