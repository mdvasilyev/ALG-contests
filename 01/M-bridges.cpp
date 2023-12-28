#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, a, y, b, l;
    cin >> x >> a >> y >> b >> l;

    int minimal = 0;
    int maximal = x * a + y * b + 1;

    while (minimal + 1 < maximal) {
        vector<vector<int>> matrix(x + 1, vector<int>(y + 1, 0));

        int average = (minimal + maximal) / 2;

        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                for (int k = 0; k <= i; ++k) {
                    int t = (average - k * a - 1) / b + 1;

                    if (average <= k * a) {
                        t = 0;
                    }
                    if (t <= j) {
                        matrix[i][j] = max(matrix[i][j], matrix[i - k][j - t] + 1);
                    }
                }
            }
        }

        if (matrix[x][y] >= l) {
            minimal = average;
        } else {
            maximal = average;
        }
    }

    cout << minimal << endl;

    return 0;
}
