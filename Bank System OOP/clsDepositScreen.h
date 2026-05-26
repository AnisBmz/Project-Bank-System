#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDepositScreen : protected clsScreen
{

private:

	static string _ReadAccountNumber() {

		string accountNumber = "";
		cout << "Please enter account number: ";
		accountNumber = clsInputValidate::readString();
		return accountNumber;

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

	static void showDepositScreen() {

		_DrawScreenHeader("\t   Deposit Screen");

		string accountNumber = _ReadAccountNumber();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "\nClient with [" << accountNumber << "] is not exist.\n\n";
			accountNumber = _ReadAccountNumber();

		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_PrintClient(client);

		cout << "\nPlease enter deposit amount: ";
		double amount = clsInputValidate::readNumber<double>();

		char answer = 'N';
		cout << "\nAre you sure you want to perform this transaction, Y/N? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			client.deposit(amount);
			cout << "\nAmount Deposited successfully.\n\n";
			cout << "New Balance is: " << client.accountBalance << endl;

		}
		else {

			cout << "\nOperation was cancelled.\n";

		}

	}

};

