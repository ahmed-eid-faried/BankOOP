#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
using namespace std;


class clsBankClient :public clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;


	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

public:
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