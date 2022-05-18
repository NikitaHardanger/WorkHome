#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {
//    const int x = 5;
//    x = 6;
//    x += 4;
//    cout << x;

//    const string s = "hello";
//    cout << s.size() << endl;
////    s += ", world";
//    string t = s + "!";
//    cout << s;

    vector<string> w = {"hello"};
    w[0][0] = 'H';
    cout << w[0];
    return 0;
}