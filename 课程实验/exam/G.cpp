还是好难……我的天。以前冬季的狼群是咋么殆尽的？不是冬天太久，就是暴风雪过于猛烈。
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto can = [&](long long x) {
        vector<long long> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + a[i - 1] * 1000LL - x;
        }
        long long min_pref = 0;
        for (int i = m; i <= n; i++) {
            min_pref = min(min_pref, prefix[i - m]);
            if (prefix[i] - min_pref >= 0) return true;
        }
        return false;
    };

    long long lo = 0, hi = 2000LL * 1000LL;
    long long ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) >> 1;
        if (can(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans;
    return 0;
}