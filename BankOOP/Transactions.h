#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Deposit.h"
#include "Withdraw.h"
#include "TotalBalances.h"
#include "clsMainMenue.h"
 using namespace std;

class clsTransactionsScreen : protected clsScreen {
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1,
		eWithdraw = 2,
		eTotalBalances = 3,
		eMainMenue = 4,
	};

	static void _BackToTransactionsMenue() {
		cout << "Press any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls");     // Clear the screen
		_ShowTransactionsMenue();
	}

	static void _RoutingTransactions(enTransactionsMenueOptions Option) {
		switch (Option) {
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			clsDepositScreen::Deposit();
			_BackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			clsWithdrawScreen::Withdraw();
			_BackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eTotalBalances:
			system("cls");
			clsTotalBalancesScreen::TotalBalances();
			_BackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eMainMenue:
			system("cls");
			//clsMainMenueScreen::ShowMainMenue();  
			break;
		default:
			break;
		}
	}

	static void _ShowTransactionsMenue() {
		_DrawScreenHeader("Transactions Menue Screen");
		cout << "\t\t\t\t\t   [1] Deposit." << endl;
		cout << "\t\t\t\t\t   [2] Withdraw." << endl;
		cout << "\t\t\t\t\t   [3] Total Balances." << endl;
		cout << "\t\t\t\t\t   [4] Main Menue." << endl;
		cout << "\t\t\t\t====================================================" << endl;
		enTransactionsMenueOptions Option = (enTransactionsMenueOptions)clsUtil::ReadNumberInRange(1, 4, "\t\t\t\tChoose what do you want to do? ");
		_RoutingTransactions(Option);
	}

public:
	static void Transactions() {
		_ShowTransactionsMenue();
	}
};
