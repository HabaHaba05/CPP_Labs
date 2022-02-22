#include "../header/Date.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

// Private
// fields
const int Date::daysCountCommonYears[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int Date::daysCountLeapYears[12] = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int *Date::getDaysCountOfCurrentYear()
{
    return year % 4 == 0 ? daysCountLeapYears : daysCountCommonYears;
};

// Public
// constructors & destructor
Date::Date()
{
    std::cout << "Date object created \n";

    time_t now = time(0);
    tm *ltm = localtime(&now);

    this->year = 1900 + ltm->tm_year;
    this->month = 1 + ltm->tm_mon;
    this->day = ltm->tm_mday;
}

Date::Date(int year, int month, int day)
{
    std::cout << "Date object created \n";
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::~Date()
{
    std::cout << "Date object destroyed \n";
}

// others
void Date::addDay(int count)
{
    auto increment = [](Date *dateObj)
    {
        const int *daysCount = dateObj->getDaysCountOfCurrentYear();

        if (dateObj->day == daysCount[dateObj->month - 1])
        {
            dateObj->day = 1;
            if (dateObj->month == 12)
            {
                dateObj->month = 1;
                dateObj->year++;
                return;
            }
            dateObj->month++;
            return;
        }
        dateObj->day++;
    };

    auto subtract = [](Date *dateObj)
    {
        const int *daysCount = dateObj->getDaysCountOfCurrentYear();

        if (dateObj->day == 1)
        {
            if (dateObj->month == 1)
            {
                dateObj->day = 31;
                dateObj->month = 12;
                dateObj->year--;
                return;
            }
            dateObj->month--;
            dateObj->day = daysCount[dateObj->month - 1];
            return;
        }
        dateObj->day--;
    };

    if (count > 0)
    {
        while (count != 0)
        {
            increment(this);
            count--;
        }
    }
    else if (count < 0)
    {
        while (count != 0)
        {
            subtract(this);
            count++;
        }
    }
}

// setters
void Date::setDay(int day)
{
    const int *daysCount = getDaysCountOfCurrentYear();
    if (day < 1 || day > daysCount[month - 1])
    {
        throw std::range_error("The day is invalid \n");
    }
    else
    {
        this->day = day;
    }
}

void Date::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
        throw std::range_error("The month is invalid");
    }
    else
    {
        this->month = month;
    }
}

void Date::setYear(int year)
{
    if (year < 0)
    {
        throw std::range_error("The year is invalid\n");
    }
    else
    {
        this->year = year;
    }
}

// getters
int Date::getDay() const
{
    return this->day;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getYear() const
{
    return this->year;
}

// formatting date

std::string Date::toStandartString()
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << month << "/";
    ss << std::setw(2) << std::setfill('0') << day << "/";
    ss << year;
    return ss.str();
}

std::string Date::toUsaString()
{
    std::stringstream ss;
    std::string monthName[] =
        {"January", "February", "March", "April", "May",
         "June", "July", "August", "September", "October",
         "November", "December"};

    ss << monthName[month - 1] << "  " << day << ", " << year;
    return ss.str();
}

// operator overloading
bool Date::operator>(const Date &other)
{
    return this->year > other.year ||
           this->month > other.month ||
           this->day > other.day;
}