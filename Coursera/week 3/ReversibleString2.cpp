//
// Created by Nikit on 01/11/2021.
//

#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {
        data = "z";
    }
    ReversibleString(const string& s) {
        data = s;
    }
    void Reverse() {
        for_each(data.begin(), data.end(), [](char & c) {
            c = toupper(c);
        });
        reverse(begin(data), end(data));
    }
    string PrintString() const {
        return data;
    }

private:
    string data;
};

int main() {
    ReversibleString s("gorod");
    s.Reverse();
    cout << s.PrintString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.PrintString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.PrintString() << '"' << endl;

    ReversibleString z("Znak");
    cout << z.PrintString() << endl;

    return 0;
}
