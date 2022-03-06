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
    // std::cout << "Date object created \n";

    time_t now = time(0);
    tm *ltm = localtime(&now);

    this->year = 1900 + ltm->tm_year;
    this->month = 1 + ltm->tm_mon;
    this->day = ltm->tm_mday;
}

Date::Date(int year, int month, int day)
{
    // std::cout << "Date object created \n";
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::~Date()
{
    // std::cout << "Date object destroyed \n";
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
        throw std::invalid_argument("The day is invalid");
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
        throw std::invalid_argument("The month is invalid");
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
        throw std::invalid_argument("The year is invalid");
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
std::string Date::toLithuaniaStandartString() const
{
    std::stringstream ss;
    ss << year << ",";
    ss << std::setw(2) << std::setfill('0') << month << ",";
    ss << std::setw(2) << std::setfill('0') << day;
    return ss.str();
}

std::string Date::toStandartString() const
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << month << "/";
    ss << std::setw(2) << std::setfill('0') << day << "/";
    ss << year;
    return ss.str();
}

std::string Date::toUsaString() const
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
Date Date::operator+(const Date &other) const
{
    Date date(this->getYear(), this->getMonth(), this->getDay());
    date.addDay(other.calculateDaysCount());

    return date;
}

Date Date::operator-(const Date &other) const
{
    Date date(this->getYear(), this->getMonth(), this->getDay());
    date.addDay(-1 * other.calculateDaysCount());

    return date;
}

void Date::operator+=(const Date &other)
{
    this->addDay(other.calculateDaysCount());
}

void Date::operator-=(const Date &other)
{
    this->addDay(-1 * other.calculateDaysCount());
}

Date &Date::operator++()
{
    this->addDay();
    return *this;
}

Date Date::operator++(int)
{
    Date old = *this;
    operator++();
    return old;
}

Date &Date::operator--()
{
    this->addDay(-1);
    return *this;
}

Date Date::operator--(int)
{
    Date old = *this;
    operator--();
    return old;
}

bool Date::operator>(const Date &other) const
{
    return this->calculateDaysCount() > other.calculateDaysCount();
}

bool Date::operator==(const Date &other) const
{
    return this->year == other.year &&
           this->month == other.month &&
           this->day == other.day;
}

bool Date::operator!=(const Date &other) const
{
    return !(*this == other);
}

bool Date::operator<(const Date &other) const
{
    return !(*this > other);
}

bool Date::operator<=(const Date &other) const
{
    return *this == other || *this < other;
}

bool Date::operator>=(const Date &other) const
{
    return *this == other || *this > other;
}

// FRIEND operator overloading
Date operator+(int dayCount, const Date &other)
{
    Date date(other.getYear(), other.getMonth(), other.getDay());
    date.addDay(dayCount);
    return date;
}

Date operator+(const Date &other, int dayCount)
{
    return dayCount + other;
}

std::ostream &operator<<(std::ostream &output, const Date &date)
{
    output << date.toLithuaniaStandartString();
    return output;
}

std::istream &operator>>(std::istream &input, Date &date)
{
    input >> date.year >> date.month >> date.day;
    return input;
}

// helpers
int Date::calculateDaysCount() const
{
    int result = 0;
    Date minimalDate(0, 1, 1);
    Date dateCopy(this->getYear(), this->getMonth(), this->getDay());

    while (minimalDate != dateCopy)
    {
        result++;
        dateCopy.addDay(-1);
    }
    return result;
}