#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, number;
    vector<int> v;
    cin >> N;
    for (N; N > 0 ; --N) {
        cin >> number;
        v.push_back(number);
    }
    sort(begin(v), end(v), [](const int& x, const int& y) {
        return abs(x) < abs(y);
    });
    for (const auto& i : v) {
        cout << i << " ";
    }
    return 0;
}