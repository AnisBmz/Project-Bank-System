#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _ReadPermissions(clsUser& user) {

		char answer = 'N';
		cout << "\n\nDo you want to give full access, Y/N? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			user.addPermissions(clsUser::enPermossions::pAll);
		}
		else {

			cout << "\nDo you want to give access to:\n";

			cout << "\nShow Client List, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pShowClientsList);

			cout << "\nAdd New Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pAddNewClient);

			cout << "\nDelete Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pDeleteClient);

			cout << "\nUpdate Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pUpdateClientInfo);

			cout << "\nFind Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pFindClient);

			cout << "\nTransaction, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pShowTransactions);

			cout << "\nManage Users, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pManageUsers);

			cout << "\nShow Login Register, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pShowLoginRegister);

			cout << "\nCurrency Exchange, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				user.addPermissions(clsUser::enPermossions::pCurrencyExchange);

		}

	}

	static void _ReadUserInfo(clsUser& user) {

		cout << "\nEnter first name: ";
		user.firstName = clsInputValidate::readString();

		cout << "\nEnter last name: ";
		user.lastName = clsInputValidate::readString();

		cout << "\nEnter phone: ";
		user.phone = clsInputValidate::readString();

		cout << "\nEnter email: ";
		user.email = clsInputValidate::readString();

		cout << "\nEnter Password: ";
		user.password = clsInputValidate::readString();

		cout << "\nEnter Permissions: ";
		_ReadPermissions(user);

	}

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

	static void showUpdateUserScreen() {

		clsScreen::_DrawScreenHeader("\tUpdate User Screen");

		string userName = _ReadUserName();

		clsUser user = clsUser::find(userName);
		_PrintUser(user);

		char answer = 'N';
		cout << "\nAre you sure you want updated this user, Y/N? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{

			cout << "\n-------------------------------\n";
			cout << "Update User Info:\n";
			cout << "-------------------------------";
			_ReadUserInfo(user);
			cout << "-------------------------------\n";

			clsUser::enSaveResults saveResult = user.save();

			switch (saveResult) {

			case  clsUser::enSaveResults::SaveSucceeded:

				cout << "\nUpdate User successfully\n";
				_PrintUser(user);
				break;

			case clsUser::enSaveResults::SaveFailedEmptyObject:

				cout << "\nError ,User was not saved because it's Empty.\n\n";
				break;
			}

		}
		else {

			cout << "\nThe update process has not been completed.\n";


		}


	}


};

