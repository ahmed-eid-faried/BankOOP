#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "clsScreen.h"
#include "clsUser.h" 
class clsUpdateUserScreen :protected clsScreen {
private:

	static	clsUser _ReadUpdateUser(clsUser User) {
		User.UserName = clsUtil::ReadString("\t\t\t\tENTER YOUR UserName: ");
		User.Password = clsUtil::ReadString("\t\t\t\tENTER YOUR Password: ");
		User.FirstName = clsUtil::ReadString("\t\t\t\tENTER YOUR FirstName: ");
		User.LastName = clsUtil::ReadString("\t\t\t\tENTER YOUR LastName: ");
		User.Phone = clsUtil::ReadString("\t\t\t\tENTER YOUR Phone: ");
		User.Permissions = clsUser::ReadPermissions();
		User.Update();
		return User;
	};

public:
	static void UpdateUser() {
		_DrawScreenHeader("Update User");
		string UserName = clsUser::ReadUserNameEixsted("\n\t\t\t\tPlease enter UserName? ");;
		clsUser User = clsUser::Find(UserName);
		User = _ReadUpdateUser(User);
		User.Save();
		User.Print();
	}
};