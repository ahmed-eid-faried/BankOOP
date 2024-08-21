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
	static void _ShowTransfer() {
		_DrawScreenHeader("Transfer");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\n\t\t\t\tPlease Enter Account Number to Transfer From:  ");;
		string AccountNumber2 = clsBankClient::ReadAccountNumberEixsted("\t\t\t\tPlease Enter Account Number to Transfer To:  ");;
		float TransferValue = clsUtil::ReadDoubleNumber("\t\t\t\tENTER Transfer Amount? ");
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		clsBankClient ClientTo = clsBankClient::Find(AccountNumber2);
		ClientFrom.PrintClientCard();
		ClientTo.PrintClientCard();
		bool state = clsUtil::ReadBool("\t\t\t\tAre you sure want to perform this operation?");
		if (state) {
			clsBankClient::Transfer(ClientFrom, ClientTo, TransferValue);
			clsBankClient::Find(AccountNumber).PrintClientCard();
			clsBankClient::Find(AccountNumber2).PrintClientCard();
		}
	}

public:
	static void Transfer() {
		_ShowTransfer();
	}
};