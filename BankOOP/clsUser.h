#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPerson.h"

using namespace std;

class clsUser : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;


	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;



	static clsUser _ConvertLinetoClientObject(string Line, string Seperator = Seperator)
	{
		vector <string> strClient = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, strClient[0], strClient[1], strClient[2], strClient[3], strClient[4],
			clsUtil::DecryptText(strClient[5]), stod(strClient[6]));
	}
	static string _ConverClientObjectToLine(clsUser Client, string Seperator = Seperator)
	{
		string Line = "";
		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.UserName + Seperator;
		Line += clsUtil::EncryptText(Client.Password) + Seperator;
		Line += to_string(Client.Permissions);
		return Line;
	}
	static  vector <clsUser> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		string Line;
		vector <clsUser> Clients;
		MyFile.open(UsersPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLinetoClientObject(Line, Seperator);
				Clients.push_back(Client);
			}
			MyFile.close();
		}
		return Clients;
	}
	static void _SaveCleintsDataToFile(vector <clsUser> vClients)
	{
		fstream MyFile;
		MyFile.open(UsersPathFile, ios::out);//write mode
		if (MyFile.is_open()) {
			string DataLine;
			for (clsUser C : vClients)
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
	void _AddDataLineToFile(clsUser  Client)
	{
		fstream MyFile;
		MyFile.open(UsersPathFile, ios::out | ios::app);//append mode or create mode
		if (MyFile.is_open()) {
			string   DataLine = _ConverClientObjectToLine(Client);
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadClientsDataFromFile();
		for (clsUser& C : _vUsers)
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
	static clsUser _GetEmptyClientObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	//static clsUser CurrentUser ;

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
			state = (clsUser::IsClientExist(UserName)) || UserName == "";
			if (state && UserName != "") { cout << "\t\t\t\tThis UserName is existed." << endl; }
			if (UserName == "") { cout << "\t\t\t\tThis UserName is empty, please enter value." << endl; }
		} while (state);
		return UserName;
	}

	clsUser(string Message) : clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0) {
		*this = GetAddNewClientObject(ReadUserName(Message));
	}


	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
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
		cout << "\n\t\t\t\tFirstName   : " << FirstName;
		cout << "\n\t\t\t\tLastName    : " << LastName;
		cout << "\n\t\t\t\tFull Name   : " << FullName;
		cout << "\n\t\t\t\tEmail       : " << Email;
		cout << "\n\t\t\t\tPhone       : " << Phone;
		cout << "\n\t\t\t\tUserName    : " << _UserName;
		cout << "\n\t\t\t\tPassword    : " << _Password;
		cout << "\n\t\t\t\tPermissions : " << _Permissions;
		cout << "\n\t\t\t\t___________________\n";

	}

	static clsUser Find(string UserName)
	{
		//vector <clsUser> _vUsers;
		//_vUsers = _LoadClientsDataFromFile();
		//for (clsUser C : _vUsers)
		//{
		//	if (C.UserName == UserName) {
		//		return C;
		//		}
		//}
		//return  _GetEmptyClientObject();
		/////////////////////////////////
		fstream MyFile;
		string Line;
		MyFile.open(UsersPathFile, ios::in);//read mode
		if (MyFile.is_open()) {
			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLinetoClientObject(Line, Seperator);
				if (Client.UserName == UserName) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return  _GetEmptyClientObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		clsUser Client = Find(UserName);
		return Client.Password == Password ? Client : _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

	static bool IsClientExist(string UserName)
	{
		return !(Find(UserName).IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers = _LoadClientsDataFromFile();
		for (clsUser& C : _vUsers)
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



	static vector <clsUser> GetClientsList()
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
			//This will add new record to file or database
			if (IsClientExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExists;
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

	static clsUser GetAddNewClientObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	// ���� ���� ��������
	static int setPermissions(sPermissions Permissions) {
		return Permissions.ListUsers | Permissions.Add | Permissions.Delete | Permissions.Update | Permissions.FIND | Permissions.Transactions | Permissions.MangeUsers | Permissions.LogFile;
	}

	// ���� ������ �� ��������
	static bool checkPermission(enPermissions permission, int permissions) {
		return (permissions & permission) != 0;
	}
	// ���� ������ ������ �����
	static int addPermissions(int permissions, enPermissions permToAdd) {
		return permissions | permToAdd;
	}

	// ���� ������ ������
	static int removePermissions(int permissions, enPermissions permToRemove) {
		return permissions & ~permToRemove;
	}

	static int ReadPermissions() {
		sPermissions Permissions;
		bool AllPermissions = clsUtil::ReadBool("\t\t\t\tARE YOU GIVE All Permissions FOR This USER?");
		if (AllPermissions) {
			Permissions.ListUsers = enPermissions::PERMISSION_AllPermissions;
			Permissions.Add = enPermissions(0);
			Permissions.Delete = enPermissions(0);
			Permissions.Update = enPermissions(0);
			Permissions.FIND = enPermissions(0);
			Permissions.Transactions = enPermissions(0);
			Permissions.MangeUsers = enPermissions(0);
			Permissions.LogFile = enPermissions(0);
		}
		else
		{
			Permissions.ListUsers = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Show USER?") ? enPermissions::PERMISSION_ListUsers : enPermissions(0);
			Permissions.Add = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Add USER?") ? enPermissions::PERMISSION_Add : enPermissions(0);
			Permissions.Delete = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Delete USER?") ? enPermissions::PERMISSION_Delete : enPermissions(0);
			Permissions.Update = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Update USER?") ? enPermissions::PERMISSION_Update : enPermissions(0);
			Permissions.FIND = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Find USER?") ? enPermissions::PERMISSION_Find : enPermissions(0);
			Permissions.Transactions = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR Transactions?") ? enPermissions::PERMISSION_Transactions : enPermissions(0);
			Permissions.MangeUsers = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR MangeUsers?") ? enPermissions::PERMISSION_MangeUsers : enPermissions(0);
			Permissions.LogFile = clsUtil::ReadBool("\t\t\t\tARE YOU Permission FOR LogFile Rigester?") ? enPermissions::PERMISSION_LogFile : enPermissions(0);

		}
		return setPermissions(Permissions);
	}
};
