#include <iostream>
using namespace std;

int main()
{
    bool running = true;

    while (running)
    {
        cout << "==============================\n"
             << "BMCC STUDENT WELLNESS TRACKER\n"
             << "==============================\n";

        cout << endl
             << "1. Add a new wellness record\n"
             << "2. Show all records\n"
             << "3. Sort records (date/time)\n"
             << "4. Save records to file\n"
             << "5. Load records from file\n"
             << "0. Exit\n";

        int choice;
        cout << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            break;

        case 0:
            cout << "Exiting...\n";
            running = false;
            break;

        default:
            cout << "Invalid input.\n";
        }
    }

    return 0;
}