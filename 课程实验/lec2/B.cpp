#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, m;
vector<int> a, b;

double check(double fuel) {
    double x = fuel;
    x = x - (m + x) / a[1];
    for (int i = 2; i <= n; i++) {
        x = x - (m + x) / a[i];
        x = x - (m + x) / b[i];
    }
    x = x - (m + x) / b[1];
    return x;
}

int main() {
    cin >> n >> m;
    a = vector<int>(n + 1);
    b = vector<int>(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    if (check(1e9) < 0) {
        cout << -1 << endl;
        return 0;
    }

    double left = 0, right = 1e9;
    for (int i = 0; i < 200; i++) {
        double mid = (left + right) / 2;
        if (check(mid) < 0) left = mid;
        else right = mid;
    }

    cout << fixed << setprecision(10) << right << endl;
}