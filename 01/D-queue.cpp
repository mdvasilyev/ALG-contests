#include <iostream>
#include <map>
#include <queue>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    // maps a_i and counter
    std::map<int, int> items;
    // queues a_i and t_i
    std::queue<std::pair<int, int>> customers;
    std::vector<int> waitings;
    for (int i = 0; i < n; ++i)
    {
        int type, time, item;
        std::cin >> type >> time >> item;
        if (type == 1)
        {
            ++items[item];
            while (!customers.empty() && items[customers.front().second] > 0)
            {
                waitings.push_back(time - customers.front().first);
                --items[customers.front().second];
                customers.pop();
            }
        }
        else if (type == 2)
        {
            if (customers.empty() && (items[item] > 0))
            {
                waitings.push_back(0);
                --items[item];
            }
            else { customers.push({time, item}); }
        }
    }
    while (!customers.empty())
    {
        customers.pop();
        waitings.push_back(-1);
    }
    for (int i = 0; i < waitings.size(); ++i)
        std::cout << waitings[i] << ' ';
    std::cout << std::endl;
    return 0;
}