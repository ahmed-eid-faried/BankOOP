#pragma once
#include<iostream>
 #include<string>
#include<vector>
 #include "clsScreen.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen :protected clsScreen {
private:

	static void _ShowResult(string AccountNumber, clsCurrency Currency) {
		if (Currency.IsEmpty()) {
			cout << "\n\t\t\t\tCurrency with Country (" << AccountNumber << ") is Not Found!" << endl;
		}
		else {
			Currency.Print();
		}
	}
public:
	static void FindCurrency() {
		_DrawScreenHeader("Find Currency");
		string AccountNumber = clsCurrency::ReadCountryEixsted("\n\t\t\t\tPlease enter Country? ");;
		clsCurrency Currency = clsCurrency::Find(AccountNumber);
		_ShowResult(AccountNumber, Currency);
	}
};