#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Authority
{
    long long a;
    long long b;
    unsigned long id;
    bool in_band;
};


void process_pos_influencers(vector<Authority>& pos_influence, long long& respect, unsigned long& size) {
    sort(pos_influence.begin(), pos_influence.end(), [](const Authority& fst, const Authority& snd){ return fst.a < snd.a; });
    for (Authority& auth : pos_influence) {
        if (respect >= auth.a) {
            respect += auth.b;
            ++size;
            auth.in_band = true;
        } else {
            break;
        }
    }
}


void process_neg_influencers(vector<Authority>& neg_influence, long long& respect, unsigned long& size) {
    sort(neg_influence.begin(), neg_influence.end(), [](const Authority& fst, const Authority& snd){ return snd.a + snd.b < fst.a + fst.b; });
    auto compare_b = [](Authority* fst, Authority* snd){ return fst->b > snd->b; };
    priority_queue<Authority*, vector<Authority*>, decltype(compare_b)> pq;
    for (Authority& auth : neg_influence) {
        if (respect >= auth.a) {
            respect += auth.b;
            ++size;
            auth.in_band = true;
            pq.push(&auth);
        } else {
            if (!pq.empty() && pq.top()->b < auth.b && respect - pq.top()->b >= auth.a) {
                respect -= pq.top()->b;
                pq.top()->in_band = false;
                pq.pop();
                respect += auth.b;
                auth.in_band = true;
                pq.push(&auth);
            }
        }
    }
}


int main() {
    unsigned long n;
    unsigned long size = 0;
    long long respect;
    cin >> n >> respect;
    vector<Authority> pos_influence;
    vector<Authority> neg_influence;
    
    for (size_t i = 0; i < n; ++i) {
        Authority tmp;
        cin >> tmp.a >> tmp.b;
        tmp.id = i + 1;
        tmp.in_band = false;
        if (tmp.b >= 0) {
            pos_influence.push_back(tmp);
        } else {
            neg_influence.push_back(tmp);
        }
    }

    process_pos_influencers(pos_influence, respect, size);
    process_neg_influencers(neg_influence, respect, size);

    cout << size << endl;
    for (Authority auth : pos_influence) {
        if (auth.in_band) {
            cout << auth.id << ' ';
        }
    }
    for (Authority auth : neg_influence) {
        if (auth.in_band) {
            cout << auth.id << ' ';
        }
    }
    cout << endl;

    return 0;
}
