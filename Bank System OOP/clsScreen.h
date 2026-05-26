#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsDate.h"
#include "Global.h"
#include "clsUser.h"


using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string title, string subTitle = "") {

		cout << "\t\t\t\t---------------------------------------------------\n\n";
		cout << "\t\t\t\t\t   " << title << endl;
		if (!subTitle.empty())
		{
			cout << "\t\t\t\t\t" << subTitle << endl;
		}
		cout << "\n\t\t\t\t---------------------------------------------------\n";
		cout << "\t\t\t\tUser: " << currentUser.userName;
		cout << "\n\t\t\t\tDate: " << clsDate::dateToString(clsDate()) << endl << endl;

	}

	static bool checkAccessRights(clsUser::enPermossions permission) {

		if (!currentUser.checkAccessPermissions(permission))
		{

			cout << "\t\t\t\t---------------------------------------------------\n\n";
			cout << "\t\t\t\t\t   " << "Access Denied! Contact your Admin" << endl;
			cout << "\n\t\t\t\t---------------------------------------------------\n\n";
			return false;


		}
		else {

			return true;

		}


	}

};

