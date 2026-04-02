// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat() { name = ""; age = 0; color = ""; }

    // write three more constructors
    Goat(const string& userName) {
        name = userName;
        age = 0;
        color = "";
    }
    Goat(const string& userName, const int userAge) {
        name = userName;
        age = userAge;
        color = "";
    }
    Goat(const string& userName, const int userAge, const string& userColor) {
        name = userName;
        age = userAge;
        color = userColor;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator < (const Goat& other) const {
        return name < other.name;
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

    // TODO: add goat
    void add_goat(list<Goat>& trip)

    // TODO: delete goat
    // TODO: print goat
};

#endif