#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include "clsString.h"
using namespace std;

class clsDate
{

private:

	short _Day;
	short _Month;
	short _Year;


public:

	clsDate() {

		time_t now = time(0);
		tm* local = localtime(&now);
		_Day = local->tm_mday;
		_Month = local->tm_mon + 1;
		_Year = local->tm_year + 1900;

	}

	clsDate(string date) {

		vector <string> vDate = clsString::split(date, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short day, short month, short year) {

		_Day = day;
		_Month = month;
		_Year = year;

	}

	clsDate(short dateOrderInYear, short year) {

		clsDate date = getDateFromDayOrderInYear(dateOrderInYear, year);

		_Day = date.day;
		_Month = date.month;
		_Year = date.year;

	}

	void setDay(short day) {

		_Day = day;

	}

	short getDay() {

		return _Day;

	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month) {

		_Month = month;

	}

	short getMonth() {

		return _Month;

	}

	__declspec(property(get = getMonth, put = setMonth)) short month;

	void setYear(short year) {

		_Year = year;

	}

	short getYear() {

		return _Year;

	}

	__declspec(property(get = getYear, put = setYear)) short year;

	void print() {

		cout << dateToString() << endl;

	}

	static clsDate getSystemDate() {

		clsDate date;

		time_t now = time(0);
		tm* local = localtime(&now);

		date.day = local->tm_mday;
		date.month = local->tm_mon + 1;
		date.year = local->tm_year + 1900;
		return date;

	}

	static string getSystemDateTimeString() {

		time_t now = time(0);
		tm* local = localtime(&now);

		return to_string(local->tm_mday) + "/" + to_string(local->tm_mon + 1) + "/" + to_string(local->tm_year + 1900) +
			+ " - " + to_string(local->tm_hour) + ":" + to_string(local->tm_min) + ":" + to_string(local->tm_sec);

	}

	static bool isValidDate(clsDate date) {

		if (date.day < 1 || date.month > 12 || date.month < 1 || date.year < 1)
		{
			return false;
		}

		if (date.day > numberOfDaysInMonth(date.month, date.year))
		{
			return false;
		}

		return true;

	}

	bool isValid() {

		return isValidDate(*this);

	}

	static string dateToString(clsDate date) {

		return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);

	}

	string dateToString() {

		return dateToString(*this);

	}

	static bool isLeapYear(short year) {

		return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

	}

	bool isLeapYear() {

		return isLeapYear(_Year);

	}

	static short numberOfDaysInYear(short year) {

		return isLeapYear(year) ? 366 : 365;

	}

	short numberOfDaysInYear() {

		return numberOfDaysInYear(_Year);

	}

	static short numberOfHoursInYear(short year) {

		return numberOfDaysInYear(year) * 24;

	}

	short numberOfHoursInYear() {

		return numberOfHoursInYear(_Year);

	}

	static int numberOfMinutesInYear(short year) {

		return numberOfDaysInYear(year) * 60;

	}

	int numberOfMinutesInYear() {

		return numberOfMinutesInYear(_Year);

	}

	static int numberOfSecondsInYear(short year) {

		return numberOfMinutesInYear(year) * 60;

	}

	int numberOfSecondsInYear() {

		return numberOfSecondsInYear(_Year);

	}

	static short numberOfDaysInMonth(short month, short year) {

		if (month <= 0 || month > 12)
		{
			return 0;
		}

		int arrDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[month - 1];

	}

	short numberOfDaysInMonth() {

		return numberOfDaysInMonth(_Month, _Year);

	}

	static short numberOfHoursInMonth(short month, short year) {

		return numberOfDaysInMonth(month, year) * 24;

	}

	short numberOfHoursInMonth() {

		return numberOfHoursInMonth(_Month, _Year);

	}

	static int numberOfMinutesInMonth(short month, short year) {

		return numberOfHoursInMonth(month, year) * 60;

	}

	int numberOfMinutesInMonth() {

		return numberOfMinutesInMonth(_Month, _Year);

	}

	static int numberOfSecondsInMonth(short month, short year) {

		return numberOfMinutesInMonth(month, year) * 60;

	}

	int numberOfSecondsInMonth() {

		return numberOfSecondsInMonth(_Month, _Year);

	}

	static short dayOfWeekOrder(short day, short month, short year) {

		short a, m, y;

		a = (14 - month) / 12;
		y = year - a;
		m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	}

	short dayOfWeekOrder() {

		return dayOfWeekOrder(_Day, _Month, _Year);

	}

