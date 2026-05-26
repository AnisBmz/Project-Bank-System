#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;


class clsWithdrawScreen : protected clsScreen
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

	static string _ReadAccountNumber() {

		string accountNumber = "";
		cout << "Please enter account number: ";
		accountNumber = clsInputValidate::readString();
		return accountNumber;

	}

public:

	static void showWithdrawScreen() {

		_DrawScreenHeader("\t   Withdraw Screen");

		string accountNumber = _ReadAccountNumber();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "\nClient with [" << accountNumber << "] is not exist.\n\n";
			accountNumber = _ReadAccountNumber();

		}

		clsBankClient client = clsBankClient::find(accountNumber);
		_PrintClient(client);

		double amount = 0;
		cout << "\nPlease enter withdraw amount: ";
		amount = clsInputValidate::readPositiveNumber<double>();

		char answer = 'N';
		cout << "\nAre you sure you want to perform this transaction, Y/N? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (client.withdraw(amount))
			{

				cout << "\nAmount Withdraw successfully.\n\n";
				cout << "New Balance is: " << client.accountBalance << endl;

			}
			else {

				cout << "\nCannot withdrawn, Insuffecient Balance!.\n";
				cout << "\nAmount to withdrawn is: " << amount;
				cout << "\n\nYour Balance is: " << client.accountBalance << endl;

			}
		}

		else {

			cout << "\nOperation was cancelled.\n";

		}

	}

};

