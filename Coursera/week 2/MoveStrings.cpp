#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<string> MoveStrings(vector<string> a, vector<string>& b) {
        for (auto x : a) {
            b.push_back(x);
        }
        a.clear();
        return b;
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for (auto k : destination) {
        cout << k << " " << endl;
    }
}