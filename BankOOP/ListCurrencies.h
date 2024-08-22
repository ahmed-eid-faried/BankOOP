#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
 
class clsListCurrenciesScreen :protected clsScreen {
private:
	static void _PrintCurrencyHeaderListCurrencies(vector<clsCurrency> Currencies) {
		cout << "\n\t\tCurrency List (" << Currencies.size() << ") Currency(s).";
		cout << "\n\t______________________________________________________________________________________________________\n" << endl;
		cout << "\t";
		cout << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(12) << "CurrencyCode";
		cout << "| " << left << setw(40) << "CurrencyName";
		cout << "| " << left << setw(16) << "Rate";
		cout << "\n\t______________________________________________________________________________________________________\n" << endl;

	};
	static void _PrintCurrencyListCurrencies(clsCurrency Currency) {
		cout << "\t";
		cout << "| " << setw(30) << left << Currency.Country;
		cout << "| " << setw(12) << left << Currency.CurrencyCode;
		cout << "| " << setw(40) << left << Currency.CurrencyName;
		cout << "| " << setw(16) << left << Currency.Rate;
	};
	static void _ReadFileByVectorListCurrencies(vector<clsCurrency>& Currencies) {
		for (clsCurrency& Currency : Currencies) {
			if (!Currency.IsEmpty())
			{
				_PrintCurrencyListCurrencies(Currency);
				cout << endl;
			}
		}
		cout << "\n\t______________________________________________________________________________________________________\n" << endl;

	}

	static	void _ListCurrencies() {
		vector<clsCurrency> Currencies = clsCurrency::GetCurrenciesList();
		_DrawScreenHeader("List Currencies Screen");
		_PrintCurrencyHeaderListCurrencies(Currencies);
		_ReadFileByVectorListCurrencies(Currencies);
 		cout << endl;
	}
public:
	static void ListCurrencies() {
		_ListCurrencies();
	}
};


