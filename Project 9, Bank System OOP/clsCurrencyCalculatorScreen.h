#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

    static float _ReadAmount() {

        cout << "\nEnter Amount to Exchange: ";
        float amount = clsInputValidate::readNumber<float>();
        return amount;

    }

    static void _PrintCurrencyCard(clsCurrency Currency, string message) {

        cout << message << endl;
        cout << "---------------------------\n";
        cout << "Country  : " << Currency.country << endl;
        cout << "Code     : " << Currency.currencyCode << endl;
        cout << "Name     : " << Currency.currencyName << endl;
        cout << "Rate(1$) : " << Currency.Rate << endl;
        cout << "---------------------------\n";

    }

    static clsCurrency _GetCurrency(string message) {

        cout << message;
        string currencyCode = clsInputValidate::readString();

        while (!clsCurrency::isCurrencyExist(currencyCode)) {

            cout << "\ncurrency coder is not found, choose another one: ";
            currencyCode = clsInputValidate::readString();

        }

        return clsCurrency::findByCode(currencyCode);

    }

    static void _PrintCalculationResult(clsCurrency currencyFrom, clsCurrency currencyTo, float amount) {

        if (currencyFrom.currencyCode == currencyTo.currencyCode)
        {

            cout << endl << amount << " " << currencyFrom.currencyCode << " = " << amount << " " << currencyTo.currencyCode << endl;
            return;

        }

        float amountInUSD = currencyFrom.clsCurrency::convertToUSD(amount);

        if (currencyFrom.currencyCode != "USD")
        {
            _PrintCurrencyCard(currencyFrom, "\nCurrency From:");
            cout << amount << " " << currencyFrom.currencyCode << " = " << amountInUSD << " USD\n";
        }

        if (currencyTo.currencyCode == "USD")
        {
            return;
        }

        _PrintCurrencyCard(currencyTo, "\nCurrency From USD To:");

        float amountAfterConvert = currencyFrom.convertToOtherCurrency(amount, currencyTo);

        cout << amount << " " << currencyFrom.currencyCode << " = " << amountAfterConvert << " " << currencyTo.currencyCode << endl;

    }

public:

	static void showCurrencyCalculatorScreen() {

        char Continue = 'n';

        do
        {
            system("cls");

            clsScreen::_DrawScreenHeader("\tCurrency Calculator Screen");

            clsCurrency currencyFrom = _GetCurrency("\nPlease enter first currency code: ");

            clsCurrency currencyTo = _GetCurrency("\nPlease enter second currency code: ");

            float amount = _ReadAmount();

            _PrintCalculationResult(currencyFrom, currencyTo, amount);

            cout << "\nDo you want to perform another calculation? Y/N ";
            cin >> Continue;

        } while (Continue == 'Y' || Continue == 'y');

	}

};

