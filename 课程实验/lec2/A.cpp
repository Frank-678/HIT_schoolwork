

/*  Time limit
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    // 读入城市数量
    int N;
    cin >> N;

    // 每个城市用 pair<int,int> 存：
    // first  -> 城市坐标 x
    // second -> 人口 p
    vector<pair<int, int>> city;
    int X, P;
    for (int i = 0; i < N; i++) {
        cin >> X >> P;
        city.push_back(make_pair(X, P));
    }

    // TODO  加权中位数
    sort(city.begin(), city.end());
    // 所有坐标都是整数，加权中位数一定是整数
    int left = city[0].first, right = city[city.size() - 1].first;
    double ans;
    // 比较的是权重
    for (int x = left; x <= right; x++) {
        int population_left = 0, population_right = 0;
        for (const auto& [location, people] : city) {
            if (location <= x) {
                population_left += people;
            } else if (location > x) {
                population_right += people;
            }
        }
        if (population_left >= population_right) {
            ans = (double) x;
            break;
        }
    }

    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}

*/






// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iomanip>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<pair<int, int>> city(N);
//     long long total = 0;

//     for (int i = 0; i < N; i++) {
//         cin >> city[i].first >> city[i].second; // x, p
//         total += city[i].second;
//     }

//     sort(city.begin(), city.end());

//     long long prefix = 0;
//     double ans = 0;

//     for (int i = 0; i < N; i++) {
//         prefix += city[i].second;
//         if (prefix * 2 >= total) {
//             ans = city[i].first;
//             break;
//         }
//     }

//     cout << fixed << setprecision(5) << ans << endl;
//     return 0;
// }

// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int main() {
// //     //电视台x的范围，在最左与最右城市之间
// //     int N;
// //     cin >> N;
// //     map<int, int> m;  // 坐标：人口
// //     int a, b;
// //     for (int i =0;i<N;i++){
// //         cin >> a >> b;
// //         m[a] = b;
// //     }
// //     int minl = INT_MAX, maxl = INT_MIN;
// //     for (const auto& [l, p] : m) {
// //         if (l > maxl) maxl = l;
// //         if (l < minl) minl = l;
// //     }

// //     // x 在minl和maxl之间
// //     int left = minl, right = maxl;
// //     float vmax = 0;
// //     float vx;
// //     for () {

// //         int vv = 0;
// //         float x = left + (right - left) / 2;
    
// //         int vv = 0;
// //         for (const auto& [l, p] : m) {
// //             vv += abs(l-x) * p;
// //         }

// //         if (vv > vmin) {
// //             vx = x;
// //             vmax = vv;
// //         }
// //     }
// // }