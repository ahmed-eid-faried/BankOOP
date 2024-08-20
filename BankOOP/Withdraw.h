#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsWithdrawScreen :protected clsScreen {
private:
	static void _ShowWithdraw() {
		_DrawScreenHeader("Deposit Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\nPlease enter AccountNumber? ");;
		double WithdrawValue = clsUtil::ReadDoubleNumber("ENTER YOUR Withdraw Value: ");
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Withdraw(WithdrawValue);
		Client.Print();
	}

public:
	static void Withdraw() {
		_ShowWithdraw();
	}
};