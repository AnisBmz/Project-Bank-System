#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;


class clsUserListScreen : protected clsScreen
{

private:
	
	static void _PrintUserRecordLine(clsUser user) {

		cout << "\t" << left << "| " << setw(15) << user.userName
			<< "| " << setw(23) << user.getFullName()
			<< "| " << setw(15) << user.phone
			<< "| " << setw(20) << user.email
			<< "| " << setw(10) << user.password
			<< "| " << setw(12) << user.permissions << "|" << endl;

	}

public:

	static void showClientListScreen() {

		vector <clsUser> vUsersData = clsUser::getUserList();

		string title = "\t  User List Screen";
		string subTitle = "\t    (" + to_string(vUsersData.size()) + ") user(s).";

		clsScreen::_DrawScreenHeader(title, subTitle);

		cout << "\t------------------------------------------------------------------------------------------------------------\n";

		cout << "\t" << left << "| " << setw(15) << "User name"
			<< "| " << setw(23) << "Full Name"
			<< "| " << setw(15) << "Phone"
			<< "| " << setw(20) << "Email"
			<< "| " << setw(10) << "Password"
			<< "| " << setw(12) << "Permissions" << "|" << endl;

		cout << "\t------------------------------------------------------------------------------------------------------------\n";

		if (vUsersData.size() != 0)
		{

			for (clsUser& user : vUsersData) {

				_PrintUserRecordLine(user);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No users available in the system!\n";

		}

		cout << "\t------------------------------------------------------------------------------------------------------------\n";

	}

};

