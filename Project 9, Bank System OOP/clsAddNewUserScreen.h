#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static void _ReadPermissions(clsUser& newUser){
	
		char answer = 'N';
		cout << "\n\nDo you want to give full access, Y/N? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			newUser.addPermissions(clsUser::enPermossions::pAll);
		}
		else {

			cout << "\nDo you want to give access to:\n";

			cout << "\nShow Client List, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pShowClientsList);

			cout << "\nAdd New Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pAddNewClient);

			cout << "\nDelete Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pDeleteClient);

			cout << "\nUpdate Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pUpdateClientInfo);

			cout << "\nFind Client, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pFindClient);

			cout << "\nTransaction, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pShowTransactions);

			cout << "\nManage Users, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pManageUsers);

			cout << "\nShow Login Register, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pShowLoginRegister);

			cout << "\nCurrency Exchange, Y/N? ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
				newUser.addPermissions(clsUser::enPermossions::pCurrencyExchange);

		}
	
	}

	static void _ReadUserInfo(clsUser& newUser) {

		cout << "\nEnter first name: ";
		newUser.firstName = clsInputValidate::readString();

		cout << "\nEnter last name: ";
		newUser.lastName = clsInputValidate::readString();

		cout << "\nEnter phone: ";
		newUser.phone = clsInputValidate::readString();

		cout << "\nEnter email: ";
		newUser.email = clsInputValidate::readString();

		cout << "\nEnter Password: ";
		newUser.password = clsInputValidate::readString();

		cout << "\nEnter Permissions: ";
		_ReadPermissions(newUser);

	}

	static string _ReadUserName() {

		cout << "\nPlease enter user name: ";
		string userName = clsInputValidate::readString();

		while (clsUser::isUserExist(userName)) {

			cout << "\nUser name is already exist, Choose another one: ";
			userName = clsInputValidate::readString();

		}

		return userName;

	}

	static void _PrintUser(clsUser newUser) {

		cout << "\nClient Card:\n";
		cout << "-------------------------------------\n";
		cout << "First name     : " << newUser.firstName << endl;
		cout << "Last name      : " << newUser.lastName << endl;
		cout << "Full name      : " << newUser.clsPerson::getFullName() << endl;
		cout << "Email          : " << newUser.email << endl;
		cout << "Phone          : " << newUser.phone << endl;
		cout << "User name      : " << newUser.userName << endl;
		cout << "Password       : " << newUser.password << endl;
		cout << "Permissions    : " << newUser.permissions << endl;
		cout << "-------------------------------------\n";

	}

public:

	static void showAddNewUserScreen() {

		clsScreen::_DrawScreenHeader("\tAdd New User Screen");

		string userName = _ReadUserName();

		clsUser newUser = clsUser::getAddNewUserObject(userName);

		cout << "\n-------------------------------\n";
		cout << "New User Info:\n";
		cout << "-------------------------------";
		_ReadUserInfo(newUser);
		cout << "-------------------------------\n";

		clsUser::enSaveResults saveResult = newUser.save();

		switch (saveResult)
		{
		case clsUser::enSaveResults::SaveSucceeded:

			cout << "\nUser added successfully.\n";
			_PrintUser(newUser);
			break;

		case clsUser::enSaveResults::SaveFailedEmptyObject:

			cout << "\nError ,User was not saved because it's Empty.\n\n";
			break;

		case clsUser::enSaveResults::SaveFailedUserNameExist:

			cout << "\nError ,User was not saved because user name is already exist.\n\n";
			break;
		}

	}

};

