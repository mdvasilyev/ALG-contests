#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
using namespace std;


struct Position {
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
};

bool valid_pos (int x, int y) {
    return (x >= 0 && x <= 7 && y >= 0 && y <= 7);
}

vector<Position> solve(Position start, Position end) {
    int shift_x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int shift_y[] = {1, 2, 2, 1, -1, -2, -2, -1};

    queue<pair<Position, vector<Position>>> q;

    vector<vector<bool>> vis(8, vector<bool>(8, false));

    q.push({start, {start}});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        Position pos = cur.first;
        vector<Position> path = cur.second;

        if (pos.x == end.x && pos.y == end.y) {
            return path;
        }

        for (int i = 0; i < 8; ++i) {
            int new_x = pos.x + shift_x[i];
            int new_y = pos.y + shift_y[i];

            if (valid_pos(new_x, new_y) && !vis[new_x][new_y]) {
                vis[new_x][new_y] = true;
                vector<Position> new_path = path;
                new_path.push_back({new_x, new_y});
                q.push({{new_x, new_y}, new_path});
            }
        }
    }
}

int main() {
    string start_str, end_str;
    cin >> start_str >> end_str;
    char start_x, start_y, end_x, end_y;
    start_x = start_str.c_str()[0];
    start_y = start_str.c_str()[1];
    end_x = end_str.c_str()[0];
    end_y = end_str.c_str()[1];

    int startX = start_x - 'a';
    int startY = start_y - '1';
    int endX = end_x - 'a';
    int endY = end_y - '1';

    Position start(startX, startY);
    Position end(endX, endY);

    vector<Position> path = solve(start, end);

    for (auto pos : path) {
        char x_pos = pos.x + 'a';
        char y_pos = pos.y + '1';
        cout << x_pos << y_pos << endl;
    }
}