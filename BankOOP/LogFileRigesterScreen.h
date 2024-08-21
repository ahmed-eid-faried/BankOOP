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
		cout << "__________________________________\n" << endl;
		cout << "\t\t";
		cout << "| " << left << setw(34) << "Date / Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(16) << "Password";
 		cout << "| " << left << setw(16) << "Permissions";
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
	};
	static void PrintLog(clsLogFile Log) {
		cout << "\t\t";
		cout << "| " << setw(35) << left << Log.Date;
		cout << "| " << setw(20) << left << Log.UserName;
		cout << "| " << setw(16) << left << Log.Password;
		cout << "| " << setw(16) << left << Log.Permissions;
	};
	static void PrintLogsBody(vector<clsLogFile> Logs) {
		for (clsLogFile& C : Logs) {
			if (!C.IsEmpty()) { PrintLog(C); cout << endl; }
		}
		cout << "\n\t\t_______________________________________________________";
		cout << "__________________________________\n" << endl;
	}
public:
	static void ShowLogs() {
		_DrawScreenHeader("Login Register Screen");
		vector<clsLogFile> Logs = clsLogFile::GetLogsList();
		PrintLogHeaderTable(Logs);
		PrintLogsBody(Logs);
	}
};



