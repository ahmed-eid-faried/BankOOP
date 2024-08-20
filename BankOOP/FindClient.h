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
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		}
		else {
			Client.Print();
		}
	}
public:
	static void FindClient() {
		_DrawScreenHeader("Find Client");
		string AccountNumber = clsBankClient::ReadAccountNumber("\nPlease enter AccountNumber? ", false);
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_ShowResult(AccountNumber, Client);
	}
};