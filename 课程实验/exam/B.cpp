// 不太会……？？

#include <bits/stdc++.h>
using namespace std;
int n;
using ll = long long
vector<ll> id;
int main() {
    cin >>n;
    for (size_t i = 0; i < n; i++)
    {
        ll l;
        cin >> ll;
        id.push(ll);
    }
    
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 关闭 C++ iostream 与 C stdio 的同步，以便 cin/cout 更快
    ios::sync_with_stdio(false);
    // 解除 cin 与 cout 的绑定，以减少输入输出时的额外 flush
    cin.tie(NULL);

    int n;
    // 读入元素个数
    cin >> n;
    // 用于保存 n 个长整型 id 值
    vector<ll> id(n);
    // 依次读取每个 id 值
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }

    // 如果只有一个元素或没有元素，最大值异或生成树的权值之和必然为 0
    if (n <= 1) {
        cout << 0;
        return 0;
    }

    // best[i] 表示当前已选节点集合到节点 i 的最大 XOR 权值
    vector<ll> best(n, 0);
    // used[i] 表示节点 i 是否已经被选入当前生成树
    vector<bool> used(n, false);
    // 记录结果，即最大生成树的总权值
    ll result = 0;

    // 从节点 0 开始构造最大生成树
    used[0] = true;
    // 初始化每个未选节点与节点 0 的 XOR 权值
    for (int i = 1; i < n; i++) {
        best[i] = id[0] ^ id[i];
    }

    // 需要再选 n-1 个节点加入生成树
    for (int iter = 1; iter < n; iter++) {
        int next = -1;
        ll maxEdge = 0;
        // 在所有未选节点中寻找与当前树连接时权值最大的节点
        for (int i = 0; i < n; i++) {
            if (!used[i] && best[i] > maxEdge) {
                maxEdge = best[i];
                next = i;
            }
        }
        // 将找到的节点选入生成树
        used[next] = true;
        // 将该最大边加入结果
        result += maxEdge;

        // 更新其余未选节点到当前生成树的最大 XOR 权值
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                ll weight = id[next] ^ id[j];
                if (weight > best[j]) {
                    best[j] = weight;
                }
            }
        }
    }

    // 输出最大生成树的总 XOR 权值
    cout << result;
    return 0;
}

