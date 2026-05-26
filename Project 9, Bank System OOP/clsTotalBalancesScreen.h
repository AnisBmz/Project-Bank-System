#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private:

	static void _PrintClientRecordBalanceLine(clsBankClient& client) {

		cout << "\t\t" << left << "| " << setw(20) << client.accountNumber
			<< "| " << setw(35) << client.getFullName()
			<< "| " << setw(20) << client.accountBalance  << "|" << endl;

	}

public:

	static void showTotalBalances() {

		vector <clsBankClient> vClientsData = clsBankClient::getClientsList();

		string title = "\tBalances list Screen";
		string subTitle = "\t   (" + to_string(vClientsData.size()) + ") client(s).";

		clsScreen::_DrawScreenHeader(title, subTitle);

		cout << "\t\t----------------------------------------------------------------------------------\n";
		cout << "\t\t" << left << "| " << setw(20) << "Account Number" << "| " << setw(35) << "Client Name" << "| " << setw(20) << "Balance" << "|" << endl;
		cout << "\t\t----------------------------------------------------------------------------------\n";

		if (vClientsData.size() != 0)
		{

			for (clsBankClient& client : vClientsData) {

				_PrintClientRecordBalanceLine(client);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No clients available in the system!\n";

		}
		cout << "\t\t----------------------------------------------------------------------------------\n";


		double totalBalances = clsBankClient::getTotalBalances();

		cout << "\n" << clsUtil::tabs_Space(6) << "Total balances = " << totalBalances << endl;
		if (vClientsData.size() != 0)
		{

			cout << clsUtil::tabs_Space(6) << "( " << clsUtil::numberToText(totalBalances) << " )" << endl;

		}


	}

};

