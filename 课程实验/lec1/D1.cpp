#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>   // gcd
using namespace std;

struct Fraction {
    int a, b;
};

bool cmp(const Fraction& x, const Fraction& y) {
    return x.a * y.b < y.a * x.b;
}

// 相比之下gcd 用的是欧几里得算法，核心是：gcd(a,b)=gcd(b,amodb)
// bool isRight(int j, int i) {
//     for (int k = 2; k <= j; k++) {
//         if (j % k == 0 && i % k == 0) return false;
//     }
//     return true;
// }

int main() {
    int n;
    cin >> n;
    vector<Fraction> v;
    for (int b = 1; b <= n; b++) {
        for (int a = 0; a <= b; a++) {
            if (gcd(a, b) == 1) {
                v.push_back({a, b});
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto f : v) {
        cout << f.a << "/" << f.b << endl;
    }    
    return 0;
}