#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int min;

    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}


ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

Duration operator-(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour - rhs.hour, lhs.min - rhs.min);
}

Duration operator*(const Duration& lhs, const Duration& rhs) {
    int total_first = lhs.hour * 60 + lhs.min;
    int total_second = rhs.hour * 60 + rhs.min;
    int total = total_first * total_second;
    int hour = total / 60;
    int min = total % 60;
    return Duration(hour, min);
}

Duration operator/(const Duration& lhs, const Duration& rhs) {
    int total_first = lhs.hour * 60 + lhs.min;
    int total_second = rhs.hour * 60 + rhs.min;
    int total = total_first / total_second;
    int hour = total / 60;
    int min = total % 60;
    return Duration(hour, min);
}

void PrintVector(const vector<Duration>& durs) {
    for (const auto& d : durs) {
        cout << d << ' ';
    }
    cout << endl;
}

bool operator<(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}

int main() {
    stringstream dur_ss("2:50");
    Duration dur1;
    dur_ss >> dur1;
    Duration dur2 = {0, 5};
    Duration dur3 = dur1 + dur2;
    Duration dur4 = dur1 - dur2;
    Duration dur5 = dur1 * dur2;
    Duration dur6 = dur1 / dur2;
    vector<Duration> v {
         dur5, dur3, dur1, dur6, dur4, dur2,
    };
    PrintVector(v);
    sort(begin(v), end(v));
    PrintVector(v);
    return 0;
}