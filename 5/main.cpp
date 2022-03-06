#include <iostream>
#include "header/Date.hpp"
#include <vector>
#include "header/Activity.hpp"
#include <sstream>

void clearVectorContents(std::vector<Activity *> &a);

int main()
{
    Date date1(0, 12, 25);
    Date date2(0, 1, 6);

    Date date3 = date1 + date2;

    std::cout << "SUMA" << std::endl;

    std::cout << "Date3: " << date3 << std::endl;
    date1 += date2;
    std::cout << "Date1: " << date1 << std::endl;
    date3 = date3 + 2;
    std::cout << "Date3: " << date3 << std::endl;
    date3 = 2 + date3;
    std::cout << "Date3: " << date3 << std::endl;

    std::cout << "< > <= >= != ==" << std::endl;
    Date dt1(2000, 12, 4), dt2(2000, 1, 4), dt3(2000, 12, 4);
    std::cout << dt1 << " <  " << dt2 << " - " << (dt1 < dt2) << std::endl;
    std::cout << dt1 << " >  " << dt2 << " - " << (dt1 > dt2) << std::endl;
    std::cout << dt1 << " <= " << dt2 << " - " << (dt1 <= dt2) << std::endl;
    std::cout << dt1 << " >= " << dt2 << " - " << (dt1 >= dt2) << std::endl;
    std::cout << dt1 << " != " << dt3 << " - " << (dt1 != dt3) << std::endl;
    std::cout << dt1 << " == " << dt3 << " - " << (dt1 == dt3) << std::endl;

    std::cout << "istream overload" << std::endl;
    std::stringstream ss;
    int lastNumber;
    ss << 1999 << ' ' << 12 << ' ' << 1 << ' ' << 4;
    std::cout << "Before: " << dt1;
    ss >> dt1 >> lastNumber;
    std::cout << " After: " << dt1 << " Last Number:" << lastNumber << std::endl;
    std::cout << "post and pre ++" << std::endl;
    std::cout << "DT1:     " << dt1 << std::endl;
    std::cout << "(PRE )   " << ++dt1 << std::endl;
    std::cout << "(POST )  " << dt1++ << std::endl;
    std::cout << "(RESULT) " << dt1 << std::endl;

    std::cout << "post and pre --" << std::endl;
    std::cout << "DT1:     " << dt1 << std::endl;
    std::cout << "(PRE )   " << --dt1 << std::endl;
    std::cout << "(POST )  " << dt1-- << std::endl;
    std::cout << "(RESULT) " << dt1 << std::endl;

    std::cout << "CONST Test" << std::endl;
    const Date dConst(2000, 1, 1);
    std::cout << dConst << std::endl;
    // dConst.addDay(1); CONST CONST CONST CONST

    std::cout << "------------ACTIVITY------------\n";

    Date *start = new Date(2021, 1, 1);
    Date *end = new Date(2021, 2, 1);
    Activity activity(start, end);

    std::cout << activity << std::endl;

    delete start;
    delete end;
};