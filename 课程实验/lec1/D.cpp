#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Fraction {
    int a, b;
};

bool cmp(const Fraction& x, const Fraction& y) {
    return x.a * y.b < y.a * x.b;
}

bool isRight(int j, int i) {
    for (int k = 2; k <= j; k++) {
        if (j % k == 0 && i % k == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "0/1"  << endl;
    vector<Fraction> v;
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <= i; j++){
            if (isRight(j, i)) {
                v.push_back({j, i});
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto f : v) {
        cout << f.a << "/" << f.b << endl;
    }    
    return 0;
}