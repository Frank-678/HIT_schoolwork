#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a = {0}; // 从1开始
    vector<int> b = {0};
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        a.push_back(in);
    }
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        b.push_back(in);
    }

    double left = 0, right = 1e9;
    double x;
    while (right - left >= 1e-6) {
        double mid = (left + right) / 2;
        x = mid;

        x = x - (m + x) / a[1];
        for (int i = 2; i <= n; i++) {
            x = x - (m + x) / a[i];
            x = x - (m + x) / b[i]; 
        }
        x = x - (m + x) / b[1];
        if (x < 0) {
            left = mid;
        } else {
            right = mid;  // ①
        }
    }

    if (right < 0) {
        cout << -1 << endl; //left = 当前已知的不可行最大值 right = 当前已知的可行最小值
    } else {
        cout << right << endl; // ②
    }
}

/*
    本题原先的失误在①和②两行。都是使用了变化后的x（注意这道题的x有变化）
*/