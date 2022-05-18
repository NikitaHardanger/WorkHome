#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string hello = "../Coursera/Week 4/PotokInOut/hello.txt";
    string date = "../Coursera/Week 4/PotokInOut/date.txt";
    ifstream input(hello);
    ifstream input1(date);
    string line;
    string day;
    string month;
    string year;
    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << endl;
        }
        cout << endl << "done!" << endl;
    } else {
        cout << "error!" << endl;
    }
    getline(input1, year, '-');
    getline(input1, month, '-');
    getline(input1, day, '-');
    cout << year << "." << month << "." << day << endl;
    return 0;
}