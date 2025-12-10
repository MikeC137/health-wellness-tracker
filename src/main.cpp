#include <iostream>
#include "WellnessTracker.h"

using namespace std;

int main()
{
    WellnessTracker tracker;

    int choice = -1;

    while (choice != 0)
    {
        cout << "\n";
        cout << "==============================\n";
        cout << "BMCC STUDENT WELLNESS TRACKER\n";
        cout << "==============================\n";
        cout << "1. Add a new wellness record \n";
        cout << "2. Show all records\n";
        cout << "3. Save records to file\n";
        cout << "4. Load records from file\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            tracker.addRecord();
            break;
        case 2:
            tracker.showAll();
            break;
        case 3:
            tracker.saveToFile();
            break;
        case 4:
            tracker.loadFromFile();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }

        cout << "\n";
    }
    return 0;
}
