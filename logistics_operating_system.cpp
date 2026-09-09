#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to store package details
struct Package {
    int packageID;
    string destination;
    float distance;
    int deadline;
    float shippingCost;
};

// Function to print the table (used after every sort)



void printSchedule(Package pkg[], int n, string title) {
    cout << "\n--- " << title << " ---\n";
    cout << "ID\tDestination\t\tDistance\tDeadline\tCost\n";
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << pkg[i].packageID << "\t"
             << left << setw(16) << pkg[i].destination << "\t"
             << pkg[i].distance << " km\t\t"
             << pkg[i].deadline << " hrs\t\t"
             << "$" << fixed << setprecision(2) << pkg[i].shippingCost << "\n";
    }
}

// Simple bubble sort - sorts by deadline (smallest first) - Emergency Mode
void sortByDeadline(Package pkg[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pkg[j].deadline > pkg[j + 1].deadline) {
                Package temp = pkg[j];
                pkg[j] = pkg[j + 1];
                pkg[j + 1] = temp;
            }
        }
    }
}

// Bubble sort by distance (smallest first) - Fuel-Saving Mode
void sortByDistance(Package pkg[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pkg[j].distance > pkg[j + 1].distance) {
                Package temp = pkg[j];
                pkg[j] = pkg[j + 1];
                pkg[j + 1] = temp;
            }
        }
    }
}

// Bubble sort by shipping cost (highest first) - Revenue Mode
void sortByCost(Package pkg[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pkg[j].shippingCost < pkg[j + 1].shippingCost) {
                Package temp = pkg[j];
                pkg[j] = pkg[j + 1];
                pkg[j + 1] = temp;
            }
        }
    }
}

int main() {
    Package packages[5] = {
        {101, "Downtown", 15.5, 4, 25.00},
        {102, "North Suburb", 42.0, 12, 85.50},
        {103, "Airport District", 8.2, 2, 15.00},
        {104, "West Valley", 23.1, 6, 45.00},
        {105, "East Pier", 19.8, 3, 60.00}
    };

    int n = 5;
    int choice;

    cout << "===== GLOBALROUTE LOGISTICS SORTING MODULE =====\n";
    cout << "1. Emergency Mode (Closest Deadline First)\n";
    cout << "2. Fuel-Saving Mode (Shortest Distance First)\n";
    cout << "3. Revenue Mode (Highest Shipping Cost First)\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    // Make a copy so original data doesn't get messed up
    Package temp[5];
    for (int i = 0; i < n; i++) temp[i] = packages[i];

    if (choice == 1) {
        sortByDeadline(temp, n);
        printSchedule(temp, n, "EMERGENCY DELIVERY SCHEDULE");
    } else if (choice == 2) {
        sortByDistance(temp, n);
        printSchedule(temp, n, "FUEL-SAVING DELIVERY SCHEDULE");
    } else if (choice == 3) {
        sortByCost(temp, n);
        printSchedule(temp, n, "REVENUE DELIVERY SCHEDULE");
    } else {
        cout << "Invalid choice! Please enter 1, 2, or 3.\n";
    }

    return 0;
}