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
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
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




    return 0;
}

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

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % (MA
}

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
