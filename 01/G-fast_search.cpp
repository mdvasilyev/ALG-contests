#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned int n, k;
    long long val, l, r;
    std::vector<long long> arr;
    std::vector<unsigned int> ans;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> val;
        arr.push_back(val);
    }
    std::sort(arr.begin(), arr.end());
    std::cin >> k;
    for (size_t i = 0; i < k; ++i)
    {
        std::cin >> l >> r;
        auto left = std::lower_bound(arr.begin(), arr.end(), l);
        auto right = std::upper_bound(arr.begin(), arr.end(), r);
        ans.push_back(right-left);
    }
    for (auto value : ans)
        std::cout << value << ' ';
    std::cout << std::endl;
    return 0;
}
