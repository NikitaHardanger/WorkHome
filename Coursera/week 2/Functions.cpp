#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* First Example
 * int Sum(int x, int y) {
    return x+y;
}
 */
bool Contains(vector<string> words, string w) {
    for (auto s : words) {
        if (s == w) {
            return true;
        }
    }
    return false;
}

int main() {
    /* First example
     * int x,y;
    cin >> x >> y;
    cout << Sum(x, y);
     */
    cout << Contains({"Polar bear", "Cat", "Masha", "Koala"}, "Masha");
    return 0;
}