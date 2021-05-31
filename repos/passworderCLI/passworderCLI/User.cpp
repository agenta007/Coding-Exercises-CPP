#include "User.h"
#include <iostream>
#include "is_user_registered_func.h"
using namespace std;

int User::changePassWithParam(string pass)
{
	masterpass = pass;
	return 0;
}
bool login() 
{
	string input;
	cout << "Enter username to login in: ";
	try
	{
		cin >> input;
		if (!is_user_registered(input))
		{
			cerr << "Error 404: User not found.\n";
			throw 1;
		}


	}
	catch (int)
	{
		string input;
		cout << "Enter retry and enter correct username or enter cancel: ";
		if (input=="cancel")
		{
			return 0;
		}
		else if(input=="retry")
		{
			login();
			return 1;
		}
		else
		{
			cerr << "Invalid command.\n";
			throw 1;
		}
	}
}
bool User::logon()
{
	logged_on = true;
	return 1;
}
bool User::logout()
{
	logged_on = false;
}
string User::getUsername()const
{
	return username;
}
string User::getPass()const
{
	return masterpass;
}
bool User::changePass()
{
	string pass, check, username;
	cout << "Enter username: ";
	cin >> username;
	User* pToUser = findUser(username);
}
