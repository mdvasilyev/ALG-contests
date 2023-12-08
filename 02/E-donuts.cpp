#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    unsigned n;
    unsigned k = 0;
    unsigned long w;
    vector<unsigned long> v;
    vector<unsigned long> res;
    cin >> n >> w;
    for (size_t i = 0; i < n; ++i) {
        unsigned long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    auto bound = v.end() - 1;
    while (w > 0) {
        if (*bound <= w) {
            w -= *bound;
            res.push_back(*bound);
            ++k;
        } else {
            --bound;
        }
    }
    cout << k << endl;
    for (auto value : res) {
        cout << value << ' ';
    }
    cout << endl;
    return 0;
}
