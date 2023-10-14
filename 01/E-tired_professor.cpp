#include <iostream>
#include <deque>

std::deque<unsigned int> processDeque(std::deque<unsigned int> a, unsigned int n, unsigned int k, unsigned int prof_const)
{
    while (k != 0)
    {
        unsigned int x = a.front();
        unsigned int y = a.back();
        if (x < y) {
            a.pop_front();
            a.push_back((x + y) % prof_const);
        } else {
            a.pop_back();
            a.push_front((y - x) % prof_const);
        }
        k--;
    }
    return a;
}

int main()
{
    unsigned int prof_const = 1 << 30;
    unsigned int n, k;
    std::cin >> n >> k;
    std::deque<unsigned int> a;
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int num;
        std::cin >> num;
        a.push_back(num);
    }
    std::deque<unsigned int> arr = processDeque(a, n, k, prof_const);
    for (unsigned int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}