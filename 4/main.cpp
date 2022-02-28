#include <iostream>
#include "header/Date.hpp"
#include <vector>
#include "header/Activity.hpp"

void clearVectorContents(std::vector<Activity *> &a);

int main()
{
    const int datesCount = 6;
    int dates[datesCount][3]{
        {1, 1, 1},     // Valid
        {2020, 2, 29}, // Valid
        {2021, 2, 29}, // Invalid
        {2021, 99, 1}, // Invalid
        {1999, 4, 31}, // Invalid
        {-1, 4, 30}    // Invalid
    };

    for (int i = 0; i < datesCount; i++)
    {
        try
        {
            Date date(dates[i][0], dates[i][1], dates[i][2]);
            std::cout << "Valid date: " << date.toStandartString() << std::endl;
        }
        catch (std::invalid_argument const &ex)
        {
            std::cout << "Exception: " << ex.what() << std::endl;
        }
    };
    std::cout << "------------------------\n";

    Date dt(2021, 2, 1);
    try
    {
        dt.setDay(29);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    std::cout << "------------------------\n";

    Date *start = new Date(2021, 1, 1);
    Date *end = new Date(2021, 2, 1);
    Activity activity(start, end);
    activity.setPathToAttachment("test.txt");

    try
    {
        activity.setPathToAttachment("doesntExist.txt");
    }
    catch (std::runtime_error const &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    delete start;
    delete end;
};