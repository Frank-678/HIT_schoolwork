#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, N, M;
    cin >> L >> N >> M;

    vector<int> d;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        d.push_back(in);
    }

    int left = 1, right = L;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int last = 0;      // 上一个保留的石头位置
        int removed = 0;   // 删除的石头数量

        for (int i = 0; i < N; i++) {
            if (d[i] - last < mid) {
                removed++;
            } else {
                last = d[i];
            }
        }

        if (L - last < mid) {
            removed++;
        }

        if (removed <= M) {
            ans = mid;         // mid 可行
            left = mid + 1;    // 继续尝试更大
        } else {
            right = mid - 1;   // mid 不可行
        }
    }

    cout << ans << endl;
    return 0;
}