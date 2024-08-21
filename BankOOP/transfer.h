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
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\nPlease Enter Account Number to Transfer From:  ");;
		string AccountNumber2 = clsBankClient::ReadAccountNumberEixsted("\nPlease Enter Account Number to Transfer To:  ");;
		float TransferValue = clsUtil::ReadDoubleNumber("ENTER Transfer Amount? ");
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		clsBankClient ClientTo = clsBankClient::Find(AccountNumber);
		ClientFrom.PrintClientCard();
		ClientTo.PrintClientCard();
		bool state = clsUtil::ReadBool("Are you sure want to perform this operation?");
		if (state) {
			clsBankClient::Transfer(ClientFrom, ClientTo, TransferValue);
			ClientFrom.PrintClientCard();
			ClientTo.PrintClientCard();
		}
	}

public:
	static void Transfer() {
		_ShowTransfer();
	}
};