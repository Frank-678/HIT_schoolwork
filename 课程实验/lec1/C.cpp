#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }

    bool can_delete = false;
    bool can_on;
    for (int i = 0; i < n; i++) { // 枚举删哪一行
        if (can_delete) {
            cout << "YES" << endl;
            break;
        }

        can_on = true;  // 关键：先让列循环能进去

        for (int l = 0; l < m; l++) { // 检查每一列
            can_on = false;           // 关键：重新判断这一列是否还能亮

            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (v[j][l] == '1') {
                    can_on = true;
                    break;
                }
            }

            if (!can_on) { // 这一列灭了，说明第 i 行不能删
                break;
            }

            if (l == m - 1 && can_on) {
                can_delete = true;
            }
        }

        if (i == n - 1 && !can_delete) {
            cout << "NO" << endl;
            break;
        }
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <string>
// using namespace std;

// int main() {
//     int m, n;
//     cin >> m >> n;
//     string s;
//     vector<string> v;
//     for (int i = 0; i < m; i++) {
//         cin >> s;
//         v.push_back(s);
//     }
//     for (int j = 0; j < v.size(); j++) { //string
//         for (int i = 0; i < n; i++) { //char
//             if (v[j][i] == '1') {
//                 int hasLight = false;
//                 for (int k = 0; k < v.size(); k++) { //string
//                     if (k != j && v[k][i] == '1') {
//                         hasLight = true;
//                     }
//                 }
//                 if (!hasLight) {
//                     cout << "NO" << flush;
//                     exit(0);
//                 }
//             }
//         }
//     }
//     cout << "YES" << flush;
//     return 0;
// }