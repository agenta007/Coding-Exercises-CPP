#ifndef USER_H
#define USER_H
using namespace std;
#include <string>
class User
{
	string username;
	string masterpass;
	bool logged_on;
public:
	bool login();
	bool logon();
	bool logout();
	string getUsername()const;
	string getPass()const;
	int changePassWithParam(string);
	bool changePass();
};
#endif