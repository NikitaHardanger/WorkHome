
//
// Created by Nikit on 25/08/2021.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void PrintMap(const map<string, int>& m) {
    cout << "Size: " << m.size() << endl;
    for (const auto& item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}


int main() {
//    map<string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
//    PrintMap(m);
//    m.erase("three");
//    PrintMap(m);
//    vector<string> words = {"one", "two", "one"};
//    map<string, int> counters;
//    for (const string& word : words) {
//            ++counters[word];
//    }
//    PrintMap(counters);
//    map<string, int> m = {{"one", 1}, {"two", 2}};
//    for (const auto& [key, value] : m ) {
//        cout << key << ": " << value << endl;
//    }
    vector<string> words = {"one", "two", "three", "wasd", "avc"};
    map<char, vector<string>> grouped_words;
    for (const string& word : words) {
        grouped_words[word[0]].push_back(word);
    }
    for (const auto& [key, value] : grouped_words) {
        cout << key << endl;
        for (const string& word : value) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}