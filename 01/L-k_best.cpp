#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<long> w(n), v(n);
    std::vector<double> metric(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> v[i] >> w[i];

    double l, r, mid, total;
    l = 0;
    r = INT_MAX;
    while (r - l > 1e-6)
    {
        mid = l + (r - l) / 2;
        total = 0;
        for (size_t i = 0; i < n; ++i)
            metric[i] = v[i] - mid * w[i];
        std::sort(metric.rbegin(), metric.rend());
        for (size_t i = 0; i < k; ++i)
            total += metric[i];
        if (total >= 0)
            l = mid;
        else
            r = mid;
    }
    std::vector<std::pair<double, int>> res(n);
    for (size_t i = 0; i < n; ++i)
    {
        res[i].first = v[i] - l * w[i];
        res[i].second = -i;
    }
    std::sort(res.rbegin(), res.rend());
    for (size_t i = 0; i < k; ++i)
        std::cout << 1 - res[i].second << ' ';
    std::cout << std::endl;
}
