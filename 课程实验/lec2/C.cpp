#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, N, M;
    cin >> L >> N >> M;

    vector<int> D;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        D.push_back(in);
    }

    // TODO
    int ans = 0;
    int left = 0, right = L;
    while (left <= right) {
        int x = (left + right) / 2;


        // 我们要删：所有空隙小于x的，统计删m个
        // 我们从左往右遍历地删（因为删右面不会影响左面）
        int m = 0;
        int last = 0;
        for (int i = 0; i < N; i++) {
            if (D[i] - last < x) {
                m++;
            } else {
                last = D[i];
            }
        }
        if (L - last < x) {
            m++;
        }


        if (m > M) {
            right = x - 1;
        } else if (m <= M) {  // 贪心
            ans = x;
            left = x + 1;
        } 
    }
    cout << ans << endl;
    return 0;
}