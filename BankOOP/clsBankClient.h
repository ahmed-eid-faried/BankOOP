#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

string Seperator = "#//#";
string ClientPathFile = "#//#";

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
		for (clsBankClient C : _vClients)
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
	}

	bool MarkedForDeleted()
	{
	}


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
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}

	static clsBankClient Find(string AccountNumber)
	{


	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{



	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:


		}

		case enMode::UpdateMode:
		{


		}

		case enMode::AddNewMode:
		{

		}
	}





	static bool IsClientExist(string AccountNumber)
	{

	}

	bool Delete()
	{


	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
	}

	static vector <clsBankClient> GetClientsList()
	{
		//return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{


	}


};
