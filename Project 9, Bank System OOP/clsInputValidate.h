#pragma once

#include <iostream>
#include <limits>
#include "clsDate.h"
#include "clsPeriod.h"
#include "clsUtil.h"

using namespace std;

class clsInputValidate
{

public:


	template <typename T> static bool isNumberBetween(T number, T from, T to) {

		return number >= from && number <= to;

	}

	template <typename T> static T readNumber(string errorMessage = "Invalid number, Enter again:\n") {

		T number = 0;

		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');

			cout << errorMessage;
			cin >> number;

		}

		return number;

	}

	template <typename T> static T readPositiveNumber(string errorMessage = "\nInvalid number, Enter positive number: ") {

		T number = 0;

		cin >> number;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');

			cout << errorMessage;
			cin >> number;

		}

		while (number < 0) {

			cout << errorMessage;
			cin >> number;

		}

		return number;

	}

	template <typename T> static T readNumberBetween(T from, T to, string message = "Number is not within range, Enter again:\n") {

		T number = readNumber<T>();

		while (!isNumberBetween(number, from, to))
		{
			cout << message;
			number = readNumber<T>();
		}

		return number;
	}

	static bool isDateBetween(clsDate date, clsDate startDate, clsDate endDate) {

		if (clsDate::isDate1AfterDate2(startDate, endDate))
		{

			clsUtil::swap(startDate, endDate);

		}

		return clsPeriod::isDateInPeriod(clsPeriod(startDate, endDate), date);


	}

	static bool isValidDate(clsDate date) {

		return clsDate::isValidDate(date);

	}

	static string readString() {

		string S1 = "";
		getline(cin >> ws, S1);
		return S1;

	}

};