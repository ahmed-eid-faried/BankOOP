#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsMainMenue.h"

using namespace std;
class clsLoginScreen :protected clsScreen {
private:
	static void _Exiting() {
		cout << endl << endl << endl;
		cout << "\t\t\t\tExiting the CLI" << endl;
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t\t\tEND PROGRAM:(\n";
		cout << "\t\t\t\t====================================================" << endl;
		exit(0);
	}
public:

	static void LoginScreen() {
		bool IsFinsh = false;
		int Invalid = 0;
		while (!IsFinsh)
		{
			if (Invalid >= 3) { _Exiting(); }
			system("cls");
			CurrentUser = clsUser::Find("", "");
			_DrawScreenHeader("Login");
			if (Invalid > 0) {
				cout << "\n\t\t\t\tUser Name Or Password is Not Correct!" << endl;
				cout << "\t\t\t\tYou have " << 3 - Invalid << " Trials to login" << endl << endl;
			}
			string Name = clsUtil::ReadString("\t\t\t\tEnter your Name    : ");
			string Password = clsUtil::ReadString("\t\t\t\tEnter your Password: ");
			clsUser User = clsUser::Find(Name, Password);
			if (!User.IsEmpty()) {
				IsFinsh = true;
				CurrentUser = User;
				system("cls");
				clsMainMenueScreen::ShowMainMenue();
			}
			else {
				Invalid++;
			}
		};
	}
};
