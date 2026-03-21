#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a = {0}; // 从1开始
    vector<int> b = {0};
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        a.push_back(in);
    }
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        b.push_back(in);
    }
}