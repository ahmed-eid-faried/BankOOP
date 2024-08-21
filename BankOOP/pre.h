#pragma once
#include <iostream>
#include "clsUtil.h"
using namespace std;
  
class AccessDeniedScreen {
	void DeniedPermissions() {
		cout << "========================================================" << endl;
		cout << "========================================================" << endl;
		cout << "Access Denied" << endl;
		cout << "You don't Have Permiddion To Do This," << endl;
		cout << "Please Conact Your Admin." << endl;
		cout << "========================================================" << endl;
		cout << "========================================================" << endl;
	}
};

 