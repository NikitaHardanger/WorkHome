#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void Reverse(vector<int>& v) {
    vector<int> u;
    for (int i = 0; i < v.size() ; ++i) {
        int q = 0;
        int b = v.size();
        q = v[(b-1)-i];
        u.push_back(q);
    }
    v = u;
 // or reverse(v.begin(), v.end()); !!!!
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto z : numbers) {
        cout << z << " ";
    }
    return 0;
}