// 下面几乎是错误的。

#include <bits/stdc++.h>
using namespace std;
int n, k, A, B;
vector<int> a; // 这里决不能（k）
vector<long long> ans;
void dfs(int left, int right, long long cost) {

    
    if (left == right) {
        long long more = a[left] ? (pow(2,left) * B*a[left]) : A;
        ans.push_back(cost + more);
    }
    dfs(left, (left+right)/2, cost);
    dfs((left+right)/2, right, cost);
    int people = 0;
    for (int i = left; i <= right; i++) {
        people += a[i];
    }
    long long more = people ? pow(2,(right - left + 1)) * B * people : A;   // C++中^是异或不是幂运算！
    ans.push_back(cost + more);
}

int main() {
    
    cin >> n >> k >> A >> B;
    
    for (size_t i = 0; i < k; i++)
    {
        int c;
        cin >> c;  //第i个复仇者在基地中的位置为a[i]
        a.push_back(c);
    }
    int left = 0;
    int right = k - 1;
    dfs(left, right, 0);
    long long min = LONG_LONG_MAX;
    for (long long i : ans) {
        if (i < min) {
            min = i;
        }
    }
    cout << min << endl;
}

