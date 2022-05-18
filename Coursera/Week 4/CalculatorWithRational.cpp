#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <exception>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw 1;
        }
        else if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            } else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }
        int nod = NOD(abs(numerator), abs(denominator));
        num = numerator / nod;
        den = denominator / nod;
    }

    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return den;
    }
private:
    int num;
    int den;

    int NOD(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        return a + b;
    }
};

bool operator==(const Rational& a, const Rational& b) {
    int p;
    int q;
    if (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator()) {
        return true;
    } else {
        return false;
    }
}

Rational operator+(const Rational& a, const Rational& b) {
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p,q);
}

Rational operator-(const Rational& a, const Rational& b) {
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p,q);
}

Rational operator*(const Rational& a, const Rational& b) {
    int p = (a.Numerator() * b.Numerator());
    int q = (a.Denominator() * b.Denominator());
    return Rational(p,q);
}

Rational operator/(const Rational& a, const Rational& b) {
    if (b.Numerator() == 0) throw 2;
    int p = (a.Numerator() * b.Denominator());
    int q = (a.Denominator() * b.Numerator());
    return Rational(p,q);
}

ostream& operator<<(ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& r) {
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = {p, q};
    }
    return stream;
}

bool operator>(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}

bool operator<(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}


int main() {
    try {
        Rational a, b;
        char ch;
        cin >> a >> ch >> b;
        if (ch == '+') {
            cout << a + b;
        } else if (ch == '-') {
            cout << a - b;
        } else if (ch == '*') {
            cout << a * b;
        } else {
            cout << a / b;
        }
    } catch (int i) {
        if (i == 1) {
            cout << "Invalid argument";
        } else {
            cout << "Division by zero";
        }

    }
    return 0;
}