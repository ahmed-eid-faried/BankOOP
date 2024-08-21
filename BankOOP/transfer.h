#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransferScreen :protected clsScreen {
private:
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t___________________";
		cout << "\n\t\t\t\tFull Name   : " << Client.FullName;
		cout << "\n\t\t\t\tPassword    : " << Client.PinCode;
		cout << "\n\t\t\t\tBalance     : " << Client.AccountBalance;
		cout << "\n\t\t\t\t___________________\n";
	}
	static void _ShowTransfer() {
		_DrawScreenHeader("Transfer");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\n\t\t\t\tPlease Enter Account Number to Transfer From:  ");;
		string AccountNumber2 = clsBankClient::ReadAccountNumberEixsted("\t\t\t\tPlease Enter Account Number to Transfer To:  ");;
		float TransferValue = clsUtil::ReadDoubleNumber("\t\t\t\tENTER Transfer Amount? ");
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		clsBankClient ClientTo = clsBankClient::Find(AccountNumber2);
		_PrintClientCard(ClientFrom);
		_PrintClientCard(ClientTo);
		bool state = clsUtil::ReadBool("\t\t\t\tAre you sure want to perform this operation?");
		if (state) {
			clsBankClient::Transfer(ClientFrom, ClientTo, TransferValue);
			_PrintClientCard(clsBankClient::Find(AccountNumber));
			_PrintClientCard(clsBankClient::Find(AccountNumber2));
		}
	}

public:
	static void Transfer() {
		_ShowTransfer();
	}
};