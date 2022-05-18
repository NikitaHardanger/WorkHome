#include <iostream>
#include <string>

using namespace std;

int main() {

    string a;
    cin >> a;
    int j = 0;
    for (int i = 0; i < a.size() ; ++i) {
        if (a[i] == 'f') {
            ++j;
            if (j == 2) {
                cout << i;
            }
        }

    }
    if (j == 0) {
        cout << -2;
    }
    if (j == 1) {
        cout << -1;
    }
    return 0;
}