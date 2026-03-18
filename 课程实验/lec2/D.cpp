#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

bool cmp (pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}

int main() {
    int n, m;
    cin >> n >> m;
    int k, s;
    vector<pair<int, int> > candidates;
    for (int i = 0; i < n; i++) {
        cin >> k >> s;
        candidates.push_back(make_pair(k, s));
    }
    sort(candidates.begin(), candidates.end(), cmp);

    int last_person = round(m * 1.5 - 0.5);
    int last_score = candidates[last_person].second;
    for (int i = 0; i < n; i++) {
        if (candidates[i].second < last_score) {
            cout << candidates[i].first << " " << candidates[i].second << endl;
            last_person = i - 1;
            break;
        }
    }
    cout << last_score << " " << last_person << endl;
    for (int i = 0; i < last_person;i++) {
        cout << candidates[i].first << " " << candidates[i].second << endl;
    }
    return 0;
}