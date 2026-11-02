#include<iostream>
#include<string>
using namespace std;

//VEHICLE DATA
struct Vehicle
{
    string number;
    string owner;
    bool parked;
};

//Slots for vehicles
Vehicle slots[10];

//initialisation(to start with empty vehicles)
void initialize()
{
    for (int i = 0; i < 10; i++)
    {
        slots[i].parked = false;
    }
}

//parking slot status
void showSlots()
{
    cout << "\n--- Parking Slots ---\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i + 1 << ": ";

        if (slots[i].parked)
            cout << "Occupied\n";
        else
            cout << "Empty\n";
    }
}

//new vehicle parking
void parkVehicle()
{
    for (int i = 0; i < 10; i++)
    {
        if (!slots[i].parked)
        {
            cout << "\nEnter vehicle number: ";
            cin >> slots[i].number;

            cout << "Enter owner name: ";
            cin >> slots[i].owner;

            slots[i].parked = true;

            cout << "Vehicle parked in Slot " << i + 1 << "!\n";
            return;
        }
    }

    cout << "Parking is full!\n";
}

//vehicle removing
void removeVehicle()
{
    string number;
    int hours;

    cout << "\nEnter vehicle number: ";
    cin >> number;

    for (int i = 0; i < 10; i++)
    {
        if (slots[i].parked && slots[i].number == number)
        //parking charges
        {
            cout << "Enter parking time in hours: ";
            cin >> hours;

            int charge = hours * 20;

            cout << "Parking Charge = Rs. " << charge << endl;

            slots[i].parked = false;

            cout << "Vehicle removed!\n";
            return;
        }
    }

    cout << "Vehicle not found!\n";
}

//vehicle search
void searchVehicle()
{
    string number;

    cout << "\nEnter vehicle number: ";
    cin >> number;

    for (int i = 0; i < 10; i++)
    {
        if (slots[i].parked && slots[i].number == number)
        {
            cout << "Vehicle found!\n";
            cout << "Owner: " << slots[i].owner << endl;
            cout << "Slot: " << i + 1 << endl;
            return;
        }
    }

    cout << "Vehicle not found!\n";
}

int main()
{
    initialize();
    int choice = 0;
    //console menu
    do
    {
        cout << "\n===== SMART PARKING SYSTEM =====\n";
        cout << "1. Show Parking Slots\n";
        cout << "2. Park Vehicle\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Search Vehicle\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << "Invalid input!\n";
         continue;
         }

        switch (choice)
        {
            case 1:
                showSlots();
                break;

            case 2:
                parkVehicle();
                break;

            case 3:
                removeVehicle();
                break;

            case 4:
                searchVehicle();
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}