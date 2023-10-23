#include <algorithm>
#include <iostream>
#include <vector>

struct City
{
    long populatin;
    int num;

    City(long populatin = 0, int num = 0)
    {
        this->populatin = populatin;
        this->num = num;
    }
};

int sort_func(City a, City b)
{
    if (a.populatin == b.populatin)
        return a.num < b.num;
    else return a.populatin < b.populatin;
}

int query(const std::vector<City>& cities, int l, int r, int x)
{
    int left = std::lower_bound(cities.begin(), cities.end(), City(x, l), sort_func) - cities.begin();
    int right = std::upper_bound(cities.begin(), cities.end(), City(x, r), sort_func) - cities.begin();
    return left < right;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    int l, r;
    long val;
    std::cin >> n;
    std::vector<City> cities;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> val;
        cities.push_back(City(val, i + 1));
    }
    std::sort(cities.begin(), cities.end(), sort_func);
    std::cin >> q;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> l >> r >> val;
        std::cout << query(cities, l, r, val);
    }
    std::cout << std::endl;
}