#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int q;
    string word;
    cin >> q; // count words
    set<string> rare_words;
    for (int i = 0; i < q; ++i) {
        cin >> word;
        rare_words.insert(word);
    }
    cout << rare_words.size() << endl;

    return 0;
}
