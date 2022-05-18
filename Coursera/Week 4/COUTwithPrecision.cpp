#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//void Print(const vector<double>& values) {
//    for (const auto& v : values) {
//        cout << fixed <<  setprecision(3);
//        cout <<  v << endl;
//    }
//}

int main() {
//    vector<double> values;
//    int n = 0;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        double v = 0;
//        cin >> v;
//        values.push_back(v);
//    }
//    Print(values);
//
    ifstream input("input1.txt");

    double a;

    cout << fixed << setprecision(3);

    while (input >> a) {
        cout << a << endl;
    }

    return 0;
}