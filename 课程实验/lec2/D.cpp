#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool cmp (pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int n, m;
    cin >> n >> m;
    int k, s;
    vector<pair<int, int> > candidates;
    for (int i = 0; i < n; i++) {
        candidates.push_back(make_pair(k, s));
    }
    sort(candidates.begin(), candidates.end(), cmp);

    int last_person = round(m * 1.5 + 0.5);
    
}