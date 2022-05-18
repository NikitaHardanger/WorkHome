#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> w = v;
    reverse(w.begin(), w.end());
    return w;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    for (auto z : Reversed(numbers)) {
        cout << z << " ";
    }
    return 0;
}