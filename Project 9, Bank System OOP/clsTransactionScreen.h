#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"


using namespace std;

class clsTransactionScreen : protected clsScreen
{

private:

	enum _enTransactionsMenuOptions { Deposit = 1, Withdraw = 2, ShowTotalBalances = 3, Transfer = 4, TransfersLog = 5,
        ShowMainMenu = 6 };

    static short _ReadTransactionMenuOption() {

        short choiceNumber = 0;
        cout << clsUtil::tabs_Space(4, 4) << "Choose what do you want to do, [1 to 6]? ";
        choiceNumber = clsInputValidate::readNumberBetween<short>(1, 6, "\nEnter number between 1 and 6: ");
        return choiceNumber;

    }

    static void _GoBackToTransactionMenu() {

        cout << "\nPress any key to go back to Transaction Menu...";
        system("pause>0");
        ShowTransactionsMenu();

    }

    static void _ShowDepositScreen() {

        clsDepositScreen::showDepositScreen();

    }

    static void _ShowWithdrawScreen() {

        clsWithdrawScreen::showWithdrawScreen();

    }

    static void _ShowTotalBalancesScreen() {

        clsTotalBalancesScreen::showTotalBalances();

    }

    static void _ShowTransferScreen() {
    
        clsTransferScreen::showTransferScreen();

    };

    static void _ShowTransfersLogScreen() {

        clsTransfersLogScreen::showTransfersLogScreen();

    }

    static void _PerformTransactionMenuOption(_enTransactionsMenuOptions transactionMenuOption) {

        switch (transactionMenuOption) {

        case _enTransactionsMenuOptions::Deposit:
            system("cls");
            _ShowDepositScreen();
            break;

        case _enTransactionsMenuOptions::Withdraw:
            system("cls");
            _ShowWithdrawScreen();
            break;

        case _enTransactionsMenuOptions::ShowTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            break;

        case _enTransactionsMenuOptions::Transfer:
            system("cls");
            _ShowTransferScreen();
            break;

        case _enTransactionsMenuOptions::TransfersLog:
            system("cls");
            _ShowTransfersLogScreen();
            break;

        }

        if (transactionMenuOption != _enTransactionsMenuOptions::ShowMainMenu)
        {

            _GoBackToTransactionMenu();

        }

    }

public:

    static void ShowTransactionsMenu() {

        if (!checkAccessRights(clsUser::enPermossions::pShowTransactions))
        {
            return;
        }

        system("cls");

        _DrawScreenHeader("\tTransactions Screen");

        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "             Transactions Menu\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [1] Deposit.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [2] Withdraw.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [3] Total Balances.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [4] Transfer.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [5] Transfers Log.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [6] Main Menu.\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        _PerformTransactionMenuOption((_enTransactionsMenuOptions)_ReadTransactionMenuOption());

    }

};

