#pragma once
#pragma once
#include "clsScreen.h"

class clsUpdateUserScreen : protected clsScreen {
private:
public:
	static void UpdateUser() {}
};
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsUser.h" 
class clsUpdateUserScreen :protected clsScreen {
private:

	static	clsUser _ReadUpdateUser(clsUser User) {
		User.UserName = clsUtil::ReadString("ENTER YOUR UserName: ");
		User.Password = clsUtil::ReadString("ENTER YOUR Password: ");
		User.FirstName = clsUtil::ReadString("ENTER YOUR FirstName: ");
		User.LastName = clsUtil::ReadString("ENTER YOUR LastName: ");
		User.Phone = clsUtil::ReadString("ENTER YOUR Phone: ");
		User.Permissions = clsUtil::ReadDoubleNumber("ENTER YOUR Permssions: ");
		User.Update();
		return User;
	};

public:
	static void UpdateUser() {
		_DrawScreenHeader("Update User");
		string UserName = clsUser::ReadUserNameEixsted("\nPlease enter UserName? ");;
		clsUser User = clsUser::Find(UserName);
		User = _ReadUpdateUser(User);
		User.Save();
		User.Print();
	}
};