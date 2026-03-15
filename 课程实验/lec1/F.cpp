#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
    计算第 n 个“广义丑数”

    参数：
    - primes: 给定的质数集合 S
    - n     : 要求第 n 个丑数

    返回值：
    - 第 n 个丑数（题目保证 32 位有符号整数能装下）
*/
int getNthUglyNumber(const vector<int>& primes, int n) {
    int k = primes.size();

    /*
        ugly[i] 的定义：

        ugly[i] = 第 i 个丑数
        但是这里我们人为设定：
            ugly[0] = 1

        注意：
        1 不是题目定义中的丑数，
        它只是一个“辅助起点”，便于统一递推写法。

        因此：
        - 第 1 个真正的丑数是 ugly[1]
        - 第 n 个真正的丑数是 ugly[n]
    */
    vector<long long> ugly(n + 1, 0);
    ugly[0] = 1;

    /*
        idx[j] 表示：
        对于第 j 个质数 primes[j]，
        当前应该乘到 ugly 的哪个位置上。

        于是第 j 个候选值就是：

            ugly[idx[j]] * primes[j]

        初始时所有 idx[j] 都为 0，
        所以最开始候选值就是：

            1 * primes[j]

        也就是说，最开始每个质数自己都会成为候选。
    */
    vector<int> idx(k, 0);

    /*
        从小到大生成 ugly[1], ugly[2], ..., ugly[n]

        每一步都做两件事：
        1. 找出当前最小候选值，作为新的丑数
        2. 把所有能产生这个值的指针都向前移动，避免重复
    */
    for (int i = 1; i <= n; i++) {
        long long nextUgly = LLONG_MAX;

        /*
            第一步：找出所有候选值中的最小值

            候选值公式：

                candidate_j = ugly[idx[j]] * primes[j]

            然后：

                ugly[i] = min(candidate_j)
        */
        for (int j = 0; j < k; j++) {
            long long candidate = ugly[idx[j]] * 1LL * primes[j];
            if (candidate < nextUgly) {
                nextUgly = candidate;
            }
        }

        /*
            把这个最小值记为第 i 个丑数
        */
        ugly[i] = nextUgly;

        /*
            第二步：去重

            如果多个质数都能得到同一个 nextUgly，
            那么这些质数对应的 idx 都要向前移动。

            例如：
                nextUgly = 6
            可能来自：
                2 * 3
                3 * 2

            如果只移动一个指针，下一轮还会再产生 6，
            于是就重复了。

            所以必须把所有满足下面等式的 j 都推进：

                ugly[idx[j]] * primes[j] == nextUgly
        */
        for (int j = 0; j < k; j++) {
            long long candidate = ugly[idx[j]] * 1LL * primes[j];
            if (candidate == nextUgly) {
                idx[j]++;
            }
        }
    }

    /*
        因为 ugly[0] = 1 是辅助项，不算真正丑数，
        所以第 n 个真正丑数就是 ugly[n]
    */
    return (int)ugly[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    cout << getNthUglyNumber(primes, n) << '\n';
    return 0;
}