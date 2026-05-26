#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{

private:

	static void _PrintClientRecordLine(clsBankClient& client) {

		cout << "\t" << left << "| " << setw(15) << client.accountNumber
			<< "| " << setw(23) << client.getFullName()
			<< "| " << setw(13) << client.phone
			<< "| " << setw(23) << client.email
			<< "| " << setw(10) << client.pinCode
			<< "| " << setw(8) <<  client.accountBalance << "|" << endl;

	}

public:

	static void showClientListScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pShowClientsList))
		{
			return;
		}

		vector <clsBankClient> vClientsData = clsBankClient::getClientsList();

		string title = "\t     Client List";
		string subTitle = "\t   (" + to_string(vClientsData.size()) + ") client(s).";

		clsScreen::_DrawScreenHeader(title, subTitle);

		cout << "\t---------------------------------------------------------------------------------------------------------\n";

		cout << "\t" << left << "| " << setw(15) << "Account Number"
			<< "| " << setw(23) << "Client Name"
			<< "| " << setw(13) << "Phone"
			<< "| " << setw(23) << "Email"
			<< "| " << setw(10) << "Pin code"
			<< "| " << setw(8) << "Balance"  << "|" << endl;

		cout << "\t---------------------------------------------------------------------------------------------------------\n";

		if (vClientsData.size() != 0)
		{

			for (clsBankClient& client : vClientsData) {

				_PrintClientRecordLine(client);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No clients available in the system!\n";

		}

		cout << "\t---------------------------------------------------------------------------------------------------------\n";

	}


};

