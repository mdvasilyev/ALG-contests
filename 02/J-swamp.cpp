#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

constexpr double INFINITY_DISTANCE = numeric_limits<double>::infinity();

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double max_edge(int h, int n, vector<pair<int, int>> pts) {
    int N = n + 2;
    int edges = 0;
    vector<vector<double>> matrix(n + 2, vector<double>(n + 2, 0));
    vector<bool> choose(N, false);
    choose[0] = true;
    vector<double> max_edges;
    matrix[0][n + 1] = matrix[n + 1][0] = h;

    for (int i = 1; i <= n; ++i) {
        matrix[i][n + 1] = matrix[n + 1][i] = h - pts[i - 1].second;
        matrix[0][i] = matrix[i][0] = pts[i - 1].second;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            matrix[i][j] = distance(pts[i - 1].first, pts[i - 1].second, pts[j - 1].first, pts[j - 1].second);
        }
    }

    vector<vector<double>> graph = matrix;

    while (edges < N - 1) {
        int a, b;
        double min_dist = INFINITY_DISTANCE;

        for (int m = 0; m < N; ++m) {
            if (choose[m]) {
                for (int n = 0; n < N; ++n) {
                    if (!choose[n] && graph[m][n] < min_dist) {
                        min_dist = graph[m][n];
                        a = m;
                        b = n;
                    }
                }
            }
        }

        choose[b] = true;
        edges += 1;
        max_edges.push_back(graph[a][b]);

        if (b == N - 1) {
            break;
        }
    }

    return *max_element(max_edges.begin(), max_edges.end());
}

int main() {
    int h, n;

    cin >> h >> n;
    vector<pair<int, int>> points;

    for (int i = 0; i < n; ++i) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        points.push_back(tmp);
    }

    double res = max_edge(h, n, points);
    cout << fixed << setprecision(9) << res << endl;

    return 0;
}
