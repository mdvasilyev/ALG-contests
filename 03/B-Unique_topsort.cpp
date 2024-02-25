#include <cstdio>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    deque<int> q;
    vector<vector<int>> graph(n + 1);
    graph.resize(n + 1);
    for (size_t i = 0; i < n + 1; ++i) {
        graph[i].clear();
    }
    vector<int> in_deg(n + 1, 0);
    vector<int> res(n + 1);
    res.clear();

    for (size_t i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        ++in_deg[to];
    }

    for (size_t i = 1; i < n + 1; ++i) {
        if (in_deg[i] == 0) {
            q.push_back(i);
        }
    }

    bool unique = true;

    while (!q.empty()) {
        if (q.size() > 1) {
            unique = false;
        }
        int cur = q.front();
        q.pop_front();
        for (size_t i = 0; i < graph[cur].size(); ++i) {
            if (!graph[cur].empty()) { 
                int to = graph[cur][i];
                --in_deg[to];
                if (in_deg[to] == 0) {
                    q.push_back(to);
                }
            }
        }
        res.push_back(cur);
    }

    if (unique) {
        cout << "YES" << endl;
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}