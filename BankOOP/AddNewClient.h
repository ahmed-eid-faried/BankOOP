#pragma once
#include <string>
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen :protected clsScreen {
private:
	static clsBankClient _ReadNewClient() {
		clsBankClient Client("ENTER YOUR AccountNumber: ");
		Client.PinCode = clsUtil::ReadString("ENTER YOUR PinCode: ");
		Client.FirstName = clsUtil::ReadString("ENTER YOUR FirstName: ");
		Client.LastName = clsUtil::ReadString("ENTER YOUR LastName: ");
		Client.Phone = clsUtil::ReadString("ENTER YOUR Phone: ");
		Client.AccountBalance = clsUtil::ReadDoubleNumber("ENTER YOUR AccountBalance: ");
		return Client;
	};

public:
	static void AddNewClient() {
		do {
			system("cls");
			_DrawScreenHeader("Add New Client");
			cout << "\n\nPlease Enter Client Data:  " << endl;
			cout << "===========================" << endl;
			clsBankClient Client = _ReadNewClient();
			cout << "\n\nClient Record for Saving is: \n";
			Client.Save();
		} while (clsUtil::ReadBool("\nClient Added Successfully, do you want to add more clients? "));
	}

};