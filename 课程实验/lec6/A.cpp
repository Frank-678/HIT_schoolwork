#include <bits/stdc++.h>
using namespace std;

int main() {
    int input;

    int current = -1;
    int bomb = 0;
    int max_bomb = 0;
    int system = 0;
    while (cin >> input) {
        if ((input) >= current) {
            system++;
            current = (input);
        } else {
            current = (input);
        }

        if (cin.peek() == '\n') {
            break;
        }
    }
    cout << max_bomb << endl << system << endl;
}