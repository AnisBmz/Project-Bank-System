#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrenciesScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{

private:

    enum eCurrenciesExchangeMainMenuOptions { ListCurrencies = 1,  FindCurrency = 2, UpdateRate = 3,
                                          CurrencyCalculator = 4, GoToMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenuOption() {

        short choose = 0;
        cout << clsUtil::tabs_Space(4) << "Choose what do you want to do, [1 to 5]? ";
        choose = clsInputValidate::readNumberBetween<short>(1, 5, "\nEnter number between 1 and 5: ");
        return choose;

    }

    static void _GoBackToCurrencyExchangeMenu() {

        cout << "\nPress any key to go back to Currency Exchange Menu...";
        system("pause>0");
        showCurrencyExchangeScreen();

    }

    static void _ShowCurrenciesListScreen() {

        clsCurrenciesListScreen::showCurrenciesListScreen();

    }

    static void _ShowFindCurrencyScreen() {

        clsFindCurrenciesScreen::showFindCurrencyScreen();

    }

    static void _ShowUpdateCurrencyRateScreen() {

        clsUpdateCurrencyRateScreen::showUpdateCurrencyRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen() {

        clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();

    }

    static void _PerformCurrencyExchangeMainMenuOption(eCurrenciesExchangeMainMenuOptions currencyExchangeMenuOption) {

        switch (currencyExchangeMenuOption) {

        case eCurrenciesExchangeMainMenuOptions::ListCurrencies:
            system("cls");
            _ShowCurrenciesListScreen();
            break;

        case eCurrenciesExchangeMainMenuOptions::FindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            break;

        case eCurrenciesExchangeMainMenuOptions::UpdateRate:
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            break;

        case eCurrenciesExchangeMainMenuOptions::CurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            break;

        }

        if (currencyExchangeMenuOption != eCurrenciesExchangeMainMenuOptions::GoToMainMenu)
        {
            _GoBackToCurrencyExchangeMenu();
        }

    }

public:

	static void showCurrencyExchangeScreen() {

        system("cls");

        if (!clsScreen::checkAccessRights(clsUser::enPermossions::pCurrencyExchange)) {

            return;

        }

		clsScreen::_DrawScreenHeader("Currency Exchange Main Screen");

        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "           Currency Exchange Menu\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [1] List Currencies.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [2] Find Currency.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [3] Update Rate.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [4] Currency Calculator.\n";
        cout << clsUtil::tabs_Space(4, 4) << "      [5] Main Menu.\n";
        cout << clsUtil::tabs_Space(4, 4) << "===========================================\n";
        _PerformCurrencyExchangeMainMenuOption((eCurrenciesExchangeMainMenuOptions)_ReadCurrencyExchangeMenuOption());
	}

};

