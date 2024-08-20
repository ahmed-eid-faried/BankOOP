#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h" 
class clsUpdateClientScreen :protected clsScreen {
private:

	static	clsBankClient _ReadUpdateClient(clsBankClient Client) {
		Client.PinCode = clsUtil::ReadString("ENTER YOUR PinCode: ");
		Client.FirstName = clsUtil::ReadString("ENTER YOUR FirstName: ");
		Client.LastName = clsUtil::ReadString("ENTER YOUR LastName: ");
		Client.Phone = clsUtil::ReadString("ENTER YOUR Phone: ");
		Client.AccountBalance = clsUtil::ReadDoubleNumber("ENTER YOUR AccountBalance: ");
		Client.Update();
		return Client;
	};

public:
	static void UpdateClient() {
		_DrawScreenHeader("Update Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\nPlease enter AccountNumber? ");;
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client = _ReadUpdateClient(Client);
		Client.Save();
		Client.Print();

	}
};