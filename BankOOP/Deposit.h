#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsDepositScreen :protected clsScreen {
private:
	static void _ShowDeposit() {
		_DrawScreenHeader("Deposit Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\nPlease enter AccountNumber? ");;
		double DepositValue = clsUtil::ReadDoubleNumber("ENTER YOUR Deposit Value: ");
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Deposit(DepositValue);
		Client.Print();
	}

public:
	static void Deposit() {
		_ShowDeposit();
	}
};