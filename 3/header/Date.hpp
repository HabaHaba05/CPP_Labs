#pragma once
#include <iostream>

class Date
{
private:
    static const int daysCountCommonYears[], daysCountLeapYears[];
    int month, day, year;

    const int *getDaysCountOfCurrentYear();

public:
    // constructors & destructor
    Date();
    Date(int year, int month = 1, int day = 1);
    ~Date();

    // others
    void addDay(int count = 1);

    // setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    // getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // format date
    std::string toStandartString();
    std::string toUsaString();

    // operator overloading
    bool operator>(const Date &other);
};