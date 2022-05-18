#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for (auto x : m) {
        s.insert(x.second);
    }
    return s;
}