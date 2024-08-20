#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
class clsDepositScreen :protected clsScreen {
private:
	//clsBankClient ReadDepositClient(clsBankClient vClient, double DepositValue) {
	//	clsBankClient client;
	//	client.AccountNumber = vClient.AccountNumber;
	//	client.PinCode = vClient.PinCode;
	//	client.Name = vClient.Name;
	//	client.Phone = vClient.Phone;
	//	if ((vClient.AccountBalance + DepositValue) < 0) {
	//		client.AccountBalance = vClient.AccountBalance;
	//		cout << "The value you entered is incorrect." << endl;
	//		BackToMainMenue();
	//	}
	//	else {
	//		client.AccountBalance = vClient.AccountBalance + DepositValue;
	//	}
	//	return client;
	//};
	//vector <clsBankClient> SaveDepositCleintsDataToFile(string FileName, vector<clsBankClient> vClients, double DepositValue) {
	//	fstream MyFile;

	//	MyFile.open(FileName, ios::out);
	//	//overwrite
	//	string  DataLine;
	//	if (MyFile.is_open()) {
	//		for (clsBankClient C : vClients) {
	//			if (C.MarkForUpdate == false) {
	//				//we only write records that are not marked for delete.  
	//				DataLine = ConvertRecordToLine(C, Seperator);
	//				MyFile << DataLine << endl;
	//			}
	//			else {
	//				DataLine = ConvertRecordToLine(ReadDepositClient(C, DepositValue), Seperator);
	//				MyFile << DataLine << endl;
	//			}
	//		}         MyFile.close();
	//	} return vClients;
	//}
	//bool DepositClientByAccountNumber(string AccountNumber, vector<clsBankClient>& vClients, double DepositValue) {
	//	clsBankClient Client;
	//	char Answer = 'n';
	//	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
	//		PrintClientCard(Client);
	//		cout << "\n\nAre you sure you want update this client? y/n ? ";
	//		cin >> Answer;
	//		if (Answer == 'y' || Answer == 'Y') {
	//			MarkClientForUpdateByAccountNumber(AccountNumber, vClients);
	//			SaveDepositCleintsDataToFile(ClientsFileName, vClients, DepositValue);
	//			vClients = LoadCleintsDataFromFile(ClientsFileName);
	//			return true;
	//		}
	//	}
	//	else {
	//		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	//		return false;
	//	}
	//}
	//void Deposit() {
	//	cout << "====================================================" << endl;
	//	cout << "\t\tDeposit Client\n";
	//	cout << "====================================================" << endl;
	//	vector <clsBankClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	//	string AccountNumber = ReadClientAccountNumber();
	//	double DepositValue = ReadDoubleNumber("ENTER YOUR Deposit Value: ");
	//	DepositClientByAccountNumber(AccountNumber, vClients, DepositValue);
	//}

public:
	static void Deposit() {
		_DrawScreenHeader("Deposit Client");
		string AccountNumber = clsBankClient::ReadAccountNumberEixsted("\nPlease enter AccountNumber? ");;
		double DepositValue = clsUtil::ReadDoubleNumber("ENTER YOUR Deposit Value: ");
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Deposit(DepositValue);
		//_ShowResult(AccountNumber, Client);
	}
};