#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unsigned long long int i = 1, binary = 0;
    while(N > 0) {
        binary += (N % 2) * i;
        N = N / 2;
        i *= 10;
    }

    cout << binary;
}