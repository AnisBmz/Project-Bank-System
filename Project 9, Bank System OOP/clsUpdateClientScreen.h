#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

private :

	static void _ReadClientInfo(clsBankClient& client) {

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

	static void showUpdateClientScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pUpdateClientInfo))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\tUpdate Client Screen");

		cout << "Please enter client account number: ";
		string accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "\nAccount number is not found, choose another one: ";
			accountNumber = clsInputValidate::readString();

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_PrintClient(client);

		char answer = 'N';
		cout << "\nAre you sure you want update this client, Y/N? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{

			cout << "\n-------------------------------\n";
			cout << "Update Client Info:\n";
			cout << "-------------------------------";
			_ReadClientInfo(client);
			cout << "-------------------------------\n";


			clsBankClient::enSaveResults saveResult = client.save();

			switch (saveResult) {

			case clsBankClient::SaveSucceeded:

				cout << "\nAccount update successfully.\n";
				_PrintClient(client);
				break;

			case clsBankClient::SaveFailedEmptyObject:

				cout << "\nError ,account was not saved because it's Empty.\n\n";
				break;

			}

		}

	}

};

