#pragma once
#include <string>
#include <vector>
#include "clsUser.h"
using namespace std;

class clsListUsers :protected clsScreen {

private:
	static void PrintUserHeaderTable(vector<clsUser> vFile) {
		cout << "\n\t\t\t\t\t\tUser List (" << vFile.size() << ") User(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(40) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	};
	static void PrintUser(clsUser User) {
		cout << "\t\t";
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(40) << left << User.FullName;
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(12) << left << User.Permissions;
	};
	static void PrintUsersBody(vector<clsUser> Users) {
		for (clsUser& C : Users) {
			if (!C.IsEmpty()) { PrintUser(C); cout << endl; }
		}
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ListUsers() {
		_DrawScreenHeader("List Users");
		vector<clsUser> Users = clsUser::GetClientsList();
		PrintUserHeaderTable(Users);
		PrintUsersBody(Users);
	}
};



