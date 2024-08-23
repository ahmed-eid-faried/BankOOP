#pragma once
#include<iostream>
 #include<string>
#include<vector>
 #include "clsScreen.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen :protected clsScreen {
private:

	static void _ShowResult(string Country, clsCurrency Currency) {
		if (Currency.IsEmpty()) {
			cout << "\n\t\t\t\tCurrency with Country (" << Country << ") is Not Found!" << endl;
		}
		else {
			Currency.Print();
		}
	}
public:
	static void FindCurrency() {
		_DrawScreenHeader("Find Currency");
		string Country = clsCurrency::ReadCountryEixsted("\n\t\t\t\tPlease enter Country? ");;
		clsCurrency Currency = clsCurrency::Find(Country);
		_ShowResult(Country, Currency);
	}
};