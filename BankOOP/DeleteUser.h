#pragma once
#pragma once
#include "clsScreen.h"
 

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
			cout << "You have successfully deleted the user." << endl;
			cout << UserName << " is deleted." << endl;
		}
		else {
			cout << "it failed to delete " << UserName << endl;
		}
	}

public:
	static void DeleteUser() {
		_DrawScreenHeader("Delete User Screen");
		string UserName = clsUser::ReadUserNameEixsted("\nPlease enter UserName? ");;
		clsUser User = clsUser::Find(UserName);
		User.Delete();
		_ShowResultDelete(UserName);
		User.Save();
	}
};