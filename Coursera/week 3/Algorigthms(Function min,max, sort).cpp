#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

void PrintVector(const vector<int>& v, const string& title) {
    cout << title << ": ";
    for (auto i : v) {
        cout << i << " ";
    }
}

int main() {
    vector<int> v = {1, 2, 5, 3, 4};
//    PrintVector(v, "init");
//    sort(begin(v), end(v));
//    cout << endl;
//    PrintVector(v, "sort");

// lyambda_function:
    int i = 0;
    cin >> i;
    cout << count_if(begin(v), end(v), [i](int x) {
        if (x > i) {
            return true;
        }
        return false;
    });

    return 0;
}