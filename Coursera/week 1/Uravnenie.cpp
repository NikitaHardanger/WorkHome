#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    int D = (b*b) - 4*a*c;
    D = sqrt(D);
    if (a == 0) {
        double x4;
        x4 = -c/b;
        cout << x4;

    } else if (D == 0) {
        double x3;
        x3 = -b/(2*a);
        cout << x3;
    } else if (D > 0) {
        double x1, x2;
        x1 = (-b + D)/(2*a);
        x2 = (-b - D)/(2*a);
        cout << x1 << ' ' << x2;
    } else {
        return 0;
    }
}