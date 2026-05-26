#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private:

	static void _ReadClientInfo(clsBankClient &client) {

		cout << "\nEnter first name: ";
		client.firstName = clsInputValidate::readString();

		cout << "\nEnter last name: ";
		client.lastName = clsInputValidate::readString();

		cout << "\nEnter email: ";
		client.email = clsInputValidate::readString();

		cout << "\nEnter phone: ";
		client.phone = clsInputValidate::readString();

		cout << "\nEnter pin code: ";
		client.pinCode = clsInputValidate::readString();

		cout << "\nEnter account balance: ";
		client.accountBalance = clsInputValidate::readNumber<double>();

	}
	
	static void _PrintClient(clsBankClient client) {

		cout << "\nClient Card:\n";
		cout << "-------------------------------------\n";
		cout << "First name     : " << client.firstName << endl;
		cout << "Full name      : " << client.clsPerson::getFullName() << endl;
		cout << "Email          : " << client.email << endl;
		cout << "Phone          : " << client.phone << endl;
		cout << "Account number : " << client.accountNumber << endl;
		cout << "Pin code       : " << client.pinCode << endl;
		cout << "Account balance: " << client.accountBalance << endl;
		cout << "-------------------------------------\n";

	}

public:

	static void showAddNewClientScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\tAdd New Client Screen");

		string accountNumber = "";
		cout << "Please enter account number: ";
		accountNumber = clsInputValidate::readString();

		while (clsBankClient::isClientExist(accountNumber)) {

			cout << "\nAccount number is already exist, Choose another one: ";
			accountNumber = clsInputValidate::readString();

		}

		clsBankClient newClient = clsBankClient::getNewClientObject(accountNumber);

		cout << "\n-------------------------------\n";
		cout << "New Client Info:\n";
		cout << "-------------------------------";
		_ReadClientInfo(newClient);
		cout << "-------------------------------\n";

		clsBankClient::enSaveResults saveResult = newClient.save();

		switch (saveResult) {

		case clsBankClient::SaveSucceeded:

			cout << "\nAccount added successfully.\n";
			_PrintClient(newClient);
			break;

		case clsBankClient::SaveFailedEmptyObject:

			cout << "\nError ,account was not saved because it's Empty.\n\n";
			break;

		case clsBankClient::SaveFailedAccountNumberExist:

			cout << "\nError ,account was not saved because account number is already exist.\n\n";
			break;

		}

	}

};

