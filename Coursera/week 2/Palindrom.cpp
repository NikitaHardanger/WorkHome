#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrom(string a) {
    int len = a.length();
    for (int i = 0; i < len / 2; ++i) {
        if (a[i] != a[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;
//    IsPalindrom(str);
    if (IsPalindrom(str) == 1) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}