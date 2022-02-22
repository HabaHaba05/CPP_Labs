#pragma once
#include "Date.hpp"

class Activity
{
private:
    static int activitiesCountTotal;
    std::string description;
    Date *start, *end;

public:
    Activity() = delete;
    Activity(Date *, Date *, std::string description = "");
    ~Activity();

    Date *getStartDate() const;
    Date *getEndDate() const;
    std::string getDescription() const;

    void setStartDate(Date *);
    void setEndDate(Date *);
    void setDescription(const std::string &);

    bool hasStarted();
    bool hasEnded();

    void prolongByOneDay();
};