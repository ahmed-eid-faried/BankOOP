#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "ListUsers.h"
#include "AddNewUser.h"
#include "DeleteUser.h"
#include "UpdateUser.h"
#include "FindUser.h"
#include "ListUsers.h"
class clsMangeUsersScreen :protected clsScreen {
private:
	enum enMangeUsersMenueOptions {
		eListUsers = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		enMainMenue = 6,
	};
	static	void _BackToMangeUsersMenue() {
		cout << "Press any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
		//system("pause>0");
		_ShowMangeUsersMenue();
	}

	static	void _RoutingMangeUsers(enMangeUsersMenueOptions Option) {
		switch (Option)
		{
		case enMangeUsersMenueOptions::eListUsers:
			system("cls");
			clsListUsersScreen::ListUsers();
			_BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eAddNewUser:
			system("cls");
			clsAddNewUserScreen::AddNewUser();
			_BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eDeleteUser:
			system("cls");
			clsDeleteUserScreen::DeleteUser();
			_BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eUpdateUser:
			system("cls");
			clsUpdateUserScreen::UpdateUser();
			_BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eFindUser:
			system("cls");
			clsFindUserScreen::FindUser();
			_BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::enMainMenue:
			system("cls");
			//ShowMainMenue();
		default:
			break;
		}
	}

	static void _ShowMangeUsersMenue() {
		_DrawScreenHeader("MangeUsers Menue Screen");
 		cout << "\t\t\t\t\t   [1] List Users." << endl;
		cout << "\t\t\t\t\t   [2] Add New User." << endl;
		cout << "\t\t\t\t\t   [3] Delete User." << endl;
		cout << "\t\t\t\t\t   [4] Update User." << endl;
		cout << "\t\t\t\t\t   [5] Find User." << endl;
		cout << "\t\t\t\t\t   [6] Main Menue." << endl;
		cout << "\t\t\t\t ====================================================" << endl;
		enMangeUsersMenueOptions Option = (enMangeUsersMenueOptions)clsUtil::ReadNumberInRange(1, 6, "\t\t\t\t Choose what do you want to do? ");
		_RoutingMangeUsers(Option);
	}


public:
	static void MangeUsers() {
		_ShowMangeUsersMenue();
	}
};