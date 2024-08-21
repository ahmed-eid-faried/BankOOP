#pragma once
#include <string>
#include "clsScreen.h"
using namespace std;

class clsAddNewUserScreen :protected clsScreen {
private:
	static clsUser _ReadNewUser() {
		clsUser User("ENTER YOUR UserName: ");
		User.Password = clsUtil::ReadString("ENTER YOUR Password: ");
		User.FirstName = clsUtil::ReadString("ENTER YOUR FirstName: ");
		User.LastName = clsUtil::ReadString("ENTER YOUR LastName: ");
		User.Phone = clsUtil::ReadString("ENTER YOUR Phone: ");
		User.Permissions = clsUser::ReadPermissions();
 		return User;
	};

public:
	static void AddNewUser() {
		do {
			system("cls");
			_DrawScreenHeader("Add New User");
			cout << "\n\nPlease Enter User Data:  " << endl;
			cout << "===========================" << endl;
			clsUser User = _ReadNewUser();
			cout << "\n\nUser Record for Saving is: \n";
			User.Save();
		} while (clsUtil::ReadBool("\nUser Added Successfully, do you want to add more clients? "));
	}

};