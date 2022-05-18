//
// Created by Nikit on 24/10/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        data.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(data), end(data));
        return data;
    }

private:
    vector<string> data;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    int N = 0;
    cin >> N;
    SortedStrings strings;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        strings.AddString(str);
    }

    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
