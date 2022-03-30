#pragma once
#include <iostream>
#include <string>
#include "myArray.hpp"
#include "Activity.hpp"

using namespace std;

class Team
{
private:
    const string teamName;
    MyArray<Activity *> activities;

public:
    Team(const string &teamName) : teamName(teamName)
    {
    }

    string getTeamName()
    {
        return this->teamName;
    }

    MyArray<Activity *> getActivities()
    {
        return this->activities;
    }

    void addActivity(Activity *activity)
    {
        activities.pushBack(activity);
    }

    MyArray<Activity *> selectActivities(bool hasEnded)
    {
        MyArray<Activity *> res;
        for (int i = 0; i < activities.getSize(); i++)
        {
            if (activities[i]->hasEnded() == hasEnded)
            {
                res.pushBack(activities[i]);
            }
        }
        return res;
    }

    void sortActivitiesByStartDateDesc()
    {
        int dataCount = activities.getSize();
        for (int i = 0; i < dataCount - 1; i++)
        {
            for (int j = 0; j < dataCount - i - 1; j++)
            {
                if (activities[j]->getStartDate() < activities[j + 1]->getStartDate())
                {
                    Activity *tmp = activities[j + 1];
                    activities.setData(j + 1, activities[j]);
                    activities.setData(j, tmp);
                }
            }
        }
    };

    void printActivities()
    {
        cout << teamName << endl;
        for (int i = 0; i < activities.getSize(); i++)
        {
            cout << i << " " << *activities[i] << endl;
        }
    }
};