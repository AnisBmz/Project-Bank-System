#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:
    
    static float _ReadRate() {

        cout << "Enter new Rate: ";
        float newRate = clsInputValidate::readNumber<float>();
        return newRate;

    }

    static string _ReadCurrencyCode() {

        cout << "\nPlease enter currency code: ";
        string currencyCode = clsInputValidate::readString();

        while (!clsCurrency::isCurrencyExist(currencyCode)) {

            cout << "\ncurrency coder is not found, choose another one: ";
            currencyCode = clsInputValidate::readString();

        }

        return currencyCode;
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

    void static showUpdateCurrencyRateScreen() {

        clsScreen::_DrawScreenHeader("\tUpdate Currency Screen");

        string currencyCode = _ReadCurrencyCode();

        clsCurrency currency = clsCurrency::findByCode(currencyCode);

        _PrintCurrency(currency);

        char answer = 'N';
        cout << "\nAre you sure you want update the rate of this currency, Y/N? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            cout << "\nUpdate Currency Rate: ";
            cout << "\n------------------------------\n";

            currency.updateRate(_ReadRate());

            cout << "\nCurrency Rate updated Successfully.\n";

            _PrintCurrency(currency);

        }
        else {

            cout << "\nThe update process has not been completed.\n";

        }

    }

};

