/*
    因为结束得越早，给后面的比赛留下的时间就越多，所以不会比选一个结束更晚的更差。
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int start;
    int end;
} contest;

bool cmp(contest a, contest b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<contest> v(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i].start >> v[i].end;
    }
    sort(v.begin(), v.end(), cmp);
    int count = 1;
    int last_time = v[0].end;
    for (int i = 0; i < n; i++) {
        if (v[i].start >= last_time) {
            count++;
            last_time = v[i].end;
        }
    }
    cout << count << endl;
    return 0;
}