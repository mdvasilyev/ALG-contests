// #include <algorithm>
#include <iostream>
#include <vector>


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int n, k;
    unsigned long val;
    std::vector<unsigned long> ropes;
    std::cin >> n >> k;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> val;
        ropes.push_back(val);
    }
    std::sort(ropes.begin(), ropes.end());
    unsigned long min_val = 0;
    unsigned long max_val = 1e7 + 1;
    unsigned long mid = 0;
    while (min_val + 1 < max_val)
    {
        val = 0;
        mid = min_val + (max_val - min_val) / 2;
        for (auto value : ropes)
            val += value / mid;
        if (val >= k)
            min_val = mid;
        else
            max_val = mid;
    }
    std::cout << min_val << std::endl;
    return 0;
}