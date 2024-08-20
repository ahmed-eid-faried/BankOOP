#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTotalBalancesScreen :protected clsScreen {
private:
	static void _PrintClientHeaderTotalBalances(vector<clsBankClient> Clients) {
		cout << "\n\t\t\t\t\tClient List (" << Clients.size() << ") Client(s).";
		cout << "\n\t\t\t\t_____________________________________________________\n" << endl;
 		cout << "\t\t\t\t";
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(24) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\t\t\t\t_____________________________________________________\n" << endl;

	};
	static void _PrintClientTotalBalances(clsBankClient Client) {
		cout << "\t\t\t\t";
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(24) << left << Client.FullName;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	};
	static void _ReadFileByVectorTotalBalances(vector<clsBankClient>& Clients) {
		for (clsBankClient& Client : Clients) {
			if (!Client.IsEmpty())
			{
				_PrintClientTotalBalances(Client);
				cout << endl;
			}
		}
		cout << "\n\t\t\t\t_____________________________________________________\n" << endl;

	}

	static	void _TotalBalances() {
		vector<clsBankClient> Clients = clsBankClient::GetClientsList();
		float TotalBalances = clsBankClient::GetTotalBalance();
		_DrawScreenHeader("Total Balances Screen");
		_PrintClientHeaderTotalBalances(Clients);
		_ReadFileByVectorTotalBalances(Clients);
		cout << "\t\t\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
		cout << endl;
	}
public:
	static void TotalBalances() {
		_TotalBalances();
	}
};