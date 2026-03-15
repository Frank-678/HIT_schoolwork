#include <iostream>
#include <vector>
using namespace std;


int main() {
    int L, M ,N;
    cin >> L >> N >> M;
    vector<int> d;
    int in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        d.push_back(in);
    }

    /*
    二分一个“最短跳跃距离” x：

    判断是否能通过删除不超过 M 块石头，让所有相邻跳跃距离都 >= x

    如果可以，说明 x 还能更大

    如果不行，说明 x 太大了
    */

    // x 的范围是 [1, L]
    int left = 1, right = L;
    
}