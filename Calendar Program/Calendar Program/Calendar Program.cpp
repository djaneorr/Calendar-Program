#include <iostream>
#include <iomanip> // we will use setw()
using namespace std;
// prototypes
int getMonth();
int getYear();
int computeOffset(int year, int month);
int numDaysInYear(int year);
int numDaysInMonth(int year, int month);
bool isLeapYear(int year);
void displayHeader(int year, int month);
void displayTable(int numDays, int offset);
void display(int year, int month, int offset);
/**************************************************************
* I chose to use prototypes because that way I didn't need to scroll up and
* down a million times to see my full parameter list.
*************************************************************/
int main()
{
	// this runs month, year, and offset so the program knows
	// the input from the user and can use it to run the rest
	// of the program
	int month = getMonth();
	int year = getYear();
	int offset = computeOffset(year, month);
	display(year, month, offset);
	return 0;
}
/**************************************************************
* Get Month
*************************************************************/
int getMonth()
{
	int month;
	// prompt for the month
	do
	{
		cout << "Enter a month number: ";
		cin >> month;
		if (month < 1 || month > 12)
		{
			// error message if an invalid month is provided
			cout << "Month must be between 1 and 12.\n";
		}
	}
	// keep prompting until a proper input is given (a month from and including
	// 1 to 12)
	while (month < 1 || month > 12);
	return month;
}
/**************************************************************
* Get Year
*************************************************************/
int getYear()
{
	int year;
	// prompt for a year
	do
	{
		cout << "Enter year: ";
		cin >> year;
		if (year < 1753)
		{
			// error message if an invalid year is provided
			cout << "Year must be 1753 or later.\n";
		}
	}
	// keep prompting until a proper input is given (a year greater than 1752)
	while (year < 1753);
	return year;
}
/**************************************************************
* Compute Offset
*************************************************************/
int computeOffset(int year, int month)
{
	int totalNumDays = 0;
	// the year must be greater than 1752
	for (int i = year - 1; i > 1752; i--)
	{
		// the increment the total number of days based on the provided year
		totalNumDays += numDaysInYear(i);
	}
	// the month must be between and including 1 and 12
	for (int j = month - 1; j > 0; j--)
	{
		// the increment the total number of days based on the provided month
		totalNumDays += numDaysInMonth((year), j);
	}
	// the number of spaces (skipped days) at the beginning of the calendar
	int offset = totalNumDays % 7;
	return offset;
}
/**************************************************************
* Number of Days in the inputed Year
*************************************************************/
int numDaysInYear(int year)
{
	bool leapYear = isLeapYear(year);
	// normal (a non-leap year number of days)
	int daysInYear = 365;
	if (leapYear)
	{
		// if the year is a leap year
		daysInYear = 366;
	}
	return daysInYear;
}
/**************************************************************
* Number of days in the inputed month
*************************************************************/
int numDaysInMonth(int year, int month)
{
	bool leapYear = isLeapYear(year);
	// start with 0 and update based on the month provided
	int daysInMonth = 0;
	// April, June, September, or November
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		daysInMonth = 30;
	}
	// February
	else if (month == 2)
	{
		if (leapYear)
		{
			// if it is a leap year
			daysInMonth = 29;
		}
		else
		{
			// if it is not a leap year
			daysInMonth = 28;
		}
	}
	// January, March, May, July, August, October, December
	else
	{
		daysInMonth = 31;
	}
	return daysInMonth;
}
/**************************************************************
* If it is a leap year
*************************************************************/
bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}
/**************************************************************
* Calendar Header
*************************************************************/
void displayHeader(int year, int month)
{
	cout << endl;
	// this basically correlates the inputed month number with the name of the
	// said month
	if (month == 1)
	{
		cout << "January, ";
	}
	else if (month == 2)
	{
		cout << "February, ";
	}
	else if (month == 3)
	{
		cout << "March, ";
	}
	else if (month == 4)
	{
		cout << "April, ";
	}
	else if (month == 5)
	{
		cout << "May, ";
	}
	else if (month == 6)
	{
		cout << "June, ";
	}
	else if (month == 7)
	{
		cout << "July, ";
	}
	else if (month == 8)
	{
		cout << "August, ";
	}
	else if (month == 9)
	{
		cout << "September, ";
	}
	else if (month == 10)
	{
		cout << "October, ";
	}
	else if (month == 11)
	{
		cout << "November, ";
	}
	else
	{
		cout << "December, ";
	}
	// print the year onto the screen
	cout << year
		<< endl;
	// calendar header
	cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
	return;
}
/**************************************************************
* Calendar Table (the worst part of this project)
*************************************************************/
void displayTable(int numDays, int offset)
{
	// number of days per week (row)
	int fullWeek = offset + 1;
	// position the first date based on the offset
	for (int i = offset; i >= 0; i--)
	{
		// add 4 spaces (placeholder days) if week is not full
		if (fullWeek < 7)
		{
			cout << setw(4) << " ";
		}
	}
	// reset the week once the max number of days (7) is reached
	if (fullWeek == 7)
	{
		fullWeek = 0;
	}
	// print the calendar days to screen
	for (int i = 1; i <= numDays; i++)
	{
		// new row when the max number of days is reached and reset the week
		if (fullWeek == 7)
		{
			cout << endl;
			fullWeek = 0;
		}
		cout << setw(4) << i;
		// the increment count
		fullWeek++;
	}
	// final line return to end calendar
	cout << endl;
}
/****
* Overall Display Function:
* Basically calls both of the display functions in the order they
* should appear
* ************************************************************/
void display(int year, int month, int offset)
{
	int numDays = numDaysInMonth(year, month);
	// the calendar header
	displayHeader(year, month);
	// the calendar table
	displayTable(numDays, offset);
	return;
}