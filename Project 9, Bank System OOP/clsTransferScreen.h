#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static string _ReadAccountNumber() {

		string accountNumber = clsInputValidate::readString();

		while (!clsBankClient::isClientExist(accountNumber)) {

			cout << "\nAccount Number [" << accountNumber << "] not found, Enter another one: ";
			accountNumber = clsInputValidate::readString();

		}
		 
		return accountNumber;

	}

	static double _ReadAmount(double accountBalance) {

		cout << "\nEnter transfer amount: ";
		double amount = clsInputValidate::readNumber<double>();

		while (accountBalance < amount)
		{

			cout << "\nAmount Exceeds available balance, Enter another amount: ";
			amount = clsInputValidate::readNumber<double>();

		}

		return amount;

	}

	static void _PrintClient(clsBankClient client) {

		cout << "\nClient Card:\n";
		cout << "---------------------------------\n";
		cout << "Full name      : " << client.clsPerson::getFullName() << endl;
		cout << "Account number : " << client.accountNumber << endl;
		cout << "Account balance: " << client.accountBalance << endl;
		cout << "---------------------------------\n";

	}

	

public:

	static void showTransferScreen() {

		clsScreen::_DrawScreenHeader("\t   Transfer Screen");
			
		cout << "\nPlease enter account number to transfer from: ";
		string accountNumberTransferFrom = _ReadAccountNumber();
		clsBankClient sourceClient = clsBankClient::find(accountNumberTransferFrom);
		_PrintClient(sourceClient);

		cout << "\nPlease enter account number to transfer to: ";
		string accountNumberTransferTo = _ReadAccountNumber();

		while (accountNumberTransferTo == accountNumberTransferFrom) {

			cout << "\nThe account number entered is the same as the source account, enter a different account number to transfer to: ";
			accountNumberTransferTo = _ReadAccountNumber();

		}

		clsBankClient destinationClient = clsBankClient::find(accountNumberTransferTo);
		_PrintClient(destinationClient);

		double amount = _ReadAmount(sourceClient.accountBalance);

		char answer = 'N';
		cout << "\nAre you sure you want perform this operation, Y/N? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{

			if (sourceClient.transfer(destinationClient, amount, currentUser.userName))
			{
				cout << "\nTransfer done successfully.\n";

			}
			else {

				cout << "\nTransfer Failed.\n";

			}

		}
		else {

			cout << "\nThe transfer process has not been completed.\n";

		}

		_PrintClient(sourceClient);

		_PrintClient(destinationClient);

	}
};

