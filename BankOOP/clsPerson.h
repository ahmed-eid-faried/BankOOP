#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsPerson {
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string  FirstName, string  LastName, string  Email, string  Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//setter and getter
	string GetFirstName() { return _FirstName; }
	void SetFirstName(string FirstName) { _FirstName = FirstName; }
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
	//setter and getter:-
	string GetLastName() { return _LastName; };
	void SetLastName(string LastName) { _LastName = LastName; };
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	//setter and getter:-
	string GetEmail() { return _Email; };
	void SetEmail(string Email) { _Email = Email; };
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	//setter and getter:-
	string GetPhone() { return _Phone; };
	void SetPhone(string Phone) { _Phone = Phone; };
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	string FullName() {
		return _FirstName + " " + _LastName;
	}
	void Print() {
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";

	}
};