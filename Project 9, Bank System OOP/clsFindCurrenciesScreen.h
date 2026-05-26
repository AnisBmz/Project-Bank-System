#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrenciesScreen : protected clsScreen
{

private:


    static void _ShowResults(clsCurrency currency) {

        if (!currency.isEmpty())
        {

            cout << "\nCurrency found.\n";
            _PrintCurrency(currency);

        }
        else {

            cout << "\nCurrency was not found.\n";

        }

    }

    static void _PrintCurrency(clsCurrency Currency) {

        cout << "\nCurrency Card:\n";
        cout << "------------------------------\n";
        cout << "Country  : " << Currency.country << endl;
        cout << "Code     : " << Currency.currencyCode << endl;
        cout << "Name     : " << Currency.currencyName << endl;
        cout << "Rate(1$) : " << Currency.Rate << endl;
        cout << "------------------------------\n";

    }

public:

    static void showFindCurrencyScreen() {

        clsScreen::_DrawScreenHeader("\tFind Currency Screen");


        cout << "\nFind by: [1] code or [2] country: ";
        short answer = clsInputValidate::readNumberBetween<short>(1, 2, "\nFind by: [1] code or [2] country: ");

        if (answer == 1)
        {

            cout << "\nPlease enter currency code: ";
            string countryCode = clsInputValidate::readString();
            clsCurrency Currency = clsCurrency::findByCode(countryCode);
            _ShowResults(Currency);

        }
        else {

            cout << "\nPlease enter country name: ";
            string countryName = clsInputValidate::readString();
            clsCurrency Currency = clsCurrency::findByCountry(countryName);
            _ShowResults(Currency);

        }

    }

};

