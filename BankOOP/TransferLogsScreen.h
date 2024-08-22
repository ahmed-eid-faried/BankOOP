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
		cout << "| " << left << setw(22) << "Date / Time";
		cout << "| " << left << setw(10) << "Acc. From";
		cout << "| " << left << setw(10) << "Acc. To";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "Bal. From";
		cout << "| " << left << setw(10) << "Bal. To";
		cout << "| " << left << setw(10) << "User";
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
	};
	static void PrintLog(clsBankClient::LogTransfer Log) {
		cout << "\t\t";
		cout << "| " << setw(22) << left << Log.DateTime;
		cout << "| " << setw(10) << left << Log.AccountFrom;
		cout << "| " << setw(10) << left << Log.AccountTo;
		cout << "| " << setw(8) << left << Log.Amount;
		cout << "| " << setw(10) << left << Log.BalanceAfter1;
		cout << "| " << setw(10) << left << Log.BalanceAfter2;
		cout << "| " << setw(10) << left << Log.User;
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



