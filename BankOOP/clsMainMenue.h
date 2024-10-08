#pragma once
#include <string>
#include "clsScreen.h"
#include "ShowClients.h"
#include "AddNewClient.h"
#include "clsDeleteClient.h"
#include "UpdateClient.h"
#include "FindClient.h"
#include "Transactions.h"
#include "MangeUsers.h"
#include "clsUser.h"
#include "LoginScreen.h"
#include "LogFileRigesterScreen.h"
#include "CurrencyExhange.h"
using namespace std;
static void LoginScreen();
class clsMainMenueScreen :protected clsScreen {
private:
	enum enMainMenueOptions {
		eShowClients = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClientInfo = 4,
		eFindClient = 5,
		eTransactions = 6,
		eMangeUsers = 7,
		eLogFile = 8,
		eCurrency = 9,
		eExiting = 10,
	};
	static void _Exiting() {
		cout << "Exiting the CLI" << endl;
		cout << "====================================================" << endl;
		cout << "\t\tEND PROGRAM:(\n";
		cout << "====================================================" << endl;
		exit(0);
	}
	static void _ShowClients() {
		clsShowClients::ShowClients();
	}
	static void _AddNewClient() {
		clsAddNewClientScreen::AddNewClient();
	}
	static void _DeleteClient() {
		clsDeleteClientScreen::DeleteClient();
	}
	static void _UpdateClientInfo() {
		clsUpdateClientScreen::UpdateClient();
	}
	static void _FindClient() {
		clsFindClientScreen::FindClient();
	}
	static void _Transactions() {
		clsTransactionsScreen::Transactions();
	}

	static void _MangeUsers() {
		clsMangeUsersScreen::MangeUsers();
	}
	static void _ShowLog() {
		LogFileRigesterScreen::ShowLogs();
	}
	static void _Currency() {
		clsCurrencyScreen::Currency();
	}
	static void _LoginScreen() {
		//callstak
		// clsLoginScreen::LoginScreen();
	}
	static void _Routing(enMainMenueOptions Option) {
		switch (Option)
		{
		case enMainMenueOptions::eShowClients:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_ListUsers)) { _ShowClients(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Add)) { _AddNewClient(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eDeleteClient:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Delete)) { _DeleteClient(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eUpdateClientInfo:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Update)) { _UpdateClientInfo(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eFindClient:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Find)) { _FindClient(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eTransactions:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Transactions)) { _Transactions(); };
			system("cls");
			ShowMainMenue();
		case enMainMenueOptions::eMangeUsers:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_MangeUsers)) { _MangeUsers(); };
			system("cls");
			ShowMainMenue();
		case enMainMenueOptions::eLogFile:
			system("cls");
			if (clsScreen::NivagationPermission(enPermissions::PERMISSION_LogFile)) { _ShowLog(); };
			BackToMainMenue();
			break;
		case enMainMenueOptions::eCurrency:
			system("cls");
			_Currency();
			//if (clsScreen::NivagationPermission(enPermissions::PERMISSION_Currency)) { _Currency(); };
			system("cls");
			ShowMainMenue();
			break;
	case enMainMenueOptions::eExiting:
			system("cls");
			_LoginScreen();
			//Exiting();
			break;
		default:
			break;
		}
	}
public:
	static void BackToMainMenue() {
		cout << "\t\t\t\tPress any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
		//system("pause>0");
		ShowMainMenue();
	}

	static void ShowMainMenue() {
		_DrawScreenHeader("Main Menue Screen");
		cout << "\t\t\t\t\t   [1]  Show Client List." << endl;
		cout << "\t\t\t\t\t   [2]  Add New Client." << endl;
		cout << "\t\t\t\t\t   [3]  Delete Client." << endl;
		cout << "\t\t\t\t\t   [4]  Update Client info." << endl;
		cout << "\t\t\t\t\t   [5]  Find Client." << endl;
		cout << "\t\t\t\t\t   [6]  Transactions Menue." << endl;
		cout << "\t\t\t\t\t   [7]  Mange Users Menue." << endl;
		cout << "\t\t\t\t\t   [8]  Login Register Screen." << endl;
		cout << "\t\t\t\t\t   [9]  Currency Exhange Menue." << endl;
		cout << "\t\t\t\t\t   [10] Logout." << endl;
		cout << "\t\t\t\t====================================================" << endl;
		enMainMenueOptions Option = (enMainMenueOptions)clsUtil::ReadNumberInRange(1, 10, "\t\t\t\tChoose what do you want to do? ");
		_Routing(Option);
	}
};