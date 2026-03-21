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

    // TODO
    bool can_delete = false;
    bool can_on;
    for (int i = 0; i < n; i++) { // 关灯
        if (can_delete) {
            cout << "YES" << endl;
            break;
        }
        
        for (size_t l = 0; l < m; l++) // 纵向每一位
        {
            if (!can_on) {
                break;
            }
            can_on = false;
            for (int j = 0; j < n; j++) 
            {
                if (j == i) continue;
                if (v[j][l] - '0') can_on = true;
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