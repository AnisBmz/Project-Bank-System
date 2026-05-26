#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void _PrintRegisteredRecordLine(clsUser::stLoginRegisterRecord& loginRegisterRecord) {

		cout << "\t   " << left << "| " << setw(30) << loginRegisterRecord.dateTime
			<< "| " << setw(20) << loginRegisterRecord.userName
			<< "| " << setw(20) << loginRegisterRecord.password
			<< "| " << setw(15) << to_string(loginRegisterRecord.permissions) << "|" << endl;

	}


public:

	static void showLoginRegisterScreen() {

		if (!checkAccessRights(clsUser::enPermossions::pShowLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vRegisteredUsersData = clsUser::getLoginRegisterList();

		string title = "  Login Register List Screen";
		string subTitle = "\t  (" + to_string(vRegisteredUsersData.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(title, subTitle);

		cout << "\t   ----------------------------------------------------------------------------------------------\n";

		cout << "\t   " << left << "| " << setw(30) << "Date/Time"
			<< "| " << setw(20) << "UserName"
			<< "| " << setw(20) << "Password"
			<< "| " << setw(15) << "Permissions" << "|" << endl;

		cout << "\t   ----------------------------------------------------------------------------------------------\n";

		if (vRegisteredUsersData.size() != 0)
		{

			for (clsUser::stLoginRegisterRecord& loginRegisterRecord : vRegisteredUsersData) {

				_PrintRegisteredRecordLine(loginRegisterRecord);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No Logins available in the system!\n";

		}

		cout << "\t   ----------------------------------------------------------------------------------------------\n";

	}

};

