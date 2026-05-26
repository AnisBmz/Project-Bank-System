#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

    enum _enMainMenuOptions { ShowClientsList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClientInfo = 4, 
     FindClient = 5, ShowTransactions = 6, ManageUsers = 7, LoginRegister = 8, CurrencyExchange = 9, Exit = 10 };

    static short _ReadMianMenuOption() {

        short mainMenuOption = 0;
        cout << clsUtil::tabs_Space(4) << "Choose what do you want to do, [1 to 10]? ";
        mainMenuOption = clsInputValidate::readNumberBetween<short>(1, 10, "\nEnter number between 1 and 10: ");
        return mainMenuOption;

    }

    static void _GoBackToMainMenu() {

        cout << "\nPress any key to go back to Main Menu...";
        system("pause>0");
        showMainMenu();

    }

    static void _ShowAllClientsScreen() {


        clsClientListScreen::showClientListScreen();

    }

    static void _ShowAddNewClientsScreen() {

        clsAddNewClientScreen::showAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen() {

        clsDeleteClientScreen::showDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen() {

        clsUpdateClientScreen::showUpdateClientScreen();

    }

    static void _ShowFindClientScreen() {

        clsFindClientScreen::showFindClientScreen();

    }

    static void _ShowTransactionMenu() {

        clsTransactionScreen::ShowTransactionsMenu();

    }

    static void _ShowManageUsersMenu() {

        clsManageUsersScreen::showManageUsersMenu();

    }

    static void _ShowLoginRegisterScreen() {

        clsLoginRegisterScreen::showLoginRegisterScreen();

    }

    static void _ShowCurrencyExchangeMainScreen() {

        clsCurrencyExchangeScreen::showCurrencyExchangeScreen();

    }

    static void _Logout() {
        
        currentUser = clsUser::find("", "");

    }

    static void _PerformMainMenuOption(_enMainMenuOptions mainMenuOption) {

        switch (mainMenuOption) {

        case _enMainMenuOptions::ShowClientsList:

            system("cls");
            _ShowAllClientsScreen();
            break;

        case _enMainMenuOptions::AddNewClient:

            system("cls");
            _ShowAddNewClientsScreen();
            break;

        case _enMainMenuOptions::DeleteClient:

            system("cls");
            _ShowDeleteClientScreen();
            break;

        case _enMainMenuOptions::UpdateClientInfo:

            system("cls");
            _ShowUpdateClientScreen();
            break;

        case _enMainMenuOptions::FindClient:

            system("cls");
            _ShowFindClientScreen();
            break;

        case _enMainMenuOptions::ShowTransactions:

            system("cls");
            _ShowTransactionMenu();
            break;

        case _enMainMenuOptions::ManageUsers:

            system("cls");
            _ShowManageUsersMenu();
            break;

        case _enMainMenuOptions::LoginRegister:

            system("cls");
            _ShowLoginRegisterScreen();
            break;

        case _enMainMenuOptions::CurrencyExchange:

            system("cls");
            _ShowCurrencyExchangeMainScreen();
            break;

        case _enMainMenuOptions::Exit:

            system("cls");
            _Logout();
            break;

        }

        if (mainMenuOption != _enMainMenuOptions::Exit) {

            _GoBackToMainMenu();

        }

    }

public:

	static void showMainMenu() {

        system("cls");

		_DrawScreenHeader("\t     Main Screen");

        cout << clsUtil::tabs_Space(4) << "===================================================\n";
        cout << clsUtil::tabs_Space(6, 2) << "Main Menu Screen\n";
        cout << clsUtil::tabs_Space(4) << "===================================================\n";
        cout << clsUtil::tabs_Space(5) << "[1] Show Clients List.\n";
        cout << clsUtil::tabs_Space(5) << "[2] Add New Client.\n";
        cout << clsUtil::tabs_Space(5) << "[3] Delete Client.\n";
        cout << clsUtil::tabs_Space(5) << "[4] Update Client Info.\n";
        cout << clsUtil::tabs_Space(5) << "[5] Find Client.\n";
        cout << clsUtil::tabs_Space(5) << "[6] Transaction.\n";
        cout << clsUtil::tabs_Space(5) << "[7] Manage Users.\n";
        cout << clsUtil::tabs_Space(5) << "[8] Login Register.\n";
        cout << clsUtil::tabs_Space(5) << "[9] Currency Exchange.\n";
        cout << clsUtil::tabs_Space(5) << "[10] Logout.\n";
        cout << clsUtil::tabs_Space(4) << "===================================================\n";

        _PerformMainMenuOption((_enMainMenuOptions)_ReadMianMenuOption());
	}

};

