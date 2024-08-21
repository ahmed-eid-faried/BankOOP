#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPerson.h"
class clsLogFile {


private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;


	string _Date;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;



	static clsLogFile _ConvertLinetoClientObject(string Line, string Seperator = Seperator)
	{
		vector <string> strClient = clsString::Split(Line, Seperator);
		return clsLogFile(enMode::UpdateMode, strClient[0], strClient[1], strClient[2], stod(strClient[3]));
	}
	static string _ConverClientObjectToLine(clsLogFile Client, string Seperator = Seperator)
	{
		string Line = "";
		Line += Client.Date + Seperator;
		Line += Client.UserName + Seperator;
		Line += Client.Password + Seperator;
		Line += to_string(Client.Permissions);
		return Line;
	}
	static  vector <clsLogFile> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		string Line;
		vector <clsLogFile> Clients;
		MyFile.open(LogFilePathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsLogFile Client = _ConvertLinetoClientObject(Line, Seperator);
				Clients.push_back(Client);
			}
			MyFile.close();
		}
		return Clients;
	}
	static void _SaveCleintsDataToFile(vector <clsLogFile> vClients)
	{
		fstream MyFile;
		MyFile.open(LogFilePathFile, ios::out);//write mode
		if (MyFile.is_open()) {
			string DataLine;
			for (clsLogFile C : vClients)
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
	void _AddDataLineToFile(clsLogFile  Client)
	{
		fstream MyFile;
		MyFile.open(LogFilePathFile, ios::out | ios::app);//append mode or create mode
		if (MyFile.is_open()) {
			string   DataLine = _ConverClientObjectToLine(Client);
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsLogFile> _vUsers;
		_vUsers = _LoadClientsDataFromFile();
		for (clsLogFile& C : _vUsers)
		{
			if (C.UserName == UserName) {
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vUsers);
	}
	void _AddNew()
	{
		_AddDataLineToFile(*this);
	}
	static clsLogFile _GetEmptyClientObject()
	{
		return clsLogFile(enMode::EmptyMode, "", "", "", 0);
	}

public:
	//static clsLogFile CurrentUser ;

	static string ReadUserNameEixsted(string Message = "\t\t\t\tENTER YOUR UserName: ") {
		string UserName = "";
		bool state = false;
		do {
			UserName = clsUtil::ReadString(Message);
			state = (Find(UserName).IsEmpty()) || UserName == "";
			if (state && UserName != "") { cout << "\t\t\t\tThis UserName is existed." << endl; }
			if (UserName == "") { cout << "\t\t\t\tThis UserName is empty, please enter value." << endl; }
		} while (state);
		return UserName;
	}
	static string ReadUserName(string Message = "\t\t\t\tENTER YOUR UserName: ") {
		string UserName = "";
		bool state = false;
		do {
			UserName = clsUtil::ReadString(Message);
			state = (clsLogFile::IsClientExist(UserName)) || UserName == "";
			if (state && UserName != "") { cout << "\t\t\t\tThis UserName is existed." << endl; }
			if (UserName == "") { cout << "\t\t\t\tThis UserName is empty, please enter value." << endl; }
		} while (state);
		return UserName;
	}

	clsLogFile(string Message) : clsLogFile(enMode::EmptyMode, "", "", "", 0) {
		*this = GetAddNewClientObject(ReadUserName(Message));
	}

	clsLogFile(clsUser User) {
		_Mode = enMode::AddNewMode;
		_Date = clsDate::DateTimeToString(clsDate());
		_UserName = User.UserName;
		_Password = User.Password;
		_Permissions = User.Permissions;
	}
	clsLogFile(enMode Mode, string Date, string UserName, string Password,
		int Permissions) {
		_Mode = Mode;
		_Date = Date;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}

	bool IsEmpty()
	{
		return enMode::EmptyMode == _Mode;
	}

	bool MarkedForDeleted() { return _MarkedForDelete; }


	//todo: setter and getter

	//setter and getter
	string GetDate() { return _Date; }
	void SetDate(string Date) { _Date = Date; }
	__declspec(property(get = GetDate, put = SetDate))string Date;

	//setter and getter
	string GetUserName() { return _UserName; }
	void SetUserName(string UserName) { _UserName = UserName; }
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	//setter and getter
	string GetPassword() { return _Password; }
	void SetPassword(string Password) { _Password = Password; }
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	//setter and getter
	int GetPermissions() { return _Permissions; }
	void SetPermissions(int Permissions) { _Permissions = Permissions; }
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;



	void Print()
	{
		cout << "\n\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t___________________";
		cout << "\n\t\t\t\tDate       : " << Date;
		cout << "\n\t\t\t\tUserName    : " << _UserName;
		cout << "\n\t\t\t\tPassword    : " << _Password;
		cout << "\n\t\t\t\tPermissions : " << _Permissions;
		cout << "\n\t\t\t\t___________________\n";

	}
	static clsLogFile Find(string UserName)
	{
		//vector <clsLogFile> _vUsers;
		//_vUsers = _LoadClientsDataFromFile();
		//for (clsLogFile C : _vUsers)
		//{
		//	if (C.UserName == UserName) {
		//		return C;
		//		}
		//}
		//return  _GetEmptyClientObject();
		/////////////////////////////////
		fstream MyFile;
		string Line;
		MyFile.open(LogFilePathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsLogFile Client = _ConvertLinetoClientObject(Line, Seperator);
				if (Client.UserName == UserName) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return  _GetEmptyClientObject();
	}
	static clsLogFile Find(string UserName, string Password)
	{
		clsLogFile Client = Find(UserName);
		return Client.Password == Password ? Client : _GetEmptyClientObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };
	static bool IsClientExist(string UserName)
	{
		return !(Find(UserName).IsEmpty());
	}
	bool Delete()
	{
		vector <clsLogFile> _vUsers = _LoadClientsDataFromFile();
		for (clsLogFile& C : _vUsers)
		{
			if (C.UserName == _UserName) {
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(_vUsers);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector <clsLogFile> GetLogsList()
	{
		return  _LoadClientsDataFromFile();
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
			////This will add new record to file or database
			//if (IsClientExist(_UserName))
			//{
			//	return enSaveResults::svFaildUserNameExists;
			//}
			//else
			//{
			_AddNew();
			//We need to set the mode to update after add new
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
			//}

			break;
		}
		}
	}
	static clsLogFile GetAddNewClientObject(string UserName)
	{
		return clsLogFile(enMode::AddNewMode, "", UserName, "", 0);
	}
	static void LogFileRigester(clsUser CurrentUser) {
		clsLogFile LogFile(CurrentUser);
		LogFile.Save();
	}
};
