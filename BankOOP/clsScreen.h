#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
using namespace std;
static clsUser CurrentUser = clsUser::Find("", "");

class clsScreen {
public:
	static void  _DrawScreenHeader(string title, string subtitle = "") {
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t\t\t  " << title << endl;
		if (subtitle != "") {
			cout << "\t\t\t\t\t\t" << subtitle << endl;
		}
		cout << "\t\t\t\t====================================================" << endl;
	}

	static 	void DeniedPermissions() {
		cout << "========================================================" << endl;
		cout << "========================================================" << endl;
		cout << "Access Denied" << endl;
		cout << "You don't Have Permiddion To Do This," << endl;
		cout << "Please Conact Your Admin." << endl;
		cout << "========================================================" << endl;
		cout << "========================================================" << endl;
	}
	static bool NivagationPermission(enPermissions Permission) {
		bool state = clsUser::checkPermission(Permission, CurrentUser.Permissions);
		if (!state)	clsScreen::DeniedPermissions();
		return state;
	}
};