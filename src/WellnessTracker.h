#ifndef WELLNESS_TRACKER_H
#define WELLNESS_TRACKER_H

#include <vector>
#include "WellnessRecord.h"

using namespace std;

class WellnessTracker
{
public:
    WellnessTracker();
    ~WellnessTracker();
    void addRecord();
    void showAll();
    void saveToFile();
    void loadFromFile();

private:
    vector<WellnessRecord> records;

    WellnessRecord *tempArrayPtr;
};

#endif
