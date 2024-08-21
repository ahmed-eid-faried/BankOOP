 #pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "LogFile.h"
using namespace std;

class LogFileRigesterScreen :protected clsScreen {

private:
	static void PrintLogHeaderTable(vector<clsLogFile> vFile) {
		cout << "\n\t\t\t\t\t\tLog List (" << vFile.size() << ") Log(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t";
		cout << "| " << left << setw(40) << "Date / Time";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(10) << "Password";
 		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	};
	static void PrintLog(clsLogFile Log) {
		cout << "\t\t";
		cout << "| " << setw(40) << left << Log.Date;
		cout << "| " << setw(15) << left << Log.UserName;
		cout << "| " << setw(10) << left << Log.Password;
		cout << "| " << setw(12) << left << Log.Permissions;
	};
	static void PrintLogsBody(vector<clsLogFile> Logs) {
		for (clsLogFile& C : Logs) {
			if (!C.IsEmpty()) { PrintLog(C); cout << endl; }
		}
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ShowLogs() {
		_DrawScreenHeader("Login Register Screen");
		vector<clsLogFile> Logs = clsLogFile::GetLogsList();
		PrintLogHeaderTable(Logs);
		PrintLogsBody(Logs);
	}
};



