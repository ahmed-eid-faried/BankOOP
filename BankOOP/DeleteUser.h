#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen {

private:
	static void _ShowResultDelete(string UserName) {
		if (!clsUser::IsClientExist(UserName)) {
			cout << "\t\t\t\tYou have successfully deleted the user." << endl;
			cout <<"\t\t\t\t"<< UserName << " is deleted." << endl;
		}
		else {
			cout << "\t\t\t\tit failed to delete " << UserName << endl;
		}
	}

public:
	static void DeleteUser() {
		_DrawScreenHeader("Delete User Screen");
		string UserName = clsUser::ReadUserNameEixsted("\n\t\t\t\tPlease enter UserName? ");;
		clsUser User = clsUser::Find(UserName);
		User.Delete();
		_ShowResultDelete(UserName);
		User.Save();
	}
};