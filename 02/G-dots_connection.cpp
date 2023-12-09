#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Point {
    int x;
    int y;
    unsigned id;
    bool in_mst;
};


struct Edge {
    Point a;
    Point b;
    double length;
};


double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


void process_points(unsigned& mst_edges, vector<Point>& points, unsigned& cur_point, vector<Edge>& edges, double& mst_len) {
    auto compare_edge = [](const Edge& fst, const Edge& snd){
        return fst.length > snd.length; };
    priority_queue<Edge, vector<Edge>, decltype(compare_edge)> pq;
    while (++mst_edges < points.size()) {
        points[cur_point].in_mst = true;
        for (size_t next_point = 0; next_point < points.size(); ++next_point) {
            if (!points[next_point].in_mst) {
                Edge tmp;
                tmp.a = points[cur_point];
                tmp.b = points[next_point];
                tmp.length = distance(tmp.a, tmp.b);
                pq.push(tmp);
            }
        }
        while (points[pq.top().b.id - 1].in_mst) {
            pq.pop();
        }
        edges.push_back(pq.top());
        mst_len += pq.top().length;
        points[edges.back().b.id - 1].in_mst = true;
        edges.back().b.in_mst = true;
        cur_point = pq.top().b.id - 1;
        pq.pop();
    }
}

int main(){
    unsigned n;
    unsigned mst_edges = 0, cur_point = 0;
    double mst_len = 0.0;
    cin >> n;
    vector<Point> points;
    vector<Edge> edges;
    for(size_t i = 0; i < n; ++i) {
        Point tmp;
        cin >> tmp.x >> tmp.y;
        tmp.id = i + 1;
        tmp.in_mst = false;
        points.push_back(tmp);
    }

    process_points(mst_edges, points, cur_point, edges, mst_len);
    
    cout << fixed << setprecision(6) << mst_len << endl;
    cout << mst_edges - 1 << endl;
    for (auto e : edges) {
        cout << e.a.id << ' ' << e.b.id << endl;
    }

    return 0;
}
