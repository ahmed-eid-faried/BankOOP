#pragma once
#include <string>
 using namespace std;

const string Seperator = "#//#";
const string ClientPathFile = "clients.txt";
const string UsersPathFile = "users.txt";
const string LogFilePathFile = "LogFile.txt";
 //  ⁄—Ì› enum ··√–Ê‰« 
const enum enPermissions {
	PERMISSION_ListUsers = 1 << 0, // 0000001 -> 1
	PERMISSION_Add = 1 << 1, // 0000010 -> 2
	PERMISSION_Delete = 1 << 2, // 0000100 -> 4
	PERMISSION_Update = 1 << 3, // 0001000 -> 8
	PERMISSION_Find = 1 << 4, // 0010000 -> 16
	PERMISSION_Transactions = 1 << 5, // 0100000 -> 32
	PERMISSION_MangeUsers = 1 << 6, // 1000000 -> 64
	PERMISSION_LogFile = 1 << 7, // 1000000 -> 128
	PERMISSION_AllPermissions = (1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7), // 1111111 -> 127
};

struct sPermissions {
	enPermissions ListUsers;
	enPermissions Add;
	enPermissions Delete;
	enPermissions Update;
	enPermissions FIND;
	enPermissions Transactions;
	enPermissions MangeUsers;
	enPermissions LogFile;
};

