#include "../header/Activity.hpp"
#include <fstream>

// Private
int Activity::activitiesCountTotal = 0;

// Public
Activity::Activity(Date *start, Date *end, std::string description)
{
    activitiesCountTotal++;
    this->start = start;
    this->end = end;
    this->description = description;

    std::cout << "Activity created, Total count:" << activitiesCountTotal << std::endl;
}

Activity::~Activity()
{
    activitiesCountTotal--;
    delete start;
    delete end;
    std::cout << "Activity destroyed, Total count:" << activitiesCountTotal << std::endl;
}

Date *Activity::getStartDate() const
{
    return start;
}

Date *Activity::getEndDate() const
{
    return end;
}

std::string Activity::getDescription() const
{
    return description;
}

void Activity::setStartDate(Date *start)
{
    delete this->start;
    this->start = start;
}

void Activity::setEndDate(Date *end)
{
    delete this->end;
    this->end = end;
}

void Activity::setDescription(const std::string &description)
{
    this->description = description;
}

bool Activity::hasStarted()
{
    Date now;
    return *start > now;
}

bool Activity::hasEnded()
{
    Date now;
    return now > *end;
}

void Activity::prolongByOneDay()
{
    this->end->addDay();
}

void Activity::setPathToAttachment(const std::string &pathToAttachment)
{
    std::fstream fileStream;
    fileStream.open(pathToAttachment);
    if (fileStream.fail())
    {
        throw std::runtime_error("File could not be opened");
    }
    fileStream.close();

    this->pathToAttachment = pathToAttachment;
}
