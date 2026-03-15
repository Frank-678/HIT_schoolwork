#include <iostream>
#include <cmath>
using namespace std;

int divisorSum(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum+=i;
            if (i!=n/i && n/i != n) sum+=n/i; // 平方根重复
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    for (int A = n; ; A++) {
        int B = divisorSum(A);  // 这样的交互式，迭代一个就可以通过f(A)确定另一个。
        if (divisorSum(B) == A && B!=A) {
            cout << A << " " << B;
            break;
        }
    }

    return 0;
}







// #include <iostream>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <map>
// using namespace std;

// void divisor(int n, vector<int>& divisors) {
//     for (int i = 1; i < n/2; i++) {
//         if (n % i == 0) {
//             divisors.push_back(i);
//             if (n/i != n) divisors.push_back(n/i);
//         }
//     }
// }

// int divisorSum(int n) {
//     vector<int> divisors;
//     divisor(n, divisors);
//     int total = 0;
//     for (int i : divisors) {
//         total += i;
//     }
//     return total;
// }

// int main() {
//     int n;
//     cin >> n;

//     map<int, int> calculated;

//     for (int i = n; ;i++) {
//         int l = divisorSum(i);
//         if (calculated.count(l)) {
//             cout << calculated[l] << " " << i << flush;
//             break;
//         }

//         calculated[l] = i;


//     }

//     return 0;
// }