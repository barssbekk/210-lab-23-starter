#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
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

    list<Goat> test;
    add_goat(test, names, colors);
    display_trip(test);

    return 0;
}

void add_goat(list<Goat>& trip, string names[], string colors[]) {
    string rndName = names[rand() % SZ_NAMES];
    string rndColors = colors[rand() % SZ_COLORS];
    int rndAge = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
    trip.push_back(Goat(rndName, rndAge, rndColors));
}

// TODO: delete goat
void delete_goat(list<Goat>& trip) {

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

