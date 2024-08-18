#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
using namespace std;
const string  ClientsFileName = "clients.txt";
const string  UsersFileName = "users.txt";
const string  Seperator = "#%&#";

class clsBankClient :public clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;


	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;


	clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = Seperator) {
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	//setter and getter
	string GetAccountNumber() { return _AccountNumber; }
	void SetAccountNumber(string AccountNumber) { _AccountNumber = AccountNumber; }
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber;
	//setter and getter
	string GetPinCode() { return _PinCode; }
	void SetPinCode(string PinCode) { _PinCode = PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	//setter and getter
	float GetAccountBalance() { return _AccountBalance; }
	void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;





};