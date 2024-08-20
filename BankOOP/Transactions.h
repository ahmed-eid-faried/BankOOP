#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "TotalBalances.h"
class clsTransactionsScreen :protected clsScreen {
private:
 	enum enTransactionsMenueOptions {
		eDeposit = 1,
		eWithdraw = 2,
		eTotalBalances = 3,
		eMainMenue = 4,
	};
	static	void _BackToTransactionsMenue() {
		cout << "Press any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
		//system("pause>0");
		_ShowTransactionsMenue();
	}
	static	void _RoutingTransactions(enTransactionsMenueOptions Option) {
		switch (Option)
		{
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			clsDepositScreen::Deposit();
			_BackToTransactionsMenue();
		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			clsWithdrawScreen::Withdraw();
			_BackToTransactionsMenue();
		case enTransactionsMenueOptions::eTotalBalances:
			system("cls");
			clsTotalBalancesScreen::TotalBalances();
			_BackToTransactionsMenue();
		case enTransactionsMenueOptions::eMainMenue:
			system("cls");
			clsMainMenueScreen::ShowMainMenue();
		default:
			break;
		}
	}
	static void _ShowTransactionsMenue() {
		cout << "\t\t\t\t\t   [1] Deposit." << endl;
		cout << "\t\t\t\t\t   [2] Withdraw." << endl;
		cout << "\t\t\t\t\t   [3] Total Balances." << endl;
		cout << "\t\t\t\t\t   [4] Main Menue." << endl;
		cout << "====================================================" << endl;
		enTransactionsMenueOptions Option = (enTransactionsMenueOptions)clsUtil::ReadNumberInRange(1, 4, "Choose what do you want to do? ");
		_RoutingTransactions(Option);
	}
	void Transactions() {
	}
public:
	static void Transactions() {
		_DrawScreenHeader("Transactions Menue Screen");
		_ShowTransactionsMenue();
	}
};