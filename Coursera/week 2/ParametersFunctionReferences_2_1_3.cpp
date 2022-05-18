#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//void Swap(int& x, int& y) {
//    int tmp = x;
//    x = y;
//    y = tmp;
//}

void Sort(vector<int>& v) {
    sort(begin(v), end(v));
}

int main() {
//    int a ;
//    int b ;
//    cin >> a >> b;
//    Swap(a, b);
//    cout << "a == " << a << '\n';
//    cout << "b == " << b << '\n';
    vector<int> nums = {3, 6, 1, 2, 0, 2};
    Sort(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
    return 0;
}