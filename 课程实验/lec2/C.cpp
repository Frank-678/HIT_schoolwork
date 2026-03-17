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
        // 我们可以双指针遍历
        int m = 0;
        int last = 1;
        for (int kept = 0; last <= N; last++) {
            if (kept == 0 || D[0] < x) {
                kept++;
                last++;
            } 
            if (D[last] - D[kept] < x) {
                last++;
                m++;
            } else {
                kept = last;
                last++;
            }
        }
        if (L - D[last] < x) {
            m++;
        }


        if (m > M) {
            right = x - 1;
        } else if (m <= M) {  // 贪心
            ans = x;
            left = x + 1;
        } 
    }

    return 0;
}