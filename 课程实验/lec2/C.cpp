#include <iostream>
#include <vector>
using namespace std;

void removeStone(vector<int> v, int M) {
    int minlen = INT_MAX;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] + v[i+1] < minlen) {
            minlen = v[i] + v[i+1];
        }
    }
}

int main() {
    int L, M ,N;
    cin >> L >> M >> N;
    vector<int> d;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        d.push_back(in);
    }
    vector<int> nd; //空隙
    nd.push_back(d[0]);
    for (int i = 1; i <= N ; i++) 
    {
        nd.push_back(d[i] - d[i-1]);
    }
    nd.push_back(L-d[d.size()-1]);

    for (int i = 0; i < M; i++) {
        removeStone(nd, M);
    }
}