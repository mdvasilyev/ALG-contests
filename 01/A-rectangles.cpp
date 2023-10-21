#include <algorithm>
#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    long long res = (x2 - x1) * (y2 - y1);
    long long nextx1, nexty1, nextx2, nexty2;
    if (res == 0)
    {
        std::cout << res << std::endl;
        return 0;
    }
    for (int i = 1; i < n; ++i)
    {
        std::cin >> nextx1 >> nexty1 >> nextx2 >> nexty2;
        if (nextx1 == nextx2 || nexty1 == nexty2 || nextx1 >= x2 || nextx2 <= x1 || nexty1 >= y2 || nexty2 <= y1)
        {
            std::cout << 0 << std::endl;
            return 0;
        }
        x1 = std::max(x1, nextx1);
        x2 = std::min(x2, nextx2);
        y1 = std::max(y1, nexty1);
        y2 = std::min(y2, nexty2);
    }
    res = (x2 - x1) * (y2 - y1);
    std::cout << res << std::endl;
    return 0;
}
