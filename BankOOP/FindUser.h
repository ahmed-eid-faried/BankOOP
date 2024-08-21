#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsFindUserScreen :protected clsScreen {
private:

	static void _ShowResult(string UserName, clsUser User) {
		if (User.IsEmpty()) {
			cout << "\nUser with Account Number (" << UserName << ") is Not Found!" << endl;
		}
		else {
			User.Print();
		}
	}
public:
	static void FindUser() {
		_DrawScreenHeader("Find User");
		string UserName = clsUser::ReadUserNameEixsted("\nPlease enter UserName? ");;
		clsUser User = clsUser::Find(UserName);
		_ShowResult(UserName, User);
	}
};