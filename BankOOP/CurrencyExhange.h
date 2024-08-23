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
#include "transfer.h"
#include "TransferLogsScreen.h"
#include "ListCurrencies.h"
#include "FindCurrency.h"
#include "UpdateRate.h"
#include "CurrencyCalculator.h"
using namespace std;

class clsCurrencyScreen : protected clsScreen {
private:
	enum enCurrencyMenueOptions {
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalculator = 4,
		eMainMenue = 5,
	};

	static void _BackToCurrencyMenue() {
		cout << "\t\t\t\tPress any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls");     // Clear the screen
		_ShowCurrencyMenue();
	}

	static void _RoutingCurrency(enCurrencyMenueOptions Option) {
		switch (Option) {
		case enCurrencyMenueOptions::eListCurrencies:
			system("cls");
			clsListCurrenciesScreen::ListCurrencies();
			_BackToCurrencyMenue();
			break;
		case enCurrencyMenueOptions::eFindCurrency:
			system("cls");
			clsFindCurrencyScreen::FindCurrency();
			_BackToCurrencyMenue();
			break;
		case enCurrencyMenueOptions::eUpdateRate:
			system("cls");
			clsUpdateRateScreen::UpdateRate();
			_BackToCurrencyMenue();
			break;
		case enCurrencyMenueOptions::eCurrencyCalculator:
			system("cls");
			clsCurrencyCalculatorScreen::CurrencyCalculator();
			_BackToCurrencyMenue();
			break;
		case enCurrencyMenueOptions::eMainMenue:
			system("cls");
			break;
		default:
			break;
		}
	}
	
	static void _ShowCurrencyMenue() {
		_DrawScreenHeader("Currency Exhange Menue");
		cout << "\t\t\t\t\t   [1] List Currencies." << endl;
		cout << "\t\t\t\t\t   [2] Find Currency." << endl;
		cout << "\t\t\t\t\t   [3] Update Rate." << endl;
		cout << "\t\t\t\t\t   [4] Currency Calculator." << endl;
		cout << "\t\t\t\t\t   [5] Main Menue." << endl;
		cout << "\t\t\t\t====================================================" << endl;
		enCurrencyMenueOptions Option = (enCurrencyMenueOptions)clsUtil::ReadNumberInRange(1, 5, "\t\t\t\tChoose what do you want to do? ");
		_RoutingCurrency(Option);
	}

public:
	static void Currency() {
		_ShowCurrencyMenue();
	}
};
