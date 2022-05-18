#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
//    map<string, int> b = {{"a", 1}, {"b", 2}, {"c", 3}};
//    vector<int> a = {1, 3, 5, 7, 9, 11};
//
//    int sum = 0;
//    for (auto i : a) {
//        sum += i;
//    }
//
//    cout << sum;
//    int sum = 0;
//    string concat;
//    for (auto i : b) {
//        concat += i.first;
//        sum += i.second;
//    }
//    cout << concat << endl;
//    cout << sum;
    string a = "coffee";

    int i = 0;
    for (auto c : a) {
        if (c == 'a') {
            cout << i << endl;
        }
        ++i;
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'a') {
            cout << i << endl;
            break;
        }
    }
    return 0;
}