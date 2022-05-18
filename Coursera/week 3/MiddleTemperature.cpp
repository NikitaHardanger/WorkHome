#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& v) {
    int MiddleTemp = 0;
    int i = 0;
    int o = 0;
    for (auto s : v) {
        MiddleTemp += s;
    }
    MiddleTemp /= v.size();
    for (auto s : v) {
        if (s > MiddleTemp) {
            i++;
        }
    }
    cout << i << endl;
    for (auto s : v) {
        if (s > MiddleTemp) {
            cout << o << " ";
        }
        o++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> Temperature_in_days(n);
    for (int& s : Temperature_in_days) {
        cin >> s;
    }
    PrintVector(Temperature_in_days);
    return 0;
}