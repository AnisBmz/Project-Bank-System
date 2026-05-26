#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{

private:

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

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\tDelete User Screen");

		string userName = _ReadUserName();

		clsUser user = clsUser::find(userName);

		_PrintUser(user);

		char answer = 'N';

		cout << "\nAre you sure you want delete this user, Y/N? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{

			if (user.isDelete())
			{
				cout << "\nUser Deleted successfully.\n";
				_PrintUser(user);
			}
			else {

				cout << "\nError user was not deleted.\n\n";

			}

		}
		else {

			cout << "\nThe deletion process was not completed.\n";

		}



	}

};

