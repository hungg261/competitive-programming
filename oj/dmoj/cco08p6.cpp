/******************************************************************************
Link: https://dmoj.ca/problem/cco08p6
Code: cco08p6
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-15-11.00.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

typedef long long T;
const T EPS = 0;

struct Point {
    T x, y;
    int id;
    Point() : x(0), y(0), id(-1) {}
    Point(T _x, T _y, int _id = -1) : x(_x), y(_y), id(_id) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
    T dot(const Point& p) const { return x * p.x + y * p.y; }
    T norm2() const { return x * x + y * y; }
    bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

struct Edge {
    int id;
    Edge *rot, *nxt;
    Point org;
    bool del;
    Edge() : id(0), rot(nullptr), nxt(nullptr), del(false) {}
    Edge* rev() { return rot->rot; }
    Edge* lnext() { return rot->rev()->nxt->rot; }
    Edge* oprev() { return rot->nxt->rot; }
    Point dest() { return rev()->org; }
};

const int MAXE = 4000000;
Edge pool[MAXE];
int edge_ptr = 0;

Edge* make_edge(Point from, Point to) {
    Edge *e1 = &pool[edge_ptr++], *e2 = &pool[edge_ptr++];
    Edge *e3 = &pool[edge_ptr++], *e4 = &pool[edge_ptr++];
    e1->rot = e3; e2->rot = e4; e3->rot = e2; e4->rot = e1;
    e1->nxt = e1; e2->nxt = e2; e3->nxt = e4; e4->nxt = e3;
    e1->org = from; e2->org = to;
    e1->del = e2->del = e3->del = e4->del = false;
    return e1;
}

void splice(Edge* a, Edge* b) {
    Edge *alpha = a->nxt->rot, *beta = b->nxt->rot;
    Edge *t1 = b->nxt, *t2 = a->nxt, *t3 = beta->nxt, *t4 = alpha->nxt;
    a->nxt = t1; b->nxt = t2; alpha->nxt = t3; beta->nxt = t4;
}

Edge* connect(Edge* a, Edge* b) {
    Edge* e = make_edge(a->dest(), b->org);
    splice(e, a->lnext());
    splice(e->rev(), b);
    return e;
}

void delete_edge(Edge* e) {
    splice(e, e->oprev());
    splice(e->rev(), e->rev()->oprev());
    e->del = e->rev()->del = e->rot->del = e->rev()->rot->del = true;
}

bool right_of(Point p, Edge* e) { return e->org.cross(e->dest(), p) < -EPS; }
bool left_of(Point p, Edge* e) { return e->org.cross(e->dest(), p) > EPS; }

bool in_circle(Point a, Point b, Point c, Point d) {
    __int128 adx = a.x - d.x, ady = a.y - d.y;
    __int128 bdx = b.x - d.x, bdy = b.y - d.y;
    __int128 cdx = c.x - d.x, cdy = c.y - d.y;
    __int128 abdet = adx * bdy - bdx * ady;
    __int128 bcdet = bdx * cdy - cdx * bdy;
    __int128 cadet = cdx * ady - adx * cdy;
    __int128 alift = adx * adx + ady * ady;
    __int128 blift = bdx * bdx + bdy * bdy;
    __int128 clift = cdx * cdx + cdy * cdy;
    return alift * bcdet + blift * cadet + clift * abdet > EPS;
}

pair<Edge*, Edge*> build_delaunay(vector<Point>& pts, int l, int r) {
    if (r - l + 1 == 2) {
        Edge* a = make_edge(pts[l], pts[r]);
        return {a, a->rev()};
    }
    if (r - l + 1 == 3) {
        Edge* a = make_edge(pts[l], pts[l+1]);
        Edge* b = make_edge(pts[l+1], pts[r]);
        splice(a->rev(), b);
        T cr = pts[l].cross(pts[l+1], pts[r]);
        if (cr > EPS) {
            connect(b, a);
            return {a, b->rev()};
        } else if (cr < -EPS) {
            Edge* c = connect(b, a);
            return {c->rev(), c};
        } else {
            return {a, b->rev()};
        }
    }
    int mid = (l + r) / 2;
    Edge *ldo, *ldi, *rdi, *rdo;
    tie(ldo, ldi) = build_delaunay(pts, l, mid);
    tie(rdi, rdo) = build_delaunay(pts, mid + 1, r);

    while (true) {
        if (left_of(rdi->org, ldi)) ldi = ldi->lnext();
        else if (right_of(ldi->org, rdi)) rdi = rdi->rev()->nxt;
        else break;
    }

    Edge* basel = connect(rdi->rev(), ldi);
    if (ldi->org == ldo->org) ldo = basel->rev();
    if (rdi->org == rdo->org) rdo = basel;

    while (true) {
        Edge* lcand = basel->rev()->nxt;
        if (right_of(lcand->dest(), basel)) {
            while (in_circle(basel->dest(), basel->org, lcand->dest(), lcand->nxt->dest())) {
                Edge* t = lcand->nxt;
                delete_edge(lcand);
                lcand = t;
            }
        }
        Edge* rcand = basel->oprev();
        if (right_of(rcand->dest(), basel)) {
            while (in_circle(basel->dest(), basel->org, rcand->dest(), rcand->oprev()->dest())) {
                Edge* t = rcand->oprev();
                delete_edge(rcand);
                rcand = t;
            }
        }
        bool lvalid = right_of(lcand->dest(), basel);
        bool rvalid = right_of(rcand->dest(), basel);
        if (!lvalid && !rvalid) break;
        if (!lvalid || (rvalid && in_circle(lcand->dest(), lcand->org, rcand->org, rcand->dest()))) {
            basel = connect(rcand, basel->rev());
        } else {
            basel = connect(basel->rev(), lcand->rev());
        }
    }
    return {ldo, rdo};
}

vector<array<int, 3>> get_delaunay_triangles(vector<Point> pts) {
    if (pts.size() < 3) return {};
    edge_ptr = 0;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    build_delaunay(pts, 0, (int)pts.size() - 1);

    vector<array<int, 3>> tris;
    for (int i = 0; i < edge_ptr; i += 4) {
        Edge* e = &pool[i];
        if (e->del) continue;
        for (int j = 0; j < 2; ++j) {
            Edge* curr = (j == 0 ? e : e->rev());
            Edge* nxt = curr->lnext();
            if (nxt->lnext()->lnext() == curr) {
                if (curr->org.cross(nxt->org, nxt->lnext()->org) > EPS) {
                    array<int, 3> t = {curr->org.id, nxt->org.id, nxt->lnext()->org.id};
                    sort(t.begin(), t.end());
                    tris.push_back(t);
                }
            }
        }
    }
    sort(tris.begin(), tris.end());
    tris.erase(unique(tris.begin(), tris.end()), tris.end());
    return tris;
}

pair<double, double> get_circumcenter(Point a, Point b, Point c) {
    double D = 2.0 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    double a2 = a.norm2(), b2 = b.norm2(), c2 = c.norm2();
    double cx = (a2 * (b.y - c.y) + b2 * (c.y - a.y) + c2 * (a.y - b.y)) / D;
    double cy = (a2 * (c.x - b.x) + b2 * (a.x - c.x) + c2 * (b.x - a.x)) / D;
    return {cx, cy};
}

double get_circumradius(Point A, Point B, Point C) {
    double AB = sqrt((double)(B - A).norm2());
    double BC = sqrt((double)(C - B).norm2());
    double CA = sqrt((double)(A - C).norm2());

    double denominator = 2.0 * abs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
    if (denominator < 1e-9) return -1.0;

    return (AB * BC * CA) / denominator;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<Point> pts(n);
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        pts[i] = {x, y, i};
    }

    double res = -1.0;
    for(const auto &p: get_delaunay_triangles(pts)){
        res = max(res, get_circumradius(pts[p[0]], pts[p[1]], pts[p[2]]));
    }

    cout << fixed << setprecision(10) << res << "\n";

    return 0;
}
