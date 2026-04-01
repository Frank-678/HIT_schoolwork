#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort (h.begin(), h.end());
    long long energy = 0;
    int last_h = 0;
    while (h.size() > 0) {
        energy += (h[h.size() - 1] - last_h) * (h[h.size() - 1] - last_h);
        last_h = h[h.size() - 1];
        h.erase(h.begin() + h.size() - 1);
        
        if (h.size() > 0) {
            energy += (h[0] - last_h) * (h[0] - last_h);
            last_h = h[0];
            h.erase(h.begin());
        }
        
    }
    cout << energy << endl;
}