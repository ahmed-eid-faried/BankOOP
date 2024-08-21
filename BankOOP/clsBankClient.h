#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>
using namespace std;


 
class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;


	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;



	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = Seperator)
	{
		vector <string> strClient = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, strClient[0], strClient[1], strClient[2], strClient[3], strClient[4],
			strClient[5], stod(strClient[6]));
	}
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = Seperator)
	{
		string Line = "";
		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance) + Seperator;
		return Line;
	}
	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		string Line;
		vector <clsBankClient> Clients;
		MyFile.open(ClientPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line, Seperator);
				Clients.push_back(Client);
			}
			MyFile.close();
		}
		return Clients;
	}
	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open(ClientPathFile, ios::out);//write mode
		if (MyFile.is_open()) {
			string DataLine;
			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _AddDataLineToFile(clsBankClient  Client)
	{
		fstream MyFile;
		MyFile.open(ClientPathFile, ios::out | ios::app);//append mode or create mode
		if (MyFile.is_open()) {
			string   DataLine = _ConverClientObjectToLine(Client);
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber == AccountNumber) {
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	}
	void _AddNew()
	{
		_AddDataLineToFile(*this);
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	static string ReadAccountNumberEixsted(string Message = "ENTER YOUR AccountNumber: ") {
		string AccountNumber = "";
		bool state = false;
		do {
			AccountNumber = clsUtil::ReadString(Message);
			state = (Find(AccountNumber).IsEmpty()) || AccountNumber == "";
			if (state && AccountNumber != "") { cout << "This AccountNumber is existed." << endl; }
			if (AccountNumber == "") { cout << "This AccountNumber is empty, please enter value." << endl; }
		} while (state);
		return AccountNumber;
	}
	static string ReadAccountNumber(string Message = "ENTER YOUR AccountNumber: ") {
		string AccountNumber = "";
		bool state = false;
		do {
			AccountNumber = clsUtil::ReadString(Message);
			state = (clsBankClient::IsClientExist(AccountNumber)) || AccountNumber == "";
			if (state && AccountNumber != "") { cout << "This AccountNumber is existed." << endl; }
			if (AccountNumber == "") { cout << "This AccountNumber is empty, please enter value." << endl; }
		} while (state);
		return AccountNumber;
	}

	clsBankClient(string Message) : clsPerson("", "", "", "") {
		*this = GetAddNewClientObject(ReadAccountNumber(Message));
	}

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return enMode::EmptyMode == _Mode;
	}

	bool MarkedForDeleted() { return _MarkedForDelete; }


	//todo: setter and getter

	//setter and getter
	string GetAccountNumber() { return _AccountNumber; }
	//void SetAccountNumber(string AccountNumber) { _AccountNumber = AccountNumber; }
	__declspec(property(get = GetAccountNumber))string AccountNumber;

	//setter and getter
	string GetPinCode() { return _PinCode; }
	void SetPinCode(string PinCode) { _PinCode = PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	//setter and getter
	float GetAccountBalance() { return _AccountBalance; }
	void SetAccountBalance(float AccountBalance) { _AccountBalance = AccountBalance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;



	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName;
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}

	static clsBankClient Find(string AccountNumber)
	{
		//vector <clsBankClient> _vClients;
		//_vClients = _LoadClientsDataFromFile();
		//for (clsBankClient C : _vClients)
		//{
		//	if (C.AccountNumber == AccountNumber) {
		//		return C;
		//		}
		//}
		//return  _GetEmptyClientObject();
		/////////////////////////////////
		fstream MyFile;
		string Line;
		MyFile.open(ClientPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line, Seperator);
				if (Client.AccountNumber == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return  _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		clsBankClient Client = Find(AccountNumber);
		return Client.PinCode == PinCode ? Client : _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	static bool IsClientExist(string AccountNumber)
	{
		return !(Find(AccountNumber).IsEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber == _AccountNumber) {
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}



	static vector <clsBankClient> GetClientsList()
	{
		return  _LoadClientsDataFromFile();
	}


	static float GetTotalBalances()
	{
		float TotalBalances = 0;
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();
		for (clsBankClient C : _vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
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
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
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

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void Withdraw(double Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}
	static float GetTotalBalance() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}
};
