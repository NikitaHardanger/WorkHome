#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int cost = 10;
    int ost = N % 50;
    int need_ost = 50 - ost;
    int new_weight = N + need_ost;
    int koef = new_weight / 51;
    cost += (koef - 1) * 5;
    cout << cost << endl;
    return 0;
}