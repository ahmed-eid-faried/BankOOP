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
		Client.PinCode = clsUtil::ReadString("\t\t\t\tENTER YOUR PinCode: ");
		Client.FirstName = clsUtil::ReadString("\t\t\t\tENTER YOUR FirstName: ");
		Client.LastName = clsUtil::ReadString("\t\t\t\tENTER YOUR LastName: ");
		Client.Phone = clsUtil::ReadString("\t\t\t\tENTER YOUR Phone: ");
		Client.AccountBalance = clsUtil::ReadDoubleNumber("\t\t\t\tENTER YOUR AccountBalance: ");
		Client.Update();
		return Client;
	};

public:
	static void UpdateClient() {
		_DrawScreenHeader("Update Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\n\t\t\t\tPlease enter AccountNumber? ");;
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client = _ReadUpdateClient(Client);
		Client.Save();
		Client.Print();

	}
};