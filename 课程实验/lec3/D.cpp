#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int p, q;
} Farmer;

bool cmp(Farmer a, Farmer b) {
    return a.p < b.p;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Farmer> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].p >> v[i].q;
    }

    sort(v.begin(), v.end(), cmp);
    int cost = 0;
    int j = 0;
    while (n > 0) {
        if (v[j].q <= n) {
            n -= v[j].q;
            cost += v[j].p * v[j].q;
        } else {
            cost += n * v[j].p;
            n = 0;
        }
        j++;
    }
    cout << cost << endl;
    return 0;
}