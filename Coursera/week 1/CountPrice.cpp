#include <iostream>

using namespace std;

int main() {

    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    if (N <= A && N <= B) {
        cout << N << endl;
    } else if (N > B && A < B) {
        Y = (100 - Y) / 100;
        N *= Y;
        cout << N << endl;
    } else if (N >= A && A < B) {
        X = (100 - X)/100;
        N *= X;
        cout << N << endl;
    } else {
        cout << "Wrong value" << endl;
    }
    return 0;
}