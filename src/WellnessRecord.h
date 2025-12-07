#ifndef WELLNESS_RECORD_H
#define WELLNESS_RECORD_H

#include <string>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

class WellnessRecord
{
private:
    Date date;
    string time;
    int mood;
    int steps;
    double sleepHours;

public:
    WellnessRecord();
    WellnessRecord(Date d, string t, int m, int s, double sh);

    Date getDate() const;
    string getTime() const;

    bool operator<(const WellnessRecord &other) const;

    friend void printRecord(const WellnessRecord &rec);
};

#endif
