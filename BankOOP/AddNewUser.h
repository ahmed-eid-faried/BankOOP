#pragma once
#include <string>
#include "clsScreen.h"
using namespace std;

class clsAddNewUserScreen :protected clsScreen {
private:
	static clsUser _ReadNewUser() {
		clsUser User("\t\t\t\tENTER YOUR UserName: ");
		User.Password = clsUtil::ReadString("\t\t\t\tENTER YOUR Password: ");
		User.FirstName = clsUtil::ReadString("\t\t\t\tENTER YOUR FirstName: ");
		User.LastName = clsUtil::ReadString("\t\t\t\tENTER YOUR LastName: ");
		User.Phone = clsUtil::ReadString("\t\t\t\tENTER YOUR Phone: ");
		User.Permissions = clsUser::ReadPermissions();
 		return User;
	};

public:
	static void AddNewUser() {
		do {
			system("cls");
			_DrawScreenHeader("Add New User");
			cout << "\n\n\t\t\t\tPlease Enter User Data:  " << endl;
			cout << "\t\t\t\t===========================" << endl;
			clsUser User = _ReadNewUser();
			cout << "\n\n\t\t\t\tUser Record for Saving is: \n";
			User.Save();
		} while (clsUtil::ReadBool("\n\t\t\t\tUser Added Successfully, do you want to add more clients? "));
	}
};