#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsFindClientScreen :protected clsScreen {
private:

	static void _ShowResult(string AccountNumber, clsBankClient Client) {
		if (Client.IsEmpty()) {
			cout << "\n\t\t\t\tClient with Account Number (" << AccountNumber << ") is Not Found!" << endl;
		}
		else {
			Client.Print();
		}
	}
public:
	static void FindClient() {
		_DrawScreenHeader("Find Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\n\t\t\t\tPlease enter AccountNumber? ");;
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ShowResult(AccountNumber, Client);
	}
};