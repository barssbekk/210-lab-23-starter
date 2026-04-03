#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20, MIN_AGE = 1;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (i < SZ_NAMES && fin >> names[i]) {
        i++;
    }

    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (i < SZ_COLORS && fin1 >> colors[i]) {
        i++;
    }
    fin1.close();
    list<Goat> trip;
    while (again) {
        int choice = main_menu();

        switch (choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                again = false;
                break;
        }
    }

    return 0;
}

void add_goat(list<Goat>& trip, string names[], string colors[]) {
    string rndName = names[rand() % SZ_NAMES];
    string rndColors = colors[rand() % SZ_COLORS];
    int rndAge = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
    trip.push_back(Goat(rndName, rndAge, rndColors));
    trip.sort();
}

// TODO: delete goat
void delete_goat(list<Goat>& trip) {
    if (trip.empty()) return;
}
// TODO: print goat
void display_trip(list<Goat> trip) {
    int index = 1;
    for (Goat g : trip) {
        cout << "[" << index++ << "] "
             << g.get_name()
             << " (" << g.get_age()
             << ", " << g.get_color()
             << ")\n";
    }
}

int main_menu() {
    int choice = 0;
    cout << "*** GOAT MANAGER 3001 ***\n"
         << "[1] Add a goat\n"
         << "[2] Delete a goat\n"
         << "[3] List goats\n"
         << "[4] Quit\n"
         << "Choice --> ";
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cerr << "Invalid input. Try again: ";
        cin >> choice;
    }
    return choice;
}

