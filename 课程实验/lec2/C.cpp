#include <iostream>
#include <vector>
using namespace std;


int main() {
    int L, M ,N;
    cin >> L >> N >> M;
    vector<int> d;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        d.push_back(in);
    }

    /*
    二分一个“最短跳跃距离” x：

    判断是否能通过删除不超过 M 块石头，让所有相邻跳跃距离都 >= x

    如果可以，说明 x 还能更大

    如果不行，说明 x 太大了
    */

    // x 的范围是 [1, L]
    int left = 1, right = L;
    while (left < right) {
        int mid = left + (right - left) / 2;

        // 判断是否能通过删除不超过 M 块石头，让所有相邻跳跃距离都 >= mid
        int last = 0; // 上一个石头的位置
        int removed = 0; // 已经删除的石头数量
        for (int i = 0; i < N; i++) {
            if (d[i] - last < mid) {
                // 跳跃距离太小，需要删除这个石头
                removed++;
            } else {
                // 跳跃距离足够，更新上一个石头的位置
                last = d[i];
            }
        }
        // 最后还要考虑从最后一个石头跳到终点的距离
        if (L - last < mid) {
            removed++;
        }

        if (removed <= M) {
            // 可以通过删除不超过 M 块石头让所有相邻跳跃距离都 >= mid
            left = mid + 1; // x 还能更大
        } else {
            right = mid; // x 太大了
        }
    }
    cout << left - 1 << endl; // 输出最大的最短跳跃距离
}