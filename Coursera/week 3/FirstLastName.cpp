//
// Created by Nikit on 24/10/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstName[year] = first_name; // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name) {
        lastName[year] = last_name; // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int year) {
        bool foundName = false;
        bool foundSurN = false;
        string name, surname;
        int limit = (*firstName.begin()).first;

        for (int i = year; i >= limit; --i) {
            if (firstName.count(i)) {
                name = firstName[i];
                foundName = true;
                break;
            }
        }
        limit = lastName.begin() -> first;
        for (int i = year; i >= limit ; --i) {
            if(lastName.count(i)) {
                surname = lastName[i];
                foundSurN = true;
                break;
            }
        }
        if (foundName && foundSurN) return name + " " + surname;
        else if (foundName) return name + " with unknown last name";
        else if (foundSurN) return surname + " with unknown first name";
        else return "Incognito";
    }


private:
    map<int, string> firstName;
    map<int, string> lastName;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    Person person1;
    person1.ChangeFirstName(1999, "Michael");
    person1.ChangeLastName(2000, "Ivanov");
    for (int year : {1998, 1999, 2001}) {
        cout << person1.GetFullName(year) << endl;
    }

    Person person2;
    person1.ChangeFirstName(1999, "David");
    person1.ChangeLastName(2000, "Valiev");
    for (int year : {1998, 1999, 2001}) {
        cout << person1.GetFullName(year) << endl;
    }

    return 0;

}
