/******************************************************************************
Link: https://cses.fi/problemset/task/3427
Code: 3427
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-16-09.05.38
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Fraction{
    int a, b;

    Fraction() = default;
    Fraction(int _a, int _b = 1): a(_a), b(_b){ simplify(); }

    friend istream& operator >> (istream& is, Fraction& frac){
        return is >> frac.a >> frac.b;
    }

    friend ostream& operator << (ostream& os, const Fraction& frac){
        return os << frac.a << "/" << frac.b;
    }

    Fraction inverse() const { return Fraction(b, a); }

    Fraction simplified() const {
        int g = __gcd(a, b);
        return Fraction(a / g, b / g);
    }

    void simplify(){
        int g = __gcd(a, b);
        a /= g;
        b /= g;
    }

    int normalize(){
        assert(a % b == 0);
        return a / b;
    }

    bool operator == (const Fraction& other) const { return a * other.b == other.a * b; }
    bool operator != (const Fraction& other) const { return a * other.b != other.a * b; }
    bool operator < (const Fraction& other) const { return a * other.b < other.a * b; }
    bool operator > (const Fraction& other) const { return a * other.b > other.a * b; }
    bool operator <= (const Fraction& other) const { return *this < other || *this == other; }
    bool operator >= (const Fraction& other) const { return *this < other || *this == other; }
    Fraction operator - () const { return Fraction(-a, b); }

    Fraction operator + (const Fraction& other) const {
        int l = b / __gcd(b, other.b) * other.b;

        int a1 = a * l / b, a2 = other.a * l / other.b;
        return Fraction(a1 + a2, l).simplified();
    }

    Fraction operator - (const Fraction& other) const {
        return *this + Fraction(-other.a, other.b);
    }

    Fraction operator * (const Fraction& other) const {
        return Fraction(a * other.a, b * other.b).simplified();
    }

    Fraction operator / (const Fraction& other) const {
        return *this * other.inverse();
    }

    Fraction operator + (int other) const { return *this + Fraction(other); }
    Fraction operator - (int other) const { return *this - Fraction(other); }
    Fraction operator * (int other) const { return *this * Fraction(other); }
    Fraction operator / (int other) const { return *this / Fraction(other); }
};

struct Line{
    Fraction m, c;
    int idx;

    Line() = default;
    Line(int _m, int _c){
        m = Fraction(_m, 1);
        c = Fraction(_c, 1);
    }
    Line(int x1, int y1, int x2, int y2){
        m = Fraction(y2 - y1, x2 - x1);
        c = - m * x1 + y1;
    }

    Fraction f(int x) const { return m * x + c; }
    Fraction f(Fraction x) const { return m * x + c; }
    Fraction slope() const { return m; }

    pair<Fraction, Fraction> intersect(const Line& other) const {
        assert(m != other.m);

        Fraction x = Fraction(c - other.c) / Fraction(other.m - m);
        Fraction y = f(x);

        return {x, y};
    }

    bool operator == (const Line& other) const { return slope() == other.slope(); }
    bool operator < (const Line& other) const {
        return m < other.m || (m == other.m && c < other.c);
    }
    bool operator > (const Line& other) const {
        return m > other.m || (m == other.m && c > other.c);
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Line> l(n);
    for(int i = 0; i < n; ++i){
        int y1, y2;
        cin >> y1 >> y2;

        l[i] = Line(0, y1, m, y2);
        l[i].idx = i;
    }
    sort(begin(l), end(l));

    vector<int> sta;
    int sz = 0;
    for(int i = 0; i < n; ++i){
        while(sz >= 2){
            const Line& last1 = l[sta[sz - 1]];
            const Line& last2 = l[sta[sz - 2]];
            const Line& cur = l[i];

            if(last2.intersect(last1).second < last1.intersect(cur).second){
                sta.pop_back();
                --sz;
            }
            else break;
        }

        sta.push_back(i);
        ++sz;
    }

    int i = 0;
    for(int x = 0; x <= m; ++x){
        while(i + 1 < n && l[i].f(x) <= l[i + 1].f(x))
            ++i;

        cout << l[i].f(x).normalize() << " ";
    }

    return 0;
}
