#include "WellnessRecord.h"
#include <iostream>

WellnessRecord::WellnessRecord()
{
    date = {0, 0, 0};
    time = "";
    mood = 0;
    steps = 0;
    sleepHours = 0.0;
}

WellnessRecord::WellnessRecord(Date d, string t, int m, int s, double sh)
{
    date = d;
    time = t;
    mood = m;
    steps = s;
    sleepHours = sh;
}

Date WellnessRecord::getDate() const
{
    return date;
}

string WellnessRecord::getTime() const
{
    return time;
}

int WellnessRecord::getMood() const
{
    return mood;
}

int WellnessRecord::getSteps() const
{
    return steps;
}

double WellnessRecord::getSleepHours() const
{
    return sleepHours;
}

bool WellnessRecord::operator<(const WellnessRecord &other) const
{
    if (date.year != other.date.year)
        return date.year < other.date.year;
    if (date.month != other.date.month)
        return date.month < other.date.month;
    if (date.day != other.date.day)
        return date.day < other.date.day;

    return time < other.time;
}

void printRecord(const WellnessRecord &rec)
{
    cout << rec.date.year << "-" << rec.date.month << "-" << rec.date.day;
    cout << "  Time: " << rec.time;
    cout << "  Mood: " << rec.mood;
    cout << "  Steps: " << rec.steps << endl;
}
