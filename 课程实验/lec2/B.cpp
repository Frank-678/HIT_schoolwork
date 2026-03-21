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

    double left = 0, double right = 1e9;
    while (right) {
        int x = (left + right) / 2;

        x = x - (m + x) / a[1];
        for (int i = 2; i <= n; i++) {
            x = x - (m + x) / a[i];
            x = x - (m + x) / b[i]; 
            if (x <= 0) {
                left = x;
                continue;
            }
        }
        x = x - (m + x) / b[1];
        if (x < 0) {
            left = x;
        } else {
            right = x;
        }
    }

}
