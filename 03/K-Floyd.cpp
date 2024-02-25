#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }

    vector<vector<int>> res(n, vector<int>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            res[i][j] = matrix[i][j];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                res[u][v] = min(res[u][v], res[u][i] + res[i][v]);
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}