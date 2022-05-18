#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string path = "output.txt";
    const string s = "input.txt";
    string line;
    string line2;
    ifstream input(s);
    if(input) {
        while(getline(input,line)) {
            cout << line << endl;
            ofstream output(path, ios::app);
            output << line << endl;
        }
    }
    return 0;
}