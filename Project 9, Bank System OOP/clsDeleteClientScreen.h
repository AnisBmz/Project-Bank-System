#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

private:

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

	static void showDeleteClientScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pDeleteClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\tDelete Client Screen");

		cout << "Please enter client account number: ";
		string accentNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accentNumber)) {

			cout << "\nAccount number is not found, choose another one: ";
			accentNumber = clsInputValidate::readString();

		}

		clsBankClient clientForDelete = clsBankClient::find(accentNumber);

		_PrintClient(clientForDelete);

		char answer = 'Y';
		cout << "\nAre you sure you want delete this client, Y/N? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{

			if (clientForDelete.isDelete())
			{

				cout << "\nClient deleted successfully.\n";
				_PrintClient(clientForDelete);

			}
			else {

				cout << "\nError client was not deleted.\n\n";

			}

		}
		else {

			cout << "\nThe deletion process was not completed.\n";

		}

	}

};

