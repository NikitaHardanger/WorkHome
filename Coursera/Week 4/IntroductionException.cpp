#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        ss << "expected / , but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

Date ParseDate(const string& s) {
    stringstream stream(s);
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}


int main() {
    string date_str = "2021/11/24";
    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0') << date.day << '.'
             << setw(2) << setfill('0') << date.month << '.'
             << date.year << endl;
    } catch (exception& ex) {
        cout << "Exception happens: " << ex.what();
    }
    return 0;
}