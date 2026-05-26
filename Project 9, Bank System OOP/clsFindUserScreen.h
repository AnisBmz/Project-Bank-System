#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;



class clsFindUserScreen : protected clsScreen
{

private :

	static string _ReadUserName() {

		cout << "\nPlease enter user name: ";
		string userName = clsInputValidate::readString();

		while (!clsUser::isUserExist(userName)) {

			cout << "\nUser is not found, choose another one: ";
			userName = clsInputValidate::readString();

		}

		return userName;

	}

	static void _PrintUser(clsUser user) {

		cout << "\nClient Card:\n";
		cout << "-------------------------------------\n";
		cout << "First name     : " << user.firstName << endl;
		cout << "Last name      : " << user.lastName << endl;
		cout << "Full name      : " << user.clsPerson::getFullName() << endl;
		cout << "Email          : " << user.email << endl;
		cout << "Phone          : " << user.phone << endl;
		cout << "User name      : " << user.userName << endl;
		cout << "Password       : " << user.password << endl;
		cout << "Permissions    : " << user.permissions << endl;
		cout << "-------------------------------------\n";

	}

public:

	static void showFindUserScreen() {

		clsScreen::_DrawScreenHeader("\t  Find User Screen");

		string userName = _ReadUserName();

		clsUser user = clsUser::find(userName);

		if (!user.isEmpty())
		{

			cout << "\nUser found.\n";

		}
		else {

			cout << "\nUser was not found.\n";

		}

		_PrintUser(user);

	}


};

