/*
    高精度算法用于处理超出计算机基本数据类型（int，long long等）范围的大数字（如100位整数，高精度小数）的运算方法，本质就是用数组/字符串模拟手工计算。
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    int k;
    cin >> k;

    while (k > 0) { // 不容易想到
        int l = 0;
        while (l < (int)n.size() - 1 && n[l] <= n[l + 1]) {
            l++;
        }
        n.erase(l, 1);
        k--;
    }

    while (n[0] == '0' && n.size() > 1) {  // 不容易想到
        n.erase(0, 1);

    }
    cout << n << endl;
    return 0;
}
