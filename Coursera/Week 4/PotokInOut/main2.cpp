#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadAll(const string& path) {
    ifstream input(path);
    if (input) {
        string s;
        while(getline(input, s)) {
            cout << s << endl;
        }
    }
}

int main() {
//    string date = "E:/C++ projects/Coursera/Week 4/PotokInOut/date.txt";
//    ifstream input(date);
//    int day = 0;
//    int month = 0;
//    int year = 0;
//    if (input) {
//        input >> year;
//        input.ignore(1);
//        input >> month;
//        input.ignore(1);
//        input >> day;
//        input.ignore(1);
//    }
//    cout << year << "." << month << "." << day << endl;
    const string path = "output.txt";
    ofstream output(path, ios::app);
    output << "abc" << endl;

    ReadAll(path);

    return 0;
}