#pragma once

#include <iostream>
#include "clsScreen.h"
#include "string"
#include "clsBankClient.h"
using namespace std;

class clsTransfersLogScreen : protected clsScreen
{

private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord& transferLog) {

		cout << "    " << left << "| " << setw(22) << transferLog.dateTime
			<< "| " << setw(10) << transferLog.sourceAccountNumber
			<< "| " << setw(10) << transferLog.destinationAccountNumber
			<< "| " << setw(10) << transferLog.amount
			<< "| " << setw(15) << transferLog.srcBalanceAfter
			<< "| " << setw(15) << transferLog.destBalanceAfter
			<< "| " << setw(10) << transferLog.userName << "|" << endl;

	}


public:

	static void showTransfersLogScreen() {

		vector <clsBankClient::stTransferLogRecord> vTransfersLog = clsBankClient::getTransfersLofList();

		string title = "  Transfer Log List Screen";
		string subTitle = "\t  (" + to_string(vTransfersLog.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(title, subTitle);

		cout << "    -----------------------------------------------------------------------------------------------------------\n";

		cout << "    " << left << "| " << setw(22) << "Date/Time"
			<< "| " << setw(10) << "s.Account"
			<< "| " << setw(10) << "d.Account"
			<< "| " << setw(10) << "Amount"
			<< "| " << setw(15) << "s.Balance"
			<< "| " << setw(15) << "d.Balance"
			<< "| " << setw(10) << "UserName" << "|" << endl;

		cout << "    -----------------------------------------------------------------------------------------------------------\n";

		if (vTransfersLog.size() != 0)
		{

			for (clsBankClient::stTransferLogRecord& transferLog : vTransfersLog) {

				_PrintTransferLogRecordLine(transferLog);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No Transfers available in the system!\n";

		}

		cout << "    -----------------------------------------------------------------------------------------------------------\n";

	}


};

