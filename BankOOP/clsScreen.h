#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsScreen {
public:
	static void  _DrawScreenHeader(string title, string subtitle = "") {
		cout << "\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t\t\t  " << title << endl;
		if (subtitle != "") {
			cout << "\t\t\t\t\t\t" << subtitle << endl;
		}
		cout << "\t\t\t\t====================================================" << endl;
	}
};