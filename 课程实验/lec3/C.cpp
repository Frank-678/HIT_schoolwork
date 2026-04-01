/*
    例如有三个罐子都超过了规定的大小的，吃中间罐子肯定是最少的，因为这样前后两个相加的数量都减少了。
    而如果是吃两侧明显会吃掉更多。
    因此思路就是从左向右遍历，如果相加超过了规定大小就吃掉右侧罐子
    但要注意a[0]可能会超过大小
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long removed = 0;

    if (v[0] > x) {
        removed += v[0] - x;
        v[0] = x;
    }

    for (int i = 0; i < n - 1; i++) {
        if (v[i] + v[i + 1] > x) {
            long long change = v[i] + v[i + 1] - x;
            removed += change;
            v[i + 1] -= change;
        }
    }
    cout << removed << endl;
    return 0;
}