#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int k;
    cin >> k;
    // int n = 0;  // 位数
    // for (int i = 1; i > k; ++i) {
    //     i *= 10;
    //     n++;
    // }

    for (int j = k; ;j++) {
        int sum = 0;
        string s = to_string(j);
        int len = s.length();
        for (int l = 0; l < len;l++) {
            sum += (int)(pow(s[l] - '0', len) + 1e-4); 
        }
        if (sum == j) {
            cout << j << flush;
            break;
        }
    }
    return 0;
}