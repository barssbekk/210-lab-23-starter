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
    Goat()                          { name = ""; age = 0; color = ""; }
    Goat(string userName)           { name = userName; }
    Goat(string userName, int userAge) { age = userAge; }
    Goat(string userName, int userAge, string userColor) {
        name = userName;
        age = userAge;
        color = userColor;
    }
    // write three more constructors

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
};

#endif