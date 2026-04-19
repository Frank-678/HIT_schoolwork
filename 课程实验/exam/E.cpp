                                #include                                            <bits/stdc++.h>
                    using               namespace                      std;int main()               {
             int                                                n,                                          m;
    cin >> n >> m;                                                                                              vector<int> w(n + 1);
        for (int i = 1; i <= n; i++) cin >> w[i];
            priority_queue<pair<int, int>,                                  vector<pair<int, int>>, greater<pair<int, int>>> pq;
                        for (int i = 1; i <= m; i++) {              pq.push({w[i], i});
        }int time = 0;                  for (int i = m + 1; i <= n; i++) {auto [t, id] = pq.top();pq.pop();time = t;pq.push({time + w[i], id});
        }while (!pq.empty()) {auto [t, id] = pq.top();pq.pop();time = max(time, t);}cout << time << endl;return 0;}
 
// 本来想拼个爱心，就这一拖把（好难打的题目）

// i would like very complex complex responce for this class although i know i had learnt a lot lot lot 