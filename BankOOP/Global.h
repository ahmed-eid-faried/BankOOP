#pragma once
#include <string>
#include "clsUser.h"
using namespace std;

const string Seperator = "#//#";
const string ClientPathFile = "clients.txt";
const string UsersPathFile = "users.txt";
clsUser CurrentUser = clsUser::Find("", "");
