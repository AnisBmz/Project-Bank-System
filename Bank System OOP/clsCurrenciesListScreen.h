#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency currency) {

		cout << "\t" << left << "| " << setw(30) << currency.country
			<< "| " << setw(15) << currency.currencyCode
			<< "| " << setw(40) << currency.currencyName
			<< "| " << setw(12) << currency.Rate << "|" << endl;

	}


public:

	static void showCurrenciesListScreen() {

		vector <clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();

		string tile = "    Currencies List Screen";
		string subTitle = ("\t   (" + to_string(vCurrencies.size()) + ") Currency.");
		clsScreen::_DrawScreenHeader(tile, subTitle);

		cout << "\t----------------------------------------------------------------------------------------------------------\n";

		cout << "\t" << left << "| " << setw(30) << "Country"
			<< "| " << setw(15) << "Code"
			<< "| " << setw(40) << "Name"
			<< "| " << setw(12) << "Rate/(1$)" << "|" << endl;

		cout << "\t----------------------------------------------------------------------------------------------------------\n";

		if (vCurrencies.size() != 0)
		{

			for (clsCurrency& currency : vCurrencies) {

				_PrintCurrencyRecordLine(currency);

			}

		}
		else {

			cout << clsUtil::tabs_Space(5) << "No Currencies available in the system!\n";

		}

		cout << "\t----------------------------------------------------------------------------------------------------------\n";



	}


};

