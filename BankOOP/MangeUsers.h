#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
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
 	void BackToMangeUsersMenue() {
		cout << "Press any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
		//system("pause>0");
		ShowMangeUsersMenue();
	}

	void RoutingMangeUsers(enMangeUsersMenueOptions Option) {
		switch (Option)
		{
		case enMangeUsersMenueOptions::eListUsers:
			system("cls");
			ListUsers();
			BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eAddNewUser:
			system("cls");
			AddNewUser();
			BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eDeleteUser:
			system("cls");
			DeleteUser();
			BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eUpdateUser:
			system("cls");
			UpdateUser();
			BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::eFindUser:
			system("cls");
			FindUser();
			BackToMangeUsersMenue();
		case enMangeUsersMenueOptions::enMainMenue:
			system("cls");
			//ShowMainMenue();
		default:
			break;
		}
	}

	void ShowMangeUsersMenue() {
		cout << "====================================================" << endl;
		cout << "\t\MangeUsers Menue Screen\n";
		cout << "====================================================" << endl;
		cout << "\t   [1] List Users." << endl;
		cout << "\t   [2] Add New User." << endl;
		cout << "\t   [3] Delete User." << endl;
		cout << "\t   [4] Update User." << endl;
		cout << "\t   [5] Find User." << endl;
		cout << "\t   [6] Main Menue." << endl;
		cout << "====================================================" << endl;
		enMangeUsersMenueOptions Option = (enMangeUsersMenueOptions)clsUtil::ReadNumberInRange(1, 6, "Choose what do you want to do? ");
		RoutingMangeUsers(Option);
	}


public:
	static void MangeUsers() {

	}
};