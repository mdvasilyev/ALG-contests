#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct Scholar {
    long long h;
    long long l;
    long long id;
    bool saved;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long n, pit_height, scholars_height = 0, saved_scholars = 0;
    cin >> n;
    vector<Scholar> scholars;
    for (size_t i = 0; i < n; ++i) {
        Scholar tmp;
        cin >> tmp.h >> tmp.l;
        tmp.saved = false;
        tmp.id = i + 1;
        scholars_height += tmp.h;
        scholars.push_back(tmp);
    }
    cin >> pit_height;

    sort(scholars.begin(), scholars.end(), [&](const Scholar& fst, const Scholar& snd){
        return fst.l + fst.h < snd.l + snd.h;
    });
    auto cmp = [](const decltype(scholars.begin())& fst, const decltype(scholars.begin())& snd){
        return fst->h < snd->h;
    };
    priority_queue<decltype(scholars.begin()), vector<decltype(scholars.begin())>, decltype(cmp)> ans;
    for (auto i = scholars.begin(); i != scholars.end(); ++i) {
        if (i->l >= pit_height - scholars_height) {
            ++saved_scholars;
            i->saved = true;
            ans.push(i);
            scholars_height -= i->h;
        } else if (!ans.empty() && i->h < ans.top()->h) {
            scholars_height = scholars_height + ans.top()->h - i->h;
            i->saved = true;
            ans.top()->saved = false;
            ans.pop();
            ans.push(i);
        }
    }

    cout << saved_scholars << endl;
    for (size_t i = 0; i < n; ++i) {
        if (scholars[i].saved) {
            cout << scholars[i].id << ' ';
        }
    }
    cout << endl;

    return 0;
}