#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include"clsstring.h"


using namespace std;
class clsdate
{
private:
	short _day = 1;
	short _month = 1;
	short _year = 1900;

public:

	clsdate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_day = now->tm_mday;
		_month = now->tm_mon + 1; // tm_mon is 0-based
		_year = now->tm_year + 1900; // tm_year is years since 1900
	}
	clsdate(string stdate)
	{
		vector<string>vdate;
		vdate = clsstring::splet_each_word_in_string(stdate, "/");
		_day = stoi(vdate.at(0));
		_month = stoi(vdate.at(1));
		_year = stoi(vdate.at(2));
	}
	clsdate(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	clsdate(short day_order_in_year, short year)
	{
		clsdate date1 = convert_days_of_year_to_dat(day_order_in_year, year);
		_day = date1._day;
		_month = date1._month;
		_year = date1._year;
	}

	void set_day(short day)
	{
		_day = day;
	}
	short get_day()
	{
		return _day;
	}
	__declspec(property(get = get_day, put = set_day)) short day;

	void set_month(short month)
	{
		_month = month;
	}
	short get_month()
	{
		return _month;
	}
	__declspec(property(get = get_month, put = set_month)) short month;


	void set_year(short year)
	{
		_year = year;
	}
	short get_year()
	{
		return _year;
	}
	__declspec(property(get = get_year, put = set_year)) short year;


	void Print()
	{
		cout << DateToString() << endl;
	}

	static short day_Order_from_Gregorian_calender(short day, short month, short year)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	short day_Order_from_Gregorian_calender()
	{
		return 	day_Order_from_Gregorian_calender(_day, _month, _year);

	}

	static short day_Order_from_Gregorian_calender_overloded(clsdate date)
	{

		return day_Order_from_Gregorian_calender(date._day, date._month, date._year);
	}

	static string DateToString(clsdate date)
	{
		return  to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}
	string DateToString()
	{
		return  DateToString(*this);
	}

	static bool Is_leap_year(short year)
	{
		return((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

	static short month_days_of_year(short month, short year)
	{
		if (month < 1 || month>12)
			return 0;
		short month_arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return ((month == 2) ? ((Is_leap_year(year) ? 29 : 28)) : month_arr[month]);
	}
	short month_days_of_year()
	{
		return month_days_of_year(_month, _year);
	}

	static clsdate convert_days_of_year_to_dat(short days, short year)
	{
		clsdate date;
		if (days < 1 || days >(Is_leap_year(year) ? 366 : 365))
			return date;
		date._year = year;
		date._month = 1;
		while (days > month_days_of_year(date._month, year))
		{
			days -= month_days_of_year(date._month, year);
			date._month++;
		}
		date._day = days;
		return date;
	}
	clsdate convert_days_of_year_to_dat(short days)
	{
		return convert_days_of_year_to_dat(days, _year);
	}

	static int Days_in_year(short year)
	{
		return (Is_leap_year(year) ? 366 : 365);
	}
	int Days_in_year()
	{
		return Days_in_year(_year);
	}

	static int Hours_in_year(short year)
	{
		return Days_in_year(year) * 24;
	}
	int Hours_in_year()
	{
		return  Hours_in_year(_year);
	}

	static	long Minutes_in_year(short year)
	{
		return Days_in_year(year) * 24 * 60;
	}
	long Minutes_in_year()
	{
		return Minutes_in_year(_year);
	}

	static	long Seconds_in_year(short year)
	{
		return Days_in_year(year) * 24 * 60 * 60;
	}
	long Seconds_in_year()
	{
		return Seconds_in_year(_year);
	}

	static string Weekday_Name(short day_index)
	{
		string day_arr[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return day_arr[day_index];
	}
	string Weekday_Name()
	{
		short day_index = day_Order_from_Gregorian_calender(_day, _month, _year);
		return Weekday_Name(day_index);
	}

	static void show_Weekday()
	{
		string day_arr[] = { "Sun","Mon","Tues","Wed","Thur","Fri","Sat" };
		for (string day : day_arr)
			cout << setw(5) << day;
	}

	static string month_of_year(short month_nunber)
	{
		if (month_nunber < 1 || month_nunber>12)return "Month Error";
		string month_arr[] = { "","January","February","March","April","May","June"
			,"July","August","September","October","November","December" };
		return month_arr[month_nunber];
	}
	string month_of_year()
	{
		return month_of_year(_month);
	}

	static void Month_Calender(short month, short year)
	{
		short day_index = day_Order_from_Gregorian_calender(1, month, year);
		short monthday = month_days_of_year(month, year);
		short count = day_index;
		cout << "\n------------" << month_of_year(month) << "--------------\n";
		show_Weekday();
		cout << "\n";
		for (short j = 0; j < day_index; j++)
		{
			cout << "     ";
		}
		for (short i = 0; i < monthday; i++)
		{

			if (count++ % 7 == 0 && count != 0)
			{
				cout << "\n";
			}
			//printf("%5d", i + 1);
			//printf(" %02d  ", i + 1);
			cout << setw(5) << i + 1;
			//count++;
		}
		cout << "\n" << string(35, '-') << endl;
	}
	void Month_Calender()
	{
		Month_Calender(_month, _year);

	}

	static void Year_Calender(short year)
	{
		cout << string(35, '-');
		cout << "\n----------" << "Calender-" << year << "------------\n";
		cout << string(35, '-') << endl;
		for (short i = 1; i < 13; i++)
			Month_Calender(i, year);
	}
	void Year_Calender()
	{
		Year_Calender(_year);
	}

	static short days_from_begining_of_year(short day, short month, short year)
	{
		short total_days = 0;
		for (short i = 1; i <= month - 1; i++)
		{
			total_days += month_days_of_year(i, year);
		}
		return total_days + day;
	}
	short days_from_begining_of_year()
	{
		return 	days_from_begining_of_year(_day, _month, _year);
	}

	static clsdate add_dsys_to_date(short days, clsdate date)
	{
		date._day = days_from_begining_of_year(date._day, date._month, date._year) + days;
		date._month = 1;
		while (date._day > month_days_of_year(date._month, date._year))
		{
			date._day -= month_days_of_year(date._month, date._year);
			date._month++;                       //for test(input [days 2500]  day10 / moth 10 / year2022 )
			if (date._month > 12)                        //(output 14 /8/2029)
			{
				date._month = 1;
				date._year++;
			}
		}
		return date;
	}
	clsdate add_dsys_to_date(short days)
	{
		return 	add_dsys_to_date(days, *this);

	}

	static bool Is_valid_date(clsdate date)
	{
		if (date.month < 1 || date.month > 12)
			return false;
		if (date.day < 1 || date.day > month_days_of_year(date.month, date.year))
			return false;
		return true;
	}
	bool Is_valid_date()
	{
		return Is_valid_date(*this);
	}

	static bool Is_Date1_Befor_Date2(clsdate date1, clsdate date2)
	{
		if (date1._year < date2._year)
			return true;
		if (date1._year == date2._year)
		{
			if (date1._month < date2._month)
				return true;
			if (date1._month == date2._month)
				if (date1._day < date2._day)
					return true;
		}
		return false;
	}
	bool Is_currnt_Date_Befor_Date2(clsdate date2)
	{
		return Is_Date1_Befor_Date2(*this, date2);
	}

	static bool Is_Date1_After_Date2(clsdate date1, clsdate date2)
	{
		return(!(Is_Date1_Befor_Date2(date1, date2)) && !(Is_Date1_Equal_Date2(date1, date2)));
	}
	bool Is_currnt_Date_After_Date2(clsdate date2)
	{
		return Is_Date1_After_Date2(*this, date2);
	}


	static bool Is_Date1_Equal_Date2(clsdate date1, clsdate date2)
	{
		if (date1._year && date1._month == date2._month && date1._day == date2._day)
			return true;
		return false;
	}
	bool Is_currnt_Date_Equal_Date2(clsdate date2)
	{
		return Is_Date1_Equal_Date2(*this, date2);
	}

	static clsdate Increas_date_by_one(clsdate date)
	{
		if (Is_Last_day_in_month(date))
		{
			if (Is_Last_month_in_year(date))
			{
				date._day = 1;
				date._month = 1;
				date._year++;
			}
			else
			{
				date._day = 1;
				date._month++;
			}
		}
		else
			date._day++;
		return date;
	}
	clsdate Increas_date_by_one()
	{
		return Increas_date_by_one(*this);
	}

	static int diffrance_between_two_dates(clsdate date1, clsdate date2, bool include_end_day = 0)
	{
		int deffrance = 0;
		short flag_swap = 1;
		if (Is_Date1_Befor_Date2(date1, date2))
		{
			swap(date1, date2);
			flag_swap = -1;
		}

		while (Is_Date1_Befor_Date2(date1, date2))
		{
			date1 = Increas_date_by_one(date1);
			deffrance++;
		}
		return(include_end_day ? ++deffrance * flag_swap : deffrance * flag_swap);
	}
	int diffrance_between_two_dates(clsdate date2)
	{
		return diffrance_between_two_dates(*this, date2);
	}

	static int Birth_days_in_days(clsdate date1, clsdate date2, bool include_end_day = 0)
	{
		int deffrance = 0;
		while (Is_Date1_Befor_Date2(date1, date2))
		{
			date1 = Increas_date_by_one(date1);
			deffrance++;
		}
		return(include_end_day ? ++deffrance : deffrance);
	}
	int Birth_days_in_days(clsdate date_of_birth)
	{
		return Birth_days_in_days(date_of_birth, *this);
	}

	static clsdate Increas_date_by_x_days(int xdays, clsdate date)
	{
		for (int i = 0; i < xdays; i++)
		{
			date = Increas_date_by_one(date);
		}
		return date;
	}
	clsdate Increas_date_by_x_days(int xdays)
	{
		return Increas_date_by_x_days(xdays, *this);
	}

	static clsdate Increas_date_by_one_week(clsdate date)
	{
		for (int i = 0; i < 7; i++)
		{
			date = Increas_date_by_one(date);
		}
		return date;
	}
	clsdate Increas_date_by_one_week()
	{
		return Increas_date_by_one_week(*this);
	}

	static clsdate Increas_date_by_x_weeks(int xweeks, clsdate date)
	{
		for (int i = 0; i < xweeks; i++)
		{
			date = Increas_date_by_one_week(date);
		}
		return date;
	}
	clsdate Increas_date_by_x_weeks(int xweeks)
	{
		return  Increas_date_by_x_weeks(xweeks, *this);
	}

	static clsdate Increas_date_by_one_month(clsdate date)
	{
		if (Is_Last_month_in_year(date))
		{
			date._month = 1;
			date._year++;
		}
		else
		{
			date._month++;
		}
		if (date._day > month_days_of_year(date._month, date._year))
		{
			date._day = month_days_of_year(date._month, date._year);
		}
		return date;
	}
	clsdate Increas_date_by_one_month()
	{
		return Increas_date_by_one_month(*this);
	}

	static clsdate Increas_date_by_x_months(int xmonths, clsdate date)
	{
		for (int i = 0; i < xmonths; i++)
		{
			date = Increas_date_by_one_month(date);
		}
		return date;
	}
	clsdate Increas_date_by_x_months(int xmonths)
	{
		return Increas_date_by_x_months(xmonths, *this);
	}

	static clsdate Increas_date_by_one_year(clsdate date)
	{
		date._year++;
		return date;
	}
	clsdate Increas_date_by_one_year()
	{
		return  Increas_date_by_one_year(*this);
	}

	static clsdate Increas_date_by_x_year(int xyear, clsdate date)
	{
		for (int i = 0; i < xyear; i++)
		{
			date = Increas_date_by_one_year(date);
		}
		return date;
	}
	clsdate Increas_date_by_x_year(int xyear)
	{
		return Increas_date_by_x_year(xyear, *this);
	}

	static clsdate Increas_date_by_x_year_faster(int xyear, clsdate date)
	{
		date._year += xyear;
		return date;
	}
	clsdate Increas_date_by_x_year_faster(int xyear)
	{
		return Increas_date_by_x_year_faster(xyear, *this);
	}

	static clsdate Increas_date_by_one_decade(clsdate date)
	{
		date._year += 10;
		return date;
	}
	clsdate Increas_date_by_one_decade()
	{
		return Increas_date_by_one_decade(*this);
	}

	static clsdate Increas_date_by_x_decades(int xdecades, clsdate date)
	{
		for (int i = 0; i < xdecades; i++)
		{
			date = Increas_date_by_one_decade(date);
		}
		return date;
	}
	clsdate Increas_date_by_x_decades(int xdecades)
	{
		return Increas_date_by_x_decades(xdecades, *this);
	}

	static clsdate Increas_date_by_x_decades_faster(int xdecades, clsdate date)
	{
		date._year += (xdecades * 10);
		return date;
	}
	clsdate Increas_date_by_x_decades_faster(int xdecades)
	{
		return Increas_date_by_x_decades_faster(xdecades, *this);
	}

	static clsdate Increas_date_by_one_century(clsdate date)
	{
		date._year += 100;
		return date;
	}
	clsdate Increas_date_by_one_century()
	{
		return Increas_date_by_one_century(*this);
	}

	static clsdate Increas_date_by_one_Milleium(clsdate date)
	{
		date._year += 1000;
		return date;
	}
	clsdate Increas_date_by_one_Milleium()
	{
		return  Increas_date_by_one_Milleium(*this);
	}

	static clsdate Decreas_date_by_one(clsdate date)
	{
		if (date._day == 1)
		{
			if (date._month == 1)
			{
				date._day = month_days_of_year(date._month, date._year);
				date._month = 12;
				date._year--;
			}
			else
			{
				date._month--;
				date._day = month_days_of_year(date._month, date._year);

			}
		}
		else
			date._day--;
		return date;
	}
	clsdate Decreas_date_by_one()
	{
		return Decreas_date_by_one(*this);
	}

	static clsdate Decreas_date_by_x_days(int xdays, clsdate date)
	{
		for (int i = 0; i < xdays; i++)
		{
			date = Decreas_date_by_one(date);
		}
		return date;
	}
	clsdate Decreas_date_by_x_days(int xdays)
	{
		return Decreas_date_by_x_days(xdays, *this);
	}

	static clsdate Decreas_date_by_one_week(clsdate date)
	{
		for (int i = 0; i < 7; i++)
		{
			date = Decreas_date_by_one(date);
		}
		return date;
	}
	clsdate Decreas_date_by_one_week()
	{
		return Decreas_date_by_one_week(*this);
	}

	static clsdate Decreas_date_by_x_weeks(int xweeks, clsdate date)
	{
		for (int i = 0; i < xweeks; i++)
		{
			date = Decreas_date_by_one_week(date);
		}
		return date;
	}
	clsdate Decreas_date_by_x_weeks(int xweeks)
	{
		return Decreas_date_by_x_weeks(xweeks, *this);
	}

	static clsdate Decreas_date_by_one_month(clsdate date)
	{
		if (date._month == 1)
		{
			date._month = 12;
			date._year--;
		}
		else
		{
			date._month--;
		}
		if (date._day > month_days_of_year(date._month, date._year))
		{
			date._day = month_days_of_year(date._month, date._year);
		}
		return date;
	}
	clsdate Decreas_date_by_one_month()
	{
		return Decreas_date_by_one_month(*this);
	}

	static clsdate Decreas_date_by_x_months(int xmonths, clsdate date)
	{
		for (int i = 0; i < xmonths; i++)
		{
			date = Decreas_date_by_one_month(date);
		}
		return date;
	}
	clsdate Decreas_date_by_x_months(int xmonths)
	{
		return Decreas_date_by_x_months(xmonths, *this);
	}

	static clsdate Decreas_date_by_one_year(clsdate date)
	{
		date._year--;
		return date;
	}
	clsdate Decreas_date_by_one_year()
	{
		return Decreas_date_by_one_year(*this);
	}

	static clsdate Decreas_date_by_x_year(int xyear, clsdate date)
	{
		for (int i = 0; i < xyear; i++)
		{
			date = Decreas_date_by_one_year(date);
		}
		return date;
	}
	clsdate Decreas_date_by_x_year(int xyear)
	{
		return Decreas_date_by_x_year(xyear, *this);
	}

	static clsdate Decreas_date_by_x_year_faster(int xyear, clsdate date)
	{
		date._year -= xyear;
		return date;
	}
	clsdate Decreas_date_by_x_year_faster(int xyear)
	{
		return Decreas_date_by_x_year_faster(xyear, *this);
	}

	static clsdate Decreas_date_by_one_decade(clsdate date)
	{
		date._year -= 10;
		return date;
	}
	clsdate Decreas_date_by_one_decade()
	{
		return Decreas_date_by_one_decade(*this);
	}

	static clsdate Decreas_date_by_x_decades(int xdecades, clsdate date)
	{
		for (int i = 0; i < xdecades; i++)
		{
			date = Decreas_date_by_one_decade(date);
		}
		return date;
	}
	clsdate Decreas_date_by_x_decades(int xdecades)
	{
		return Decreas_date_by_x_decades(xdecades, *this);
	}

	static clsdate Decreas_date_by_x_decades_faster(int xdecades, clsdate date)
	{
		date._year -= (xdecades * 10);
		return date;
	}
	clsdate Decreas_date_by_x_decades_faster(int xdecades)
	{
		return Decreas_date_by_x_decades_faster(xdecades, *this);
	}

	static clsdate Decreas_date_by_one_century(clsdate date)
	{
		date._year -= 100;
		return date;
	}
	clsdate Decreas_date_by_one_century()
	{
		return Decreas_date_by_one_century(*this);
	}

	static clsdate Decreas_date_by_one_Milleium(clsdate date)
	{
		date._year -= 1000;
		return date;
	}
	clsdate Decreas_date_by_one_Milleium()
	{
		return Decreas_date_by_one_Milleium(*this);
	}

	static bool Is_Last_day_in_month(clsdate date)
	{
		short month_day = month_days_of_year(date._month, date._year);
		return (date._day == month_day);
	}
	bool Is_Last_day_in_month()
	{
		return Is_Last_day_in_month(*this);
	}

	static bool Is_Last_month_in_year(clsdate date)
	{
		return (date._month == 12);
	}
	bool Is_Last_month_in_year()
	{
		return Is_Last_month_in_year(*this);
	}

	static bool Is_End_of_week(clsdate date)
	{
		short Day_order = day_Order_from_Gregorian_calender_overloded(date);
		return(Day_order == 6);
	}
	bool Is_End_of_week()
	{
		return Is_End_of_week(*this);
	}

	static bool Is_WeekEnd(clsdate date)
	{
		short Day_order = day_Order_from_Gregorian_calender_overloded(date);
		return(Day_order == 5 || Day_order == 6);
	}
	bool Is_WeekEnd()
	{
		return Is_WeekEnd(*this);
	}

	static bool Is_Business_Day(clsdate date)
	{
		return (!Is_WeekEnd(date));
	}
	bool Is_Business_Day()
	{
		return Is_Business_Day(*this);
	}

	static short Days_until_weekEnd(clsdate date)
	{
		short day_index = day_Order_from_Gregorian_calender_overloded(date);
		short days = 0;
		for (short i = day_index; i < 5; i++)
		{
			days++;
		}
		return days;
	}
	short Days_until_weekEnd()
	{
		return Days_until_weekEnd(*this);
	}

	static short Days_until_end_of_week(clsdate date)
	{
		short day_index = day_Order_from_Gregorian_calender_overloded(date);
		return (6 - day_index);
	}
	short Days_until_end_of_week()
	{
		return  Days_until_end_of_week(*this);
	}

	static short Days_until_end_of_month(clsdate date)
	{
		clsdate date2;

		date2._day = month_days_of_year(date._month, date._year);
		date2._month = date._month;
		date2._year = date._year;
		short days = diffrance_between_two_dates(date, date2, 1);
		return days;
	}
	short Days_until_end_of_month()
	{
		return Days_until_end_of_month(*this);
	}

	static short Days_until_end_of_year(clsdate date)
	{
		clsdate date2;

		date2._day = 31;
		date2._month = 12;
		date2._year = date._year;
		short days = diffrance_between_two_dates(date, date2, 1);
		return days;
	}
	short Days_until_end_of_year()
	{
		return Days_until_end_of_year(*this);
	}

	static short calculate_vacation(clsdate from, clsdate to)
	{
		int Actual_vacation = 0;
		while (Is_Date1_Befor_Date2(from, to))
		{
			if (Is_Business_Day(from))
			{
				Actual_vacation++;
			}
			from = Increas_date_by_one(from);
		}
		return Actual_vacation;
	}

	static clsdate CalculateVacationReturnDate(clsdate DateFrom, short VacationDays)
	{
		//Hadhod solving
		// -------------
		short WeekEndCounter = 0;
		//in case the data  is weekend keep adding one day util you reach business day
	//we get rid of all weekends before the first business day
		while (Is_WeekEnd(DateFrom))
		{
			DateFrom = Increas_date_by_one(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (Is_WeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = Increas_date_by_one(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (Is_WeekEnd(DateFrom))
		{
			DateFrom = Increas_date_by_one(DateFrom);
		}

		return DateFrom;
	}


	static short compare_two_dates(clsdate date1, clsdate date2)
	{
		if (Is_Date1_Befor_Date2(date1, date2))
			return -1;
		else if (Is_Date1_After_Date2(date1, date2))
			return 1;
		else
			return 0;
	}
	short compare_two_dates(clsdate date1)
	{
		return compare_two_dates(date1, *this);
	}



};