#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ifstream input("input3.txt");
    string lines;
    int N, M;
    input >> N >> M;
    input.ignore(1);
    for (int i = N; i > 0;--i) {
        for (int z = M; z > 1; --z) {
            getline(input, lines, ',');
            cout << setw(10) << lines << " ";
        }
        getline(input, lines);
        cout << setw(10) << lines << endl;
    }
    return 0;
}