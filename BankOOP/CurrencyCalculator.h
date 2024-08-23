#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsCurrency.h" 
class clsCurrencyCalculatorScreen :protected clsScreen {
private:
	static void _ShowCurrencyCalculator() {
		_DrawScreenHeader("Currency Calculator");

		string CountryFrom = clsCurrency::ReadCountryEixsted("\n\t\t\t\tPlease enter Currency From? ");
		clsCurrency CurrencyFrom = clsCurrency::Find(CountryFrom);

		string CountryTo = clsCurrency::ReadCountryEixsted("\t\t\t\tPlease enter Currency To? ");
		clsCurrency CurrencyTo = clsCurrency::Find(CountryTo);

		float Amount = clsUtil::ReadDoubleNumber("\t\t\t\tENTER Amount To Exchange: ");
		float Result = clsCurrency::CurrencyCalculator(CurrencyFrom, CurrencyTo, Amount);
		cout << "\t\t\t\tConvert From: " << endl;
		CurrencyFrom.Print();
		cout << endl << endl << "\t\t\t\t" << Amount << " " << CurrencyFrom.CurrencyCode << " = " << Result << CurrencyTo.CurrencyCode << endl << endl;
		cout << "\t\t\t\tConvert To: " << endl;
		CurrencyTo.Print();
	}
public:
	static void CurrencyCalculator() {
		do
		{
			system("cls");
			_ShowCurrencyCalculator();
		} while (clsUtil::ReadBool("\t\t\t\tDo you want to perform another calculation?"));
	}
};