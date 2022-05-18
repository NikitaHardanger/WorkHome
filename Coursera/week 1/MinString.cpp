#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
//    vector<int> nums = {1, 5, 2, 3, 5};
//    int q = count(begin(nums), end(nums), 5);
//
//    cout << q ;

//    int x, y;
//    cin >> x >> y;
//    cout << x+y;
//    return 0;
      string a, b, c;
      cin >> a >> b >> c;
      if (a <= b && a <= c) {
          cout << a;
      } else if (b <= a && b <= c) {
          cout << b;
      } else {
          cout << c;
      }
     return 0;
}