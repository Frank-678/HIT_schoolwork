#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int u, v, w;
} edge;

int main(void) {
    int n, m ,s;
    cin >> n >> m >> s;
    vector<edge> path;
    vector<int> dis(m, INT_MAX); vector<bool> vis(n, false);
    for (size_t i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        path.push_back({u, v, w});
    }
    
    

}