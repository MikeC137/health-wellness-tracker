#ifndef WELLNESS_TRACKER_H
#define WELLNESS_TRACKER_H

#include <vector>
#include "WellnessRecord.h"

using namespace std;

class WellnessTracker
{
private:
    vector<WellnessRecord> records;

    WellnessRecord *tempArrayPtr;

public:
    WellnessTracker();
    ~WellnessTracker();

    void addRecord();
    void showAll();
    void sortRecords();
    void saveToFile();
    void loadFromFile();
};

#endif
