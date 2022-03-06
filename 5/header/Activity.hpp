#pragma once
#include "Date.hpp"

class Activity
{
private:
    static int activitiesCountTotal;
    std::string description;
    Date *start, *end;
    std::string pathToAttachment;

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
    void setPathToAttachment(const std::string &);

    bool hasStarted();
    bool hasEnded();

    void prolongByOneDay();

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &, const Activity &);
};