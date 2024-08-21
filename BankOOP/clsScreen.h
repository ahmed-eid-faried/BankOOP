#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
using namespace std;
static clsUser CurrentUser = clsUser::Find("", "");

class clsScreen {
	static void _BackToMainMenue() {
		cout << "\t\t\t\tPress any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
	}
public:
	static void  _DrawScreenHeader(string title, string subtitle = "") {
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t\t\t  " << title << endl;
		if (subtitle != "") {
			cout << "\t\t\t\t\t\t" << subtitle << endl;
		}
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\tUser:" << CurrentUser.UserName << endl;
		clsDate Date;
		cout << "\t\t\t\tDate:" << Date.DateToString() << endl;
		cout << "\t\t\t\t====================================================" << endl;
	}

	static 	void DeniedPermissions() {
		_DrawScreenHeader("Access Denied");
		cout << endl << endl;
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\tAccess Denied" << endl;
		cout << "\t\t\t\tYou don't Have Permiddion To Do This," << endl;
		cout << "\t\t\t\tPlease Conact Your Admin." << endl;
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t====================================================" << endl;
		_BackToMainMenue();
	}
	static bool NivagationPermission(enPermissions Permission) {
		bool state = clsUser::checkPermission(Permission, CurrentUser.Permissions);
		if (!state)	clsScreen::DeniedPermissions();
		return state;
	}
};