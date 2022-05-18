#include <iostream>
#include <set>
#include <string>
#include <map>
#include <sstream>

using namespace std;

using Synonyms = map<string, set<string>>;

void AddSynonyms(Synonyms& synonyms, const string& word1, const string& word2) {
    synonyms[word2].insert(word1);
    synonyms[word1].insert(word2);
}

size_t GetSynonymCount(Synonyms& synonyms, const string& word) {
    return synonyms[word].size();
}

bool AreSynonyms(Synonyms& synonyms, const string& word1, const string& word2) {
    return synonyms[word1].count(word2) == 1;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}


template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
         os << "Assertion failed: " << t << " != " << u
            << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
                {"a", {"b"}},
                {"b", {"a"}},
        };
        AssertEqual(empty, expected, "Add to empty");
    }
    {
        Synonyms synonyms = {
                {"a", {"b"}},
                {"b", {"a", "c"}},
                {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
                {"a", {"b", "c"}},
                {"b", {"a", "c"}},
                {"c", {"b", "a"}}

        };
        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestCount() {
    {
        Synonyms empty;
        AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        AssertEqual(GetSynonymCount(synonyms, "a"), 2u, "count for a");
        AssertEqual(GetSynonymCount(synonyms, "b"), 1u, "count for b");
        AssertEqual(GetSynonymCount(synonyms, "z"), 0u, "count for z");
    }
}

void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "synonyms a b");
        Assert(AreSynonyms(synonyms, "b", "a"), "synonyms b a");
        Assert(AreSynonyms(synonyms, "a", "c"), "synonyms a c");
        Assert(AreSynonyms(synonyms, "c", "a"), "synonyms c a");
        Assert(!AreSynonyms(synonyms, "b", "c"), "synonyms b c");
        Assert(!AreSynonyms(synonyms, "c", "b"), "synonyms c b");
    }
}

class TestRunner {
public:
    template <class TestFunc> // Функция ловит ошибки в юнит-тестировании, и выводит в консоль.
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");

}

int main() {
    TestAll();

    int q;
    cin >> q;

    map<string, set<string>> synonyms;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            AddSynonyms(synonyms, word1, word2);
        } else if (operation_code == "COUNT") {
            string word;
            cin >> word;
            cout << GetSynonymCount(synonyms, word) << endl;
        } else if (operation_code == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (AreSynonyms(synonyms, word1, word2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

//template <class T>
//T Sum(T x, T y) {
//    return x + y;
//}
//
//void TestSUM() {
//    assert(Sum(2, 3) == 5);
//    assert(Sum(-2, -3) == -5);
//    assert(Sum(-2, 0) == -2);
//    assert(Sum(-2, 2) == 0);
//    assert(Sum(2.3, 4.8) == 7.1);
//    cout << "TestSum OK" << endl;
//}
//
//
//int main() {
//    TestSUM();
//    return 0;
//}