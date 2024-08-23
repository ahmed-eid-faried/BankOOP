#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>
#include "Global.h"
using namespace std;


class  clsCurrency {
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	bool _MarkedForDelete = false;


	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = Seperator)
	{
		vector <string> strCurrency = clsString::Split(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, strCurrency[0], strCurrency[1], strCurrency[2], stod(strCurrency[3]));
	}
	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = Seperator)
	{
		string Line = "";
		Line += Currency.Country + Seperator;
		Line += Currency.CurrencyCode + Seperator;
		Line += Currency.CurrencyName + Seperator;
		Line += to_string(Currency.Rate) + Seperator;
		return Line;
	}
	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		fstream MyFile;
		string Line;
		vector <clsCurrency> Currencies;
		MyFile.open(CurrencyPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line, Seperator);
				Currencies.push_back(Currency);
			}
			MyFile.close();
		}
		return Currencies;
	}
	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open(CurrencyPathFile, ios::out);//write mode
		if (MyFile.is_open()) {
			string DataLine;
			for (clsCurrency C : vCurrencies)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverCurrencyObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}
			MyFile.close();
		}
	}
	void _AddDataLineToFile(clsCurrency  Currency)
	{
		fstream MyFile;
		MyFile.open(CurrencyPathFile, ios::out | ios::app);//append mode or create mode
		if (MyFile.is_open()) {
			string   DataLine = _ConverCurrencyObjectToLine(Currency);
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////
	void _Update()
	{
		vector <clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& C : _vCurrencies)
		{
			if (C.Country == Country) {
				C = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(_vCurrencies);
	}
	void _AddNew()
	{
		_AddDataLineToFile(*this);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode, string  Country, string  CurrencyCode, string  CurrencyName, float  Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	////////////////////////////////////////////////////////////////////////////////////////

	//todo: setter and getter

	//setter and getter
	string GetCountry() { return _Country; }
	void SetCountry(string Country) { _Country = Country; }
	__declspec(property(get = GetCountry, put = SetCountry))string Country;

	//setter and getter
	string GetCurrencyCode() { return _CurrencyCode; }
	void SetCurrencyCode(string CurrencyCode) { _CurrencyCode = CurrencyCode; }
	__declspec(property(get = GetCurrencyCode, put = SetCurrencyCode))string CurrencyCode;

	//setter and getter
	string GetCurrencyName() { return _CurrencyName; }
	void SetCurrencyName(string CurrencyName) { _CurrencyName = CurrencyName; }
	__declspec(property(get = GetCurrencyName, put = SetCurrencyName))string CurrencyName;

	//setter and getter
	float GetRate() { return _Rate; }
	void SetRate(float Rate) { _Rate = Rate; }
	__declspec(property(get = GetRate, put = SetRate))float Rate;
	////////////////////////////////////////////////////////////////////////////////////////

	static string ReadCountryEixsted(string Message = "\t\t\t\tENTER YOUR Country: ") {
		string Country = "";
		bool state = false;
		do {
			Country = clsUtil::ReadString(Message);
			state = (Find(Country).IsEmpty()) || Country == "";
			if (state && Country != "") { cout << "\t\t\t\tThis Country is NOT existed." << endl; }
			if (Country == "") { cout << "\t\t\t\tThis Country is empty, please enter value." << endl; }
		} while (state);
		return Country;
	}
	static string ReadCountry(string Message = "\t\t\t\tENTER YOUR Country: ") {
		string Country = "";
		bool state = false;
		do {
			Country = clsUtil::ReadString(Message);
			state = (clsCurrency::IsCurrencyExist(Country)) || Country == "";
			if (state && Country != "") { cout << "\t\t\t\tThis Country is existed." << endl; }
			if (Country == "") { cout << "\t\t\t\tThis Country is empty, please enter value." << endl; }
		} while (state);
		return Country;
	}

	bool IsEmpty()
	{
		return enMode::EmptyMode == _Mode;
	}
	bool MarkedForDeleted() { return _MarkedForDelete; }

	////////////////////////////////////////////////////////////////////////////////////////
	void Print()
	{
		cout << "\n\t\t\t\tCurrency Card:";
		cout << "\n\t\t\t\t___________________";
		cout << "\n\t\t\t\tCountry     : " << Country;
		cout << "\n\t\t\t\tCurrencyCode: " << CurrencyCode;
		cout << "\n\t\t\t\tCurrencyName: " << CurrencyName;
		cout << "\n\t\t\t\tRate        : " << Rate;
		cout << "\n\t\t\t\t___________________\n";
	}

	static clsCurrency Find(string Country)
	{
		fstream MyFile;
		string Line;
		MyFile.open(CurrencyPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line, Seperator);
				string UpCountry = clsString::UpperAllString(Country);
				if (clsString::UpperAllString(Currency.Country) == UpCountry || clsString::UpperAllString(Currency.CurrencyCode) == UpCountry) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return  _GetEmptyCurrencyObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildCountryExists = 2 };
	static bool IsCurrencyExist(string Country)
	{
		return !(Find(Country).IsEmpty());
	}
	bool Delete()
	{
		vector <clsCurrency> _vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& C : _vCurrencies)
		{
			if (C.Country == _Country) {
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveCurrenciesDataToFile(_vCurrencies);
		*this = _GetEmptyCurrencyObject();
		return true;
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return  _LoadCurrenciesDataFromFile();
	}

	void Update() {
		_Mode = enMode::UpdateMode;
	}
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty()) {
				return enSaveResults::svFaildEmptyObject;
			}
		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (IsCurrencyExist(_Country))
			{
				return enSaveResults::svFaildCountryExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}
	}
	static clsCurrency GetAddNewCurrencyObject(string Country)
	{
		return clsCurrency(enMode::AddNewMode, Country, "", "", 0);
	}
	void ChangeRate(float Amount)
	{
		_Rate = Amount;
		Save();
	}
	static float CurrencyCalculator(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		return  Amount * (CurrencyTo.Rate / CurrencyFrom.Rate);
	}



};



