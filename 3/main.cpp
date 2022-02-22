#include <iostream>
#include "header/Date.hpp"
#include <vector>
#include "header/Activity.hpp"

void clearVectorContents(std::vector<Activity *> &a);

int main()
{
    std::vector<Date *> dates{
        new Date(), new Date(20), new Date(2021, 12, 31),
        new Date(2021, 2, 28), new Date(2020, 2, 28)};

    for (int i = 0; i < dates.size(); i++)
    {
        std::cout << dates[i]->toStandartString();
        dates[i]->addDay(5);
        std::cout << " + 5days = " << dates[i]->toStandartString();
        dates[i]->addDay(-5);
        std::cout << " -5days = " << dates[i]->toStandartString() << std::endl;

        delete dates[i];
    }

    dates.erase(dates.begin(), dates.end());

    std::cout << "--------------------------\n";
    Activity *m1 = new Activity(new Date(2022, 2, 18), new Date(2022, 2, 20));
    Activity *m2 = new Activity(new Date(2022, 3, 20), new Date(2022, 3, 21));

    std::vector<Activity *> activities{m1, m2};

    for (int i = 0; i < activities.size(); i++)
    {
        std::cout << activities[i]->hasStarted() << " " << activities[i]->hasEnded() << std::endl;
    }

    std::cout << activities[0]->getEndDate()->toUsaString() << std::endl;
    activities[0]->prolongByOneDay();
    std::cout << activities[0]->getEndDate()->toUsaString() << std::endl;

    clearVectorContents(activities);
}

void clearVectorContents(std::vector<Activity *> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        delete a[i];
    }
    a.clear();
}