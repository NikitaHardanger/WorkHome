#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;

string str_low(string s) {
    transform(s.begin(), s.end(), s.begin(), tolower);
    return s;
}
bool gt_abs(string s1, string s2) {
    return (str_low(s1) < str_low(s2));
}

int main() {
    int N;
    string s;
    vector<string> v;
    cin >> N;
    for (int i = 0; i < N ; i++) {
        cin >> s;
        v.push_back(s);
    }
    sort(begin(v), end(v), gt_abs);

    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    return 0;
}