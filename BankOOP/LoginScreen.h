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

public:

	static void LoginScreen() {
		bool IsFinsh = false;
		bool Invalid = false;
		while (!IsFinsh)
		{
			system("cls");
			CurrentUser = clsUser::Find("", "");
			_DrawScreenHeader("Login");
			if (Invalid) { cout << "\nUser Name Or Password is Not Correct!" << endl << endl; }
			string Name = clsUtil::ReadString("Enter your Name    : ");
			string Password = clsUtil::ReadString("Enter your Password: ");
			clsUser User = clsUser::Find(Name, Password);
			if (!User.IsEmpty()) {
				IsFinsh = true;
				CurrentUser = User;
				system("cls");
				clsMainMenueScreen::ShowMainMenue();
			}
			else {
				Invalid = true;
			}
		};
	}
};
