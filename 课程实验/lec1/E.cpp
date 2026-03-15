#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

/*
    把输入字符转成数字，便于处理

    约定：
    F -> 0   表示已经朝前
    B -> 1   表示朝后，需要被翻过来

    这样做的好处：
    一头牛如果被翻转 1 次，就相当于 0/1 互换
    只需要关心“被翻了奇数次还是偶数次”
*/
int toState(char c) {
    if (c == 'F') return 0;
    return 1; // c == 'B'
}

/*
    计算：当每次必须翻连续 K 头牛时，最少需要翻多少次

    参数：
    - cows[i] 表示第 i 头牛的初始状态
      0 = 朝前
      1 = 朝后
    - K 表示每次翻转的长度

    返回值：
    - 如果这个 K 可行，返回最少操作次数
    - 如果这个 K 不可行，返回 INT_MAX
*/
int getMinOperationsForK(const vector<int>& cows, int K) {
    int N = cows.size();

    /*
        flipStart[i] = 1 表示“在位置 i 开始翻一次”
        flipStart[i] = 0 表示“没有在位置 i 开始翻”

        注意：
        这里不是直接真的把后面 K 头牛全部改掉，
        而只是把“我从这里开始翻过一次”记下来。
    */
    vector<int> flipStart(N, 0);

    /*
        currentFlipEffect 表示：
        当前这头牛，受到了前面多少次翻转的影响

        只需要关心奇偶：
        - 偶数次：方向不变
        - 奇数次：方向翻转
    */
    int currentFlipEffect = 0;

    // 记录当前 K 下总共翻了多少次
    int operationCount = 0;

    /*
        从左到右处理每一头牛

        为什么必须从左到右？
        因为如果第 i 头牛现在还是朝后，
        那么以后只能从更右边开始翻，
        已经再也影响不到第 i 头牛了。
        所以在位置 i 的决定是“必须当场做”的。
    */
    for (int i = 0; i < N; i++) {

        /*
            如果 i >= K，说明有一段“很早之前开始的翻转”
            已经不再影响当前位置了，需要把它的影响去掉。

            例如 K = 3：
            如果在位置 2 开始翻，那么它只影响 2,3,4
            当走到 i = 5 时，这次翻转已经失效了。
        */
        if (i >= K) {
            currentFlipEffect -= flipStart[i - K];
        }

        /*
            计算第 i 头牛“当前真实方向”

            cows[i] 是原始方向
            currentFlipEffect 是它被前面翻了多少次

            如果 (cows[i] + currentFlipEffect) % 2 == 1
            说明它现在仍然朝后，需要处理
        */
        int currentDirection = (cows[i] + currentFlipEffect) % 2;

        /*
            如果这头牛现在朝后，那么必须在 i 这里开始翻一次

            因为：
            - 当前位置之前的翻转已经定了
            - 当前位置之后开始的翻转都不再包含第 i 头牛
            所以这是唯一选择
        */
        if (currentDirection == 1) {

            /*
                检查从 i 开始还能不能翻 K 头
                如果 i + K > N，说明越界，这个 K 不可行
            */
            if (i + K > N) {
                return INT_MAX;
            }

            /*
                在 i 这里开始翻一次
            */
            flipStart[i] = 1;
            currentFlipEffect++;
            operationCount++;
        }
    }

    return operationCount;
}

/*
    主流程：
    1. 读入数据
    2. 枚举 K = 1 ~ N
    3. 对每个 K 计算最少操作次数
    4. 找到操作次数最少的方案
*/
int main() {
    int N;
    cin >> N;

    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        cows[i] = toState(c);
    }

    int bestK = 1;
    int bestM = INT_MAX;

    /*
        枚举每一种翻转长度 K
    */
    for (int K = 1; K <= N; K++) {
        int operations = getMinOperationsForK(cows, K);

        /*
            只在这个 K 可行时，才尝试更新答案
        */
        if (operations < bestM) {
            bestM = operations;
            bestK = K;
        }
    }

    cout << bestK << " " << bestM << endl;
    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     vector<int> v;
//     char c;
//     for (size_t i = 0; i < N; i++)
//     {
//         int o = 0;
//         cin >> c;
//         if (c == 'F') o = 1;
//         v.push_back(o);
//     }

//     for (int K = 1; K <= N; K++) {
        
//         int M = 0;
//         while (find(v.begin(), v.end(), 0) != v.end()) {
//             auto i = find(v.begin(), v.end(), 0);
//             for (int p = 0; p < K; p++) {
//                 v[i+p] ^= 1;
//             }
//             M++;
//         }
//     }
    
// }