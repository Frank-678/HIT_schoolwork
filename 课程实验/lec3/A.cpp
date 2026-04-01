#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    vector<int> order;
    for (int j = 0; j < n; j++) {
        int min = INT_MAX;
        int i;
        int min_index;
        for (i = 0; i < n; i++) {
            if (T[i] < min && find(order.begin(), order.end(), i) == order.end()) {
                min = T[i];
                min_index = i;
            }
        }
        order.push_back(min_index);
        // 存入所有最小值
        for (int k = 0; k < n; k++) {
            if (T[k] == min && k != min_index
                && find(order.begin(), order.end(), k) == order.end()) {
                order.push_back(k);
                j++;
            }
        }
    }

    for (int i : order) {
        cout << i + 1 << " ";
    }
    cout << endl;

    long long all = 0;
    long long prefix = 0;
    for (int i = 0; i < n; i++) {
        all += prefix;
        prefix += T[order[i]];
    }
    double average = (double)all / n;
    cout << fixed << setprecision(2) << average << endl;
    return 0;
}