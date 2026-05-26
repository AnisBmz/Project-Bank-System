#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void showFindClientScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pFindClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\tFind Client Screen");

		cout << "Please enter client account number: ";
		string accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "\nAccount number is not found, choose another one: ";
			accountNumber = clsInputValidate::readString();

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		if (!client.isEmpty())
		{

			cout << "\nClient Found.\n";

		}
		else {

			cout << "\nClient was not Found.\n";

		}

		_PrintClient(client);

	}

};

