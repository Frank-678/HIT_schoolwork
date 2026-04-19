
#include <bits/stdc++.h>
using namespace std;

int fact[10];

int rankPerm(const array<int, 9> &a) {
    int r = 0;
    bool used[10] = {};
    for (int i = 0; i < 9; ++i) {
        int smaller = 0;
        for (int v = 1; v < a[i]; ++v) {
            if (!used[v]) ++smaller;
        }
        r += smaller * fact[8 - i];
        used[a[i]] = true;
    }
    return r;
}

void unrankPerm(int idx, array<int, 9> &a) {
    bool used[10] = {};
    for (int i = 0; i < 9; ++i) {
        int f = fact[8 - i];
        int order = idx / f;
        idx %= f;
        int cnt = 0;
        for (int v = 1; v <= 9; ++v) {
            if (used[v]) continue;
            if (cnt == order) {
                a[i] = v;
                used[v] = true;
                break;
            }
            ++cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < 10; ++i) fact[i] = fact[i - 1] * i;

    static int dist[362880];
    fill(dist, dist + 362880, -1);

    array<int, 9> start = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int startId = rankPerm(start);
    dist[startId] = 0;

    int moves[4][4] = {
        {0, 1, 4, 3},
        {1, 2, 5, 4},
        {3, 4, 7, 6},
        {4, 5, 8, 7}
    };

    deque<int> dq;
    dq.push_back(startId);

    while (!dq.empty()) {
        int curId = dq.front();
        dq.pop_front();
        array<int, 9> cur;
        unrankPerm(curId, cur);
        int curDist = dist[curId];

        for (int m = 0; m < 4; ++m) {
            array<int, 9> nxt = cur;
            for (int k = 0; k < 4; ++k) {
                nxt[moves[m][k]] = cur[moves[m][(k + 3) & 3]];
            }
            int nxtId = rankPerm(nxt);
            if (dist[nxtId] == -1) {
                dist[nxtId] = curDist + 1;
                dq.push_back(nxtId);
            }
        }
    }

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        array<int, 9> query;
        for (int i = 0; i < 9; ++i) {
            cin >> query[i];
        }
        int qid = rankPerm(query);
        cout << dist[qid] << '\n';
    }
    return 0;
}