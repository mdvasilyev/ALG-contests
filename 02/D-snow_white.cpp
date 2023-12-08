#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


struct Dwarf {
    unsigned long a;
    unsigned long b;
    unsigned id;
};


void process_dwarfs(vector<Dwarf>& dwarfs, unsigned long long& cradle_time, unsigned& size, vector<unsigned>& res) {
    sort(dwarfs.begin(), dwarfs.end(), [](const Dwarf& fst, const Dwarf& snd){ return snd.a + snd.b < fst.a + fst.b; });
    for (Dwarf& d : dwarfs) {
        if (d.b + d.a > cradle_time) {
            cradle_time -= d.a;
            ++size;
            res.push_back(d.id);
        } else {
            break;
        }
    }
}


int main() {
    unsigned n;
    unsigned long long cradle_time = 0;
    unsigned size = 0;
    cin >> n;
    vector<Dwarf> dwarfs(n);
    vector<unsigned> res;
    for (size_t i = 0; i < n; ++i) {
        cin >> dwarfs[i].a;
        cradle_time += dwarfs[i].a;
        dwarfs[i].id = i + 1;
    }
    for (size_t i = 0; i < n; ++i) {
        cin >> dwarfs[i].b;
    }

    process_dwarfs(dwarfs, cradle_time, size, res);

    if (size == n) {
        for (auto t : res) {
            cout << t << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
