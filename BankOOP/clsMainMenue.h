#pragma once
#include <string>
#include "pre.h"
#include "clsScreen.h"
#include "ShowClients.h"
#include "AddNewClient.h"
#include "clsDeleteClient.h"
#include "UpdateClient.h"
#include "FindClient.h"
#include "Transactions.h"
#include "MangeUsers.h"
#include "LoginScreen.h"
using namespace std;
class clsMainMenueScreen :protected clsScreen {
private:
	//void LoginScreen();
	enum enMainMenueOptions {
		eShowClients = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClientInfo = 4,
		eFindClient = 5,
		eTransactions = 6,
		eMangeUsers = 7,
		eExiting = 8,
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
	static void _LoginScreen() {
		clsLoginScreen::LoginScreen();
	}
	static void _Routing(enMainMenueOptions Option) {
		switch (Option)
		{
		case enMainMenueOptions::eShowClients:
			system("cls");
			_ShowClients();
			//checkPermission(enPermissions::PERMISSION_ListUsers) ? _ShowClients() : DeniedPermissions();
			BackToMainMenue();
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_AddNewClient();
			//checkPermission(enPermissions::PERMISSION_Add) ? _AddNewClient() : DeniedPermissions();
			BackToMainMenue();
		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_DeleteClient();
			//checkPermission(enPermissions::PERMISSION_Delete) ? _DeleteClient() : DeniedPermissions();
			BackToMainMenue();
		case enMainMenueOptions::eUpdateClientInfo:
			system("cls");
			_UpdateClientInfo();
			//checkPermission(enPermissions::PERMISSION_Update) ? _UpdateClientInfo() : DeniedPermissions();
			BackToMainMenue();
		case enMainMenueOptions::eFindClient:
			system("cls");
			_FindClient();
			//checkPermission(enPermissions::PERMISSION_Find) ? _FindClient() : DeniedPermissions();
			BackToMainMenue();
		case enMainMenueOptions::eTransactions:
			system("cls");
			_Transactions();
			//checkPermission(enPermissions::PERMISSION_Transactions) ? _Transactions() : DeniedPermissions();
			//BackToMainMenue();
			system("cls");
			ShowMainMenue();
		case enMainMenueOptions::eMangeUsers:
			system("cls");
			_MangeUsers();
			//checkPermission(enPermissions::PERMISSION_MangeUsers) ? _MangeUsers() : DeniedPermissions();
			//BackToMainMenue();
			system("cls");
			ShowMainMenue();
		case enMainMenueOptions::eExiting:
			system("cls");
			_LoginScreen();
			//Exiting();
		default:
			break;
		}
	}
public:
	static void BackToMainMenue() {
		cout << "Press any key to go back to Main Menu...";
		cin.ignore(); // Clear the input buffer
		cin.get();    // Wait for a key press
		system("cls"); // Clear the screen
		//system("pause>0");
		ShowMainMenue();
	}

	static void ShowMainMenue() {
		_DrawScreenHeader("Main Menue Screen");
		cout << "\t\t\t\t\t   [1] Show Client List." << endl;
		cout << "\t\t\t\t\t   [2] Add New Client." << endl;
		cout << "\t\t\t\t\t   [3] Delete Client." << endl;
		cout << "\t\t\t\t\t   [4] Update Client info." << endl;
		cout << "\t\t\t\t\t   [5] Find Client." << endl;
		cout << "\t\t\t\t\t   [6] Transactions Menue." << endl;
		cout << "\t\t\t\t\t   [7] Mange Users Menue." << endl;
		cout << "\t\t\t\t\t   [8] Logout." << endl;
		cout << "\t\t\t\t====================================================" << endl;
		enMainMenueOptions Option = (enMainMenueOptions)clsUtil::ReadNumberInRange(1, 8, "\t\t\t\tChoose what do you want to do? ");
		_Routing(Option);
	}
};