	static string dayShortName(short dayOfWeekOrder) {

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		if (dayOfWeekOrder >= 0 && dayOfWeekOrder <= 6)
		{

			return arrDayNames[dayOfWeekOrder];

		}
		else return "invalid day of week order\n";

	}

	static string dayShortName(short day, short month, short year) {

		short OrderOfDay = dayOfWeekOrder(day, month, year);
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[OrderOfDay];

	}

	string dayShortName() {

		return dayShortName(_Day, _Month, _Year);

	}

	static string monthShortName(short monthNumber) {

		string arrMonths[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return arrMonths[monthNumber - 1];

	}

	string monthShortName() {

		return monthShortName(_Month);

	}

	static void printMonthCalendar(int month, int year) {

		short OrderOfDay = dayOfWeekOrder(1, month, year);
		int numberOfDays = numberOfDaysInMonth(month, year);

		cout << "___________________" << monthShortName(month) << "___________________\n\n";
		cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";

		for (int i = 0; i < OrderOfDay; i++)
			cout << "      ";

		int j = OrderOfDay;
		for (int i = 1; i <= numberOfDays; i++)
		{
			j++;
			cout << setw(3) << i << "   ";

			if (j == 7)
			{
				cout << endl;
				j = 0;
			}

		}
		cout << "\n_________________________________________\n\n";

	}

	void printMonthCalendar() {

		printMonthCalendar(_Month, _Year);

	}

	static void printYearCalendar(int year) {


		cout << "-----------------------------------------\n\n";
		cout << "              Calendar - " << year << endl;
		cout << "\n-----------------------------------------\n\n";

		for (int i = 1; i <= 12; i++)
		{

			printMonthCalendar(i, year);

		}

	}

	void printYearCalendar() {

		printYearCalendar(_Year);

	}

	static short numberOfDaysFromTheBeginningOfYear(short day, short month, short year) {

		int numberOfDays = 0;

		for (int i = 1; i <= month - 1; i++)
		{

			numberOfDays += numberOfDaysInMonth(i, year);

		}

		numberOfDays += day;

		return numberOfDays;

	}

	short numberOfDaysFromTheBeginningOfYear() {

		return numberOfDaysFromTheBeginningOfYear(_Day, _Month, _Year);

	}

	static clsDate getDateFromDayOrderInYear(int dateOrderInYear, int year) {

		clsDate date;

		short RemainingDays = dateOrderInYear;
		short monthDays = 0;

		short day = 0;
		short month = 1;


		while (true) {

			monthDays = numberOfDaysInMonth(month, year);

			if (RemainingDays > monthDays)
			{
				month++;
				RemainingDays -= monthDays;

				if (month > 12)
				{
					month = 1;
					year++;
				}

			}
			else {

				day = RemainingDays;
				break;

			}

		}

		date.day = day;
		date.month = month;
		date.year = year;

		return date;

	}

	static clsDate dateAddDays(int day, int month, int year, int daysToAdd) {

		int totalDays = numberOfDaysFromTheBeginningOfYear(day, month, year) + daysToAdd;
		return getDateFromDayOrderInYear(totalDays, year);

	}

	void AddDays(int daysToAdd) {

		*this = dateAddDays(_Day, _Month, _Year, daysToAdd);

	}

	static bool isDate1BeforDate2(clsDate date1, clsDate date2) {

		return date1._Year < date2._Year ? true : (date1._Year == date2._Year && date1._Month < date2._Month ? true 
			: (date1._Year == date2._Year && date1._Month == date2._Month && date1._Day < date2._Day ? true : false));

	}

	bool isDateBeforDate2(clsDate date2) {

		return isDate1BeforDate2(*this, date2);

	}

	static bool isDate1EqualsDate2(clsDate date1, clsDate date2) {

		return date1._Year == date2._Year && date1._Month == date2._Month && date1._Day == date2._Day;

	}

	bool isDateEqualsDate2(clsDate date2) {

		return isDate1EqualsDate2(*this, date2);

	}

	static bool isDate1AfterDate2(clsDate date1, clsDate date2) {

		return !isDate1BeforDate2(date1, date2) && !isDate1EqualsDate2(date1, date2);

	}

	bool isDateAfterDate2(clsDate date2) {

		return isDate1AfterDate2(*this, date2);

	}

	static bool isLastDayInMonth(clsDate date) {

		return date.day == numberOfDaysInMonth(date.month, date.year);

	}

	bool isLastDayInMonth() {

		return isLastDayInMonth(*this);

	}

	static bool isLastMonthInYear(short month) {

		return month > 12;

	}

	bool isLastMonthInYear() {

		return isLastMonthInYear(_Month);

	}

	static clsDate addOneDay(clsDate date) {

		if (isLastDayInMonth(date))
		{
			date.day = 1;
			date.month++;

			if (isLastMonthInYear(date.month))
			{

				date.day = 1;
				date.month = 1;
				date.year++;

			}

		}
		else {

			date.day++;

		}

		return  date;

	}

	void addOneDay() {

		*this = addOneDay(*this);

	}

	static void swapDates(clsDate &date1, clsDate &date2) {

		clsDate tempDate;

		tempDate = date1;
		date1 = date2;
		date2 = tempDate;

	}

	static int getDifferencesInDays(clsDate date1, clsDate date2, bool includeEndDay = false) {

		int diffOfDays = 0;

		if (isDate1AfterDate2(date1, date2)) {

			while (isDate1AfterDate2(date1, date2)) {

				diffOfDays--;
				date2 = addOneDay(date2);

			}

			return includeEndDay ? --diffOfDays : diffOfDays;


		}
			
		else {

			while (isDate1BeforDate2(date1, date2)) {

				diffOfDays++;
				date1 = addOneDay(date1);

			}

			return includeEndDay ? ++diffOfDays : diffOfDays;
		}
	}

	int getDifferencesInDays(clsDate date2, bool includeEndDay = false) {

		return getDifferencesInDays(*this, date2);

	}

	static int calculateMyAgeInDays(clsDate dateOfBirth) {

		return getDifferencesInDays(dateOfBirth, clsDate());

	}

	static clsDate increaseDateByOneWeek(clsDate &date) {

		for (int i = 1; i <= 7; i++)
		{

			date = addOneDay(date);

		}

		return date;

	}

	void increaseDateByOneWeek() {

		increaseDateByOneWeek(*this);

	}

	static clsDate increaseDateByXWeeks(clsDate &date, short numberOfWeeksToAdd) {

		while (numberOfWeeksToAdd > 0) {

			date = increaseDateByOneWeek(date);
			numberOfWeeksToAdd--;

		}

		return date;

	}

	void increaseDateByXWeeks(short numberOfWeeksToAdd) {

		increaseDateByXWeeks(*this, numberOfWeeksToAdd);

	}

	static clsDate increaseDateByOneMonth(clsDate &date) {

		if (date.month == 12)
		{
			date.month = 1;
			date.year++;
		}
		else
		{
			date.month++;
		}

		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);

		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}


		return date;

	}

	void increaseDateByOneMonth() {

		increaseDateByOneMonth(*this);

	}

	static clsDate increaseDateByXMonths(clsDate date, short numberOfMonthsToAdd) {

		while (numberOfMonthsToAdd > 0) {

			date = increaseDateByOneMonth(date);
			numberOfMonthsToAdd--;

		}

		return date;

	}

	void increaseDateByXMonths(short numberOfMonthsToAdd) {

		increaseDateByXMonths(*this, numberOfMonthsToAdd);

	}

	static clsDate increaseDateByOneYear(clsDate &date) {

		date.year++;

		return date;

		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);

		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}

	}

	void increaseDateByOneYear() {

		increaseDateByOneYear(*this);

	}

	static clsDate increaseDateByXYears(clsDate &date, short numberOfYearsToAdd) {

		while (numberOfYearsToAdd > 0) {

			date = increaseDateByOneYear(date);
			numberOfYearsToAdd--;

		}

		return date;

	}

	void increaseDateByXYears(short numberOfYearsToAdd) {

		increaseDateByXYears(*this, numberOfYearsToAdd);

	}

	static clsDate increaseDateByXYearsFaster(clsDate &date, short numberOfYearsToAdd) {

		date.year += numberOfYearsToAdd;

		return date;

	}

	void increaseDateByXYearsFaster(short numberOfYearsToAdd) {

		increaseDateByXYearsFaster(*this, numberOfYearsToAdd);

	}

	static clsDate increaseDateByOneDecade(clsDate &date) {

		date.year += 10;

		return date;

	}

	void increaseDateByOneDecade() {

		increaseDateByOneDecade(*this);

	}

	static clsDate increaseDateByXDecades(clsDate &date, short numberOfDecadesToAdd) {

		while (numberOfDecadesToAdd > 0) {

			date = increaseDateByOneDecade(date);
			numberOfDecadesToAdd--;

		}

		return date;

	}

	void increaseDateByXDecades(short numberOfDecadesToAdd) {

		increaseDateByXDecades(*this, numberOfDecadesToAdd);

	}

	static clsDate increaseDateByXDecadesFaster(clsDate &date, short numberOfDecadesToAdd) {

		date.year += (numberOfDecadesToAdd * 10);

		return date;

	}

	void increaseDateByXDecadesFaster(short numberOfDecadesToAdd) {

		increaseDateByXDecadesFaster(*this, numberOfDecadesToAdd);

	}

	static clsDate increaseDateByOneCentury(clsDate &date) {

		date.year += 100;

		return date;

	}

	void increaseDateByOneCentury() {

		increaseDateByOneCentury(*this);

	}

	static clsDate increaseDateByOneMillennium(clsDate &date) {

		date.year += 1000;

		return date;

	}

	void increaseDateByOneMillennium() {

		increaseDateByOneMillennium(*this);

	}

	static clsDate decreaseOneDayInDate(clsDate& date) {

		if (date.day == 1)
		{

			if (date.month == 1)
			{

				date.day = 31;
				date.month = 12;
				date.year--;

			}
			else {

				date.month--;
				date.day = numberOfDaysInMonth(date.month, date.year);

			}

		}
		else {

			date.day--;

		}

		return date;

	}

	void decreaseOneDayInDate() {

		decreaseOneDayInDate(*this);

	}

	static clsDate decreaseDateByXDays(clsDate& date, short numberOfDaysToSubtract) {

		while (numberOfDaysToSubtract > 0) {

			date = decreaseOneDayInDate(date);
			numberOfDaysToSubtract--;

		}

		return date;

	}

	void decreaseDateByXDays(short numberOfDaysToSubtract) {

		decreaseDateByXDays(*this, numberOfDaysToSubtract);

	}

	static clsDate decreaseDateByOneWeek(clsDate& date) {

		date = decreaseDateByXDays(date, 7);

		return date;

	}

	void decreaseDateByOneWeek() {

		decreaseDateByOneWeek(*this);

	}

	static clsDate decreaseDateByXWeeks(clsDate& date, short numberOfWeeksToSubtract) {

		while (numberOfWeeksToSubtract > 0) {

			date = decreaseDateByOneWeek(date);
			numberOfWeeksToSubtract--;

		}

		return date;

	}

	void decreaseDateByXWeeks(short numberOfWeeksToSubtract) {

		decreaseDateByXWeeks(*this, numberOfWeeksToSubtract);

	}

	static clsDate decreaseDateByOneMonth(clsDate& date) {


		if (date.month == 1)
		{
			date.month = 12;
			date.year--;
		}
		else
		{
			date.month--;
		}

		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);

		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}


		return date;

	}

	void decreaseDateByOneMonth() {

		decreaseDateByOneMonth(*this);

	}

	static clsDate decreaseDateByXMonths(clsDate& date, short numberOfMonthsToSubtract) {

		while (numberOfMonthsToSubtract > 0) {

			date = decreaseDateByOneMonth(date);
			numberOfMonthsToSubtract--;

		}

		return date;

	}

	void decreaseDateByXMonths(short numberOfMonthsToSubtract) {

		decreaseDateByXMonths(*this, numberOfMonthsToSubtract);

	}

	static clsDate decreaseDateByOneYear(clsDate& date) {

		date.year--;

		short numberOfDaysInCurrentMonth = numberOfDaysInMonth(date.month, date.year);

		if (date.day > numberOfDaysInCurrentMonth)
		{
			date.day = numberOfDaysInCurrentMonth;
		}


		return date;

	}

	void decreaseDateByOneYear() {

		decreaseDateByOneYear(*this);

	}

	static clsDate decreaseDateByXYears(clsDate& date, short numberOfYearsToSubtract) {

		while (numberOfYearsToSubtract > 0) {

			date = decreaseDateByOneYear(date);
			numberOfYearsToSubtract--;

		}

		return date;

	}

	void decreaseDateByXYears(short numberOfYearsToSubtract) {

		decreaseDateByXYears(*this, numberOfYearsToSubtract);

	}

	static clsDate decreaseDateByXYearsFaster(clsDate& date, short numberOfYearsToSubtract) {

		date.year -= numberOfYearsToSubtract;

		return date;

	}

	void decreaseDateByXYearsFaster(short numberOfYearsToSubtract) {

		decreaseDateByXYearsFaster(*this, numberOfYearsToSubtract);

	}

	static clsDate decreaseDateByOneDecade(clsDate& date) {

		date.year -= 10;

		return date;

	}

	void decreaseDateByOneDecade() {

		decreaseDateByOneDecade(*this);

	}

	static clsDate decreaseDateByXDecades(clsDate& date, short numberOfDecadesToSubtract) {

		while (numberOfDecadesToSubtract > 0) {

			date = decreaseDateByOneDecade(date);
			numberOfDecadesToSubtract--;

		}

		return date;

	}

	void decreaseDateByXDecades(short numberOfDecadesToSubtract) {

		decreaseDateByXDecades(*this, numberOfDecadesToSubtract);

	}

	static clsDate decreaseDateByXDecadesFaster(clsDate& date, short numberOfDecadesToSubtract) {

		date.year -= (numberOfDecadesToSubtract * 10);

		return date;

	}

	void decreaseDateByXDecadesFaster(short numberOfDecadesToSubtract) {

		decreaseDateByXDecadesFaster(*this, numberOfDecadesToSubtract);

	}

	static clsDate decreaseDateByOneCentury(clsDate& date) {

		date.year -= 100;

		return date;

	}

	void decreaseDateByOneCentury() {

		decreaseDateByOneCentury(*this);

	}

	static clsDate decreaseDateByOneMillennium(clsDate& date) {

		date.year -= 1000;

		return date;

	}

	void decreaseDateByOneMillennium() {

		decreaseDateByOneMillennium(*this);

	}

	static bool isEndOfWeek(clsDate date) {

		return dayOfWeekOrder(date.day, date.month, date.year) == 6;

	}

	bool isEndOfWeek() {

		return isEndOfWeek(*this);

	}

	static bool isWeekEnd(clsDate date) {

		return dayOfWeekOrder(date.day, date.month, date.year) == 5 || dayOfWeekOrder(date.day, date.month, date.year) == 6;

	}

	bool isWeekEnd() {

		return isWeekEnd(*this);

	}

	static bool isBusinessDay(clsDate date) {

		return !isWeekEnd(date);

	}

	bool isBusinessDay() {

		return isBusinessDay(*this);

	}

	static short daysUntilTheEndOfWeek(clsDate date) {

		return 6 - dayOfWeekOrder(date.day, date.month, date.year);

	}

	short daysUntilTheEndOfWeek() {

		return daysUntilTheEndOfWeek(*this);

	}

	static short daysUntilTheEndOfMonth(clsDate date) {

		return numberOfDaysInMonth(date.month, date.year) - date.day;

	}

	short daysUntilTheEndOfMonth() {

		return daysUntilTheEndOfMonth(*this);

	}

	static short calculateVacationDays(clsDate dateFrom, clsDate dateTo) {

		short daysCount = 0;

		while (isDate1BeforDate2(dateFrom, dateTo))
		{

			dateFrom = addOneDay(dateFrom);

			if (!isWeekEnd(dateFrom))
			{
				daysCount++;
			}

		}

		return daysCount;

	}

	short calculateVacationDays(clsDate dateTo) {

		return calculateVacationDays(*this, dateTo);

	}

	static short calculateBusinessDays(clsDate dateFrom, clsDate dateTo) {

		short daysCount = 0;

		while (isDate1BeforDate2(dateFrom, dateTo))
		{

			dateFrom = addOneDay(dateFrom);

			if (!isWeekEnd(dateFrom))
			{
				daysCount++;
			}


		}

		return daysCount;

	}

	short calculateBusinessDays(clsDate dateTo) {

		return calculateBusinessDays(*this, dateTo);

	}

	static clsDate calculateVacationReturnDate(clsDate date, short vacationDays) {

		while (vacationDays > 0)
		{

			if (!isWeekEnd(date))
			{

				vacationDays--;

			}

			date = addOneDay(date);


		}

		return  date;

	}

	void calculateVacationReturnDate(short vacationDays) {

		*this = calculateVacationReturnDate(*this, vacationDays);

	}

	enum enCompareDate { Before = -1, Equal = 0, After = 1 };

	static enCompareDate compareDates(clsDate date1, clsDate date2) {

		if (isDate1BeforDate2(date1, date2))
		{

			return enCompareDate::Before;

		}

		if (isDate1EqualsDate2(date1, date2))
		{

			return enCompareDate::Equal;

		}

		return enCompareDate::After;

	}

	enCompareDate compareDates(clsDate date2) {

		return  compareDates(*this, date2);

	}

	static string formatDate(clsDate date, string format = "dd/mm/yyyy") {

		string formattedDateString = "";

		formattedDateString = clsString::replaceWordInString(format, "yyyy", to_string(date.year));
		formattedDateString = clsString::replaceWordInString(formattedDateString, "mm", to_string(date.month));
		formattedDateString = clsString::replaceWordInString(formattedDateString, "dd", to_string(date.day));

		return formattedDateString;

	}

	string formatDate(string format = "dd/mm/yyyy") {

		return formatDate(*this, format);

	}

};

