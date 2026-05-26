#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
using namespace std;

class clsCurrency
{

private:

	enum eMode{EmptyMode = 0, UpdateMode = 1};

	eMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string line, string separator = "#//#") {

		vector <string> vLineData = clsString::split(line, separator);

		return clsCurrency (eMode::UpdateMode, vLineData[0], vLineData[1], vLineData[2], stod(vLineData[3]));

	}

	static vector <clsCurrency> _LoadCurrenciesDataFromFile() {

		vector <clsCurrency> vCurrencies;

		fstream file;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				vCurrencies.push_back(currency);

			}

			file.close();

		}

		return vCurrencies;

	}

	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(eMode::EmptyMode, "", "", "", 0);

	}

	string _ConvertCurrencyObjectToLine(clsCurrency currency, string separator = "#//#") {

		string lineData = "";

		lineData += currency.country + separator;
		lineData += currency.currencyCode + separator;
		lineData += currency.currencyName + separator;
		lineData += to_string(currency.Rate);

		return lineData;
	}

	void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies) {

		fstream file;

		file.open("Currencies.txt", ios::out);

		if (file.is_open())
		{

			for (clsCurrency& currency : vCurrencies) {

				file << _ConvertCurrencyObjectToLine(currency) << endl;

			}

			file.close();

		}

	}

	void _Update() {

		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& currency : vCurrencies) {

			if (clsString::upperAllString(currency.currencyCode) == clsString::upperAllString(currencyCode))
			{

				currency = *this;
				break;

			}

		}

		_SaveCurrenciesDataToFile(vCurrencies);

	}

public:

	clsCurrency(eMode mode, string country, string currencyCode, string currencyName, float Rate) {

		_Mode = mode;
		_Country = country;
		_CurrencyCode = currencyCode;
		_CurrencyName = currencyName;
		_Rate = Rate;

	}

	string getCountry() {

		return _Country;

	}

	__declspec(property(get = getCountry)) string country;

	string getCode() {

		return _CurrencyCode;

	}

	__declspec(property(get = getCode)) string currencyCode;

	string getCurrencyName() {

		return _CurrencyName;

	}

	__declspec(property(get = getCurrencyName)) string currencyName;

	void updateRate(float newRate) {

		_Rate = newRate;
		_Update();

	}

	float getCurrencyRate() {

		return _Rate;

	}

	__declspec(property(get = getCurrencyRate)) float Rate;

	bool isEmpty() {

		return _Mode == eMode::EmptyMode;

	}

	static clsCurrency findByCode(string currencyCode) {

		fstream file;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				clsCurrency currency = _ConvertLineToCurrencyObject(line);

				if (clsString::upperAllString(currency.currencyCode) == clsString::upperAllString(currencyCode))
				{

					file.close();
					return currency;

				}

			}

			file.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency findByCountry(string country) {

		fstream file;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				clsCurrency currency = _ConvertLineToCurrencyObject(line);

				if (clsString::upperAllString(currency.country) == clsString::upperAllString(country))
				{

					file.close();
					return currency;

				}

			}

			file.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool isCurrencyExist(string currencyCode) {

		clsCurrency currency = findByCode(currencyCode);
		return !currency.isEmpty();

	}

	static vector <clsCurrency> getCurrenciesList() {

		return _LoadCurrenciesDataFromFile();

	}

	float convertToUSD(float amount) {

		return amount / Rate;

	}

	float convertToOtherCurrency(float amount, clsCurrency currencyTo) {

		if (currencyTo.currencyCode == "USD")
		{

			return convertToUSD(amount);

		}

		return convertToUSD(amount) * currencyTo.Rate;

	}
};

