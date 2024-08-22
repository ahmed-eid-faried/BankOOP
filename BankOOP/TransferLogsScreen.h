#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "LogFile.h"
#include "clsBankClient.h"
using namespace std;

class LogFileTransferScreen :protected clsScreen {

private:
	static void PrintLogHeaderTable(vector<clsBankClient::LogTransfer> vFile) {
		cout << "\n\t\t\t\t\t\tLog List (" << vFile.size() << ") Log(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
		cout << "\t\t";
		cout << "| " << left << setw(30) << "Date / Time";
		cout << "| " << left << setw(16) << "AccountFrom";
		cout << "| " << left << setw(16) << "AccountTo";
		cout << "| " << left << setw(16) << "Amount";
		cout << "| " << left << setw(16) << "BalanceAfter1";
		cout << "| " << left << setw(16) << "BalanceAfter2";
		cout << "| " << left << setw(16) << "User";
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
	};
	static void PrintLog(clsBankClient::LogTransfer Log) {
		cout << "\t\t";
		cout << "| " << setw(30) << left << Log.DateTime;
		cout << "| " << setw(16) << left << Log.AccountFrom;
		cout << "| " << setw(16) << left << Log.AccountTo;
		cout << "| " << setw(16) << left << Log.Amount;
		cout << "| " << setw(16) << left << Log.BalanceAfter1;
		cout << "| " << setw(16) << left << Log.BalanceAfter2;
		cout << "| " << setw(16) << left << Log.User;
	};
	static void PrintLogsBody(vector<clsBankClient::LogTransfer> Logs) {
		for (clsBankClient::LogTransfer& C : Logs) {
			PrintLog(C); cout << endl;
		}
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
	}
public:
	static void ShowLogs() {
		_DrawScreenHeader("Transfer Logs Screen");
		vector<clsBankClient::LogTransfer> Logs = clsBankClient::GetTransferLogs();
		PrintLogHeaderTable(Logs);
		PrintLogsBody(Logs);
	}
};



