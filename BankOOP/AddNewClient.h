#pragma once
#include <string>
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen :protected clsScreen {
private:
	static clsBankClient _ReadNewClient() {
		clsBankClient Client("\t\t\t\tENTER YOUR AccountNumber: ");
		Client.PinCode = clsUtil::ReadString("\t\t\t\tENTER YOUR PinCode: ");
		Client.FirstName = clsUtil::ReadString("\t\t\t\tENTER YOUR FirstName: ");
		Client.LastName = clsUtil::ReadString("\t\t\t\tENTER YOUR LastName: ");
		Client.Phone = clsUtil::ReadString("\t\t\t\tENTER YOUR Phone: ");
		Client.AccountBalance = clsUtil::ReadDoubleNumber("\t\t\t\tENTER YOUR AccountBalance: ");
		return Client;
	};

public:
	static void AddNewClient() {
		do {
			system("cls");
			_DrawScreenHeader("Add New Client");
			cout << "\n\n\t\t\t\tPlease Enter Client Data:  " << endl;
			cout << "\t\t\t\t===========================" << endl;
			clsBankClient Client = _ReadNewClient();
			cout << "\n\n\t\t\t\tClient Record for Saving is: \n";
			Client.Save();
		} while (clsUtil::ReadBool("\n\t\t\t\tClient Added Successfully, do you want to add more clients? "));
	}

};