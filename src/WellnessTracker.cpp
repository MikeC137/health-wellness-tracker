#include "WellnessTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

WellnessTracker::WellnessTracker()
{
    tempArrayPtr = nullptr;
}

WellnessTracker::~WellnessTracker()
{
    delete[] tempArrayPtr;
}

void WellnessTracker::addRecord()
{

    Date d;
    string t;
    int m;
    int s;
    double sh;

    cout << "Enter year (e.g. 2025): ";
    cin >> d.year;
    cout << "Enter month (1-12): ";
    cin >> d.month;
    cout << "Enter day (1-31): ";
    cin >> d.day;
    cout << "Enter time (HH:MM): ";
    cin >> t;
    cout << "Enter mood (1-10): ";
    cin >> m;
    cout << "Enter steps: ";
    cin >> s;
    cout << "Enter sleep hours (e.g. 7.5): ";
    cin >> sh;

    WellnessRecord rec(d, t, m, s, sh);
    records.push_back(rec);

    cout << "\nRecord added.\n\n";
}

void WellnessTracker::showAll()
{
    cout << "\n";

    vector<WellnessRecord> sortedRecords = records;

    for (size_t i = 0; i < sortedRecords.size(); i++)
    {
        for (size_t j = 0; j < sortedRecords.size() - i - 1; j++)
        {
            if (sortedRecords[j + 1] < sortedRecords[j])
            {
                WellnessRecord temp = sortedRecords[j];
                sortedRecords[j] = sortedRecords[j + 1];
                sortedRecords[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < sortedRecords.size(); i++)
    {
        printRecord(sortedRecords[i]);
    }

    cout << "\n";
}

void WellnessTracker::saveToFile()
{

    ofstream file("records.txt");

    if (file.is_open())
    {
        file << records.size() << '\n';
        for (size_t i = 0; i < records.size(); ++i)
        {
            Date d = records[i].getDate();
            file << d.year << ' ' << d.month << ' ' << d.day << ' ';
            file << records[i].getTime() << ' ';
            file << records[i].getMood() << ' ' << records[i].getSteps() << ' ' << records[i].getSleepHours() << '\n';
        }
        file.close();
        cout << "Saved " << records.size() << " records to records.txt\n\n";
        return;
    }

    file.close();
    cout << "Failed to open records.txt for writing.\n\n";
}

void WellnessTracker::loadFromFile()
{
    ifstream file("records.txt");

    if (file.is_open())
    {
        size_t count = 0;
        if (!(file >> count))
        {
            cout << "Failed to read record count.\n\n";
            file.close();
            return;
        }

        records.clear();
        for (size_t i = 0; i < count; ++i)
        {
            Date d;
            string t;
            int m = 0;
            int s = 0;
            double sh = 0.0;

            if (!(file >> d.year >> d.month >> d.day >> t >> m >> s >> sh))
            {
                break;
            }

            WellnessRecord rec(d, t, m, s, sh);
            records.push_back(rec);
        }

        file.close();
        cout << "Loaded " << records.size() << " records from records.txt\n\n";
        return;
    }

    cout << "Failed to open records.txt for reading.\n\n";
}
