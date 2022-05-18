//
// Created by Nikit on 25/08/2021.
//
#include <iostream>
#include <map>

using namespace std;

void PrintMap(const map<int, string>& m) {
    cout << "Size = " << m.size() << endl;
    for (const auto& [key, value] : m) {
        cout << key << ": " << value << endl;
    }
}

void PrintReversedMap(const map<string, int>& m) {
    cout << "Size = " << m.size() << endl;
    for (auto [key, value] : m) {
        cout << key << ": " << value << endl;
    }
}

map<string, int> BuildReverseMap(const map<int, string>& m) {
    map<string, int> result;
    for (auto [key, value] : m) {
        result[value] = key;
    }
    return result;
}

int main() {
    map<int, string> events;
    events[1950] = "Bjarne Stroustrup's birth";
    events[1941] = "Dennis Ritchie's birth";
    events[1970] = "UNIX epoch start";
    PrintMap(events);

    cout << events[1950] << endl;

    events.erase(1970);
    PrintMap(events);

    PrintReversedMap(BuildReverseMap(events));
    return 0;
}