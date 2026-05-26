#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;


class clsPeriod
{

public:

	clsDate startDate;
	clsDate endDate;

	clsPeriod(clsDate startDate, clsDate endDate) {

		this->startDate = startDate;
		this->endDate = endDate;

	}

    static bool isOverlapPeriods(clsPeriod period1, clsPeriod period2)
    {

        if (
            clsDate::compareDates(period1.endDate, period2.startDate) == clsDate::enCompareDate::Before
            ||
            clsDate::compareDates(period2.endDate, period1.startDate) == clsDate::enCompareDate::Before
            )
            return false;
        else
            return true;

    }

    bool isOverlapPeriods(clsPeriod period2) {

        return isOverlapPeriods(*this, period2);

    }

    static bool isDateInPeriod(clsPeriod period, clsDate dateToCheck) {

        return clsDate::compareDates(dateToCheck, period.startDate) != clsDate::enCompareDate::Before &&
            clsDate::compareDates(dateToCheck, period.endDate) != clsDate::enCompareDate::After;

    }

    bool isDateInPeriod(clsDate dateToCheck) {

        return isDateInPeriod(*this, dateToCheck);

    }

    static int countOverlapDays(clsPeriod period1, clsPeriod period2) {

        int overLapDays = 0;

        if (!isOverlapPeriods(period1, period2))
        {
            return 0;
        }

        if (clsDate::isDate1BeforDate2(period1.startDate, period2.startDate))
        {

            while (!clsDate::isDate1EqualsDate2(period1.startDate, period1.endDate)) {

                if (clsDate::isDate1EqualsDate2(period1.startDate, period2.startDate))
                {
                    overLapDays++;
                    period2.startDate = clsDate::addOneDay(period2.startDate);

                }
                else
                    period1.startDate = clsDate::addOneDay(period1.startDate);
            }

        }
        else {

            while (!clsDate::isDate1EqualsDate2(period2.startDate, period2.endDate)) {

                if (clsDate::isDate1EqualsDate2(period2.startDate, period1.startDate))
                {

                    overLapDays++;
                    period1.startDate = clsDate::addOneDay(period1.startDate);

                }
                else
                    period2.startDate = clsDate::addOneDay(period2.startDate);
            }

        }

        if (clsDate::isDate1EqualsDate2(period1.startDate, period2.startDate))
        {
            overLapDays++;

        }

        return overLapDays;
    }

    int countOverlapDays(clsPeriod period2) {

        return countOverlapDays(*this, period2);

    }

};

