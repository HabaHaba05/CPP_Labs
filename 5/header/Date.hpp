#pragma once
#include <iostream>

// Minimum date is 0000-01-01
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
    std::string toLithuaniaStandartString() const;
    std::string toStandartString() const;
    std::string toUsaString() const;

    // operator overloading
    Date operator+(const Date &other) const;
    Date operator-(const Date &other) const;
    void operator+=(const Date &other);
    void operator-=(const Date &other);

    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);

    bool operator>(const Date &other) const;
    bool operator==(const Date &other) const;

    bool operator!=(const Date &other) const;
    bool operator<(const Date &other) const;
    bool operator<=(const Date &other) const;
    bool operator>=(const Date &other) const;

    // FRIEND operator overloading
    friend Date operator+(int, const Date &);
    friend Date operator+(const Date &, int);
    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::istream &operator>>(std::istream &is, Date &obj);

    // helper
    int calculateDaysCount() const;
};