#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUtil.h"
using namespace std;


class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login() {

		bool loginFailed = false;
		short failedLoginCount = 0;

		do
		{

			if (loginFailed)
			{
				failedLoginCount++;
				cout << "\nInvalid UserName/Password!\n";
				cout << "\nYou have " << 3 - failedLoginCount << " trail(s) to login.\n";

			}

			if (failedLoginCount == 3)
			{
				cout << "\nYou are locked after 3 failed trails\n";
				return false;
			}

			string userName = "", password = "";

			cout << "\nEnter User Name: ";
			userName = clsInputValidate::readString();
			cout << "\nEnter password: ";
			password = clsInputValidate::readString();

			currentUser = clsUser::find(userName, password);

			loginFailed = currentUser.isEmpty();

		} while (loginFailed);

		currentUser.registerLogin();
		clsMainScreen::showMainMenu();
		return true;
	}

public:

	static bool showLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		return _Login();
		
	}

};

