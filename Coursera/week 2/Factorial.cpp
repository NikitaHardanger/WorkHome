#include <iostream>

using namespace std;

void Factorial(int N) {
    if (N > 0) {
        int b = 1;
        for (int i = 1; i <= N; ++i) {
            b *= i;
        }
        cout << b;
    } else {
        cout << 1;
    }

}

int main() {
    int x;
    cin >> x;
    Factorial(x);
    return 0;
}