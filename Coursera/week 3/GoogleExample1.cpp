//
// Created by Nikit on 23/08/2021.
//

#include <iostream>
// we need the following include for setw() in some c++ implementations
#include <iomanip>
using namespace std;

int main() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0;  j < 4 ; j++)
            cout << setw(17) << "Hello World!";
        cout << endl;
    }
    return 0;
}