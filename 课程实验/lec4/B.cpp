#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
    int x, y;
} Location;

vector<Location> getmoves(Location p) {
    vector<Location> v;
    Location new_;
    new_.x = p.x;
    new_.y = p.y - 1;
    v.push_back(v)
}

void dfs(const vector<int>& board, Location current, const Location& end, int cost, vector<Location> path) {
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    Location start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    vector<Location> path;
    dfs(board, start, end, 0, path);
}