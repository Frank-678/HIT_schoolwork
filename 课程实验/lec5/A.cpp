#include <stdc++.h>

struct loc {
    int x, y;
};

int n;
vector<loc> v[10e6 + 10];

int main() {
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    
}