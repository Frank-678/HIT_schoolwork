/*
    给定一个长度为 N 的 S/D 串，求有多少个长度为 2N 的合法括号序列 a，满足：

    a_i 和 a_{i+N} 相同，当且仅当 color[i] = S
    a_i 和 a_{i+N} 不同，当且仅当 color[i] = D
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printMagic(string s) {
    return;
}

int main() {
    int T;
    cin >> T;
    vector<string> v(T);
    for (size_t i = 0; i < T; i++)
    {
        cin >> v[i];
    }
    
    for (string s : v) {

        printMagic(s);


    }
}
