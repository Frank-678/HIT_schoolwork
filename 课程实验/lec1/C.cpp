#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    string s;
    vector<string> v;
    for (int i = 0; i < m; i++) {
        cin >> s;
        v.push_back(s);
    }

    for (int j = 0; j < v.size(); j++) {   // 假设删掉第 j 行
        bool canDelete = true;

        for (int i = 0; i < n; i++) {      // 枚举每一列
            if (v[j][i] == '1') {
                bool hasLight = false;
                for (int k = 0; k < v.size(); k++) {
                    if (k != j && v[k][i] == '1') {
                        hasLight = true;
                        break;
                    }
                }
                if (!hasLight) {
                    canDelete = false;
                    break;
                }
            }
        }

        if (canDelete) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
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