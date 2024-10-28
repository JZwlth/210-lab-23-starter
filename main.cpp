#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> &trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names[], string colors[]);
void display_trip(const list<Goat> &trip);
int main_menu();

int main() {
    srand(time(0));  // Seed the random number generator
    bool again = true;
    list<Goat> trip;

    // Read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // GM3K1 Engine Loop
    while (again) {
        int choice = main_menu();
        switch (choice) {
            case 1: add_goat(trip, names, colors); break;
            case 2: delete_goat(trip); break;
            case 3: display_trip(trip); break;
            case 4: 
                cout << "Exiting... Goodbye!\n";
                again = false;
                break;
            default: 
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}

// Main menu function
int main_menu() {
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";
    cin >> choice;
    return choice;
}

// Function to add a goat to the trip
void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % (MAX_AGE + 1);  // Random age between 0 and MAX_AGE

    Goat new_goat(name, age, color);
    trip.push_back(new_goat);
    cout << "Added: ";
    new_goat.display();
    cout << "\n";
}

// Function to delete a goat from the trip
void delete_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats to delete!\n";
        return;
    }
    int index = select_goat(trip);
    if (index == -1) return;  // User canceled

    auto it = trip.begin();
    advance(it, index);
    cout << "Deleted: ";
    it->display();
    cout << "\n";
    trip.erase(it);
}

// Function to display all goats in the trip
void display_trip(const list<Goat> &trip) {
    if (trip.empty()) {
        cout << "No goats in the trip!\n";
        return;
    }
    cout << "\nCurrent Trip:\n";
    int index = 1;
    for (const auto &goat : trip) {
        cout << "[" << index++ << "] ";
        goat.display();
        cout << "\n";
    }
}

// Function to select a goat from the list
int select_goat(list<Goat> &trip) {
    display_trip(trip);
    cout << "Select a goat by number (0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice == 0) return -1;  // Cancel operation

    if (choice < 1 || choice > trip.size()) {
        cout << "Invalid selection!\n";
        return -1;
    }
    return choice - 1;  // Convert to 0-based index
}
