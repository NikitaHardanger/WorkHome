//
// Created by Nikit on 06/09/2021.
//

#include <set>
#include <iostream>
#include <vector>

using namespace std;

void PrintSet(const set<string>& x) {
    cout << "Size = " << x.size() << endl;
    for (auto a : x) {
        cout << a << endl;
    }
};

int main() {
//    set<string> famous_persons;
//    famous_persons.insert("Stroustrup");
//    famous_persons.insert("Ritchie");
//    famous_persons.insert("Nikita");
//    //PrintSet(famous_persons);
//
//    famous_persons.erase("Nikita");
//    //PrintSet(famous_persons);
//
//    set<string> month_names = {"January", "February", "March", "March"};
//    set<string> other_month_names = {"March", "February", "January"};
//    if (month_names == other_month_names) {
//        cout << "Equal" << endl;
//    } else {
//        cout << "Not Equal" << endl;
//    }
//
//    cout << month_names.count("January") << endl;

    vector<string> v = {"a", "b", "a"};
    set<string> s(begin(v), end(v));
    PrintSet(s);


    return 0;
}