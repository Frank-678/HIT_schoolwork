#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>   // gcd
using namespace std;

void fractionInside(int a, int b, int c, int d, int n) {
    // a/b < c/d => a/b < a+c/b+d < c/d
    if (b + d > n) return;
    // fraction middle = (a + c) / (b + d)
    fractionInside(a, b, a + c, b + d, n);
    cout << a + c << '/' << b + d << endl;
    fractionInside(a + c, b + d, c, d, n);
    
}

void fractions(int n) {
    cout << "0/1" << endl;
    fractionInside(0, 1, 1, 1, n);
    cout << "1/1" << endl;
}

int main() {
    int n;
    cin >> n;
    fractions(n);
}