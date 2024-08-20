#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
using namespace std;

class clsShowClients :protected clsScreen {

private:
	static void PrintClientHeaderTable(vector<clsBankClient> vFile) {
		cout << "\n\t\t\t\t\t\tClient List (" << vFile.size() << ") Client(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t";
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	};
	static void PrintClient(clsBankClient Client) {
		cout << "\t\t";
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.FullName;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	};
	static void PrintClientsBody(vector<clsBankClient> Clients) {
		for (clsBankClient& C : Clients) {
			if (!C.IsEmpty()) { PrintClient(C); cout << endl; }
		}
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ShowClients() {
		_DrawScreenHeader("Show Clients");
		vector<clsBankClient> Clients = clsBankClient::GetClientsList();
		PrintClientHeaderTable(Clients);
		PrintClientsBody(Clients);
	}
};



