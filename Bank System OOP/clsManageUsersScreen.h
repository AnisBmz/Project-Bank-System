#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{

    enum _enManageUsersMenuOptions { ShowListUser = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, GoToMainMenu = 6 };

    static short _ReadManageUsersMenuOption() {

        short choose = 0;
        cout << clsUtil::tabs_Space(4, 4) << "Choose what do you want to do, [1 to 6]? ";
        choose = clsInputValidate::readNumberBetween<short>(1, 6, "\nEnter number between 1 and 6: ");
        return choose;

    }

    static void _GoBackToManageUsersMenu() {

        cout << "\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        showManageUsersMenu();

    }

    static void _ShowUserListScreen() {

        clsUserListScreen::showClientListScreen();

    }

    static void _ShowAddNewUserScreen() {

        clsAddNewUserScreen::showAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen() {

        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen() {

        clsUpdateUserScreen::showUpdateUserScreen();

    }

    static void _ShowFindUserScreen() {

        clsFindUserScreen::showFindUserScreen();

    }

    static void _PerformManageUsersMenuOption(_enManageUsersMenuOptions manageUsersMenuOption) {

        switch (manageUsersMenuOption) {

        case _enManageUsersMenuOptions::ShowListUser:
            system("cls");
            _ShowUserListScreen();
            break;

        case _enManageUsersMenuOptions::AddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            break;

        case _enManageUsersMenuOptions::DeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            break;

        case _enManageUsersMenuOptions::UpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            break;

        case _enManageUsersMenuOptions::FindUser:
            system("cls");
            _ShowFindUserScreen();
            break;

        }

        if (manageUsersMenuOption != _enManageUsersMenuOptions::GoToMainMenu)
        {

            _GoBackToManageUsersMenu();

        }

    }

public:

	static void showManageUsersMenu() {

        if (!checkAccessRights(clsUser::enPermossions::pManageUsers))
        {
            return;
        }

        system("cls");

		_DrawScreenHeader("\tManage Users Screen");

        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "             Manage Users Menu\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [1] List Users.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [2] Add New User.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [3] Delete User.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [4] Update User.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [5] Find User.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [6] Main Menu.\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        _PerformManageUsersMenuOption((_enManageUsersMenuOptions)_ReadManageUsersMenuOption());


	}

};

