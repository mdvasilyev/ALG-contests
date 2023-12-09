#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    unsigned n, m, res = 0;
    vector<pair<unsigned, unsigned>> edges;
    vector<unsigned> path;
    cin >> n >> m;
    for (size_t i = 0; i < m; ++i) {
        pair<unsigned, unsigned> tmp;
        cin >> tmp.first >> tmp.second;
        edges.push_back(tmp);
    }

    cout << res << endl;
    for (auto p : path) {
        cout << p << ' ';
    }
    cout << endl;

    return 0;
}