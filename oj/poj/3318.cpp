/******************************************************************************
Link: http://poj.org/problem?id=3318
Code: 3318
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-19-22.23.50
*******************************************************************************/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

#define int long long

template <long long MOD = 1000000007>
struct Matrix {
    int n, m;
    vector<vector<long long> > a;

    Matrix(int _n = 0, int _m = 0) : n(_n), m(_m), a(_n, vector<long long>(_m, 0)) {}

    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; ++i) res.a[i][i] = 1;
        return res;
    }

    bool operator==(const Matrix& other) const {
        return n == other.n && m == other.m && a == other.a;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix res(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                res.a[i][j] = a[i][j] + other.a[i][j];
                if (MOD > 0 && res.a[i][j] >= MOD) res.a[i][j] -= MOD;
            }
        return res;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix res(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                res.a[i][j] = a[i][j] - other.a[i][j];
                if (MOD > 0 && res.a[i][j] < 0) res.a[i][j] += MOD;
            }
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                if (!a[i][k]) continue;
                for (int j = 0; j < other.m; ++j) {
                    res.a[i][j] += a[i][k] * other.a[k][j];
                    if (MOD > 0) res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix pow(long long p) const {
        Matrix res = identity(n), base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }

    friend istream& operator>>(istream& is, Matrix& M) {
        for (int i = 0; i < M.n; ++i)
            for (int j = 0; j < M.m; ++j)
                is >> M.a[i][j], MOD > 0 ? M.a[i][j] = (M.a[i][j] % MOD + MOD) % MOD : 0;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Matrix& M) {
        for (int i = 0; i < M.n; ++i)
            for (int j = 0; j < M.m; ++j)
                os << M.a[i][j] << " \n"[j + 1 == M.m];
        return os;
    }
};

int n;
Matrix<0> A, B, C;

bool check(){
    Matrix<0> r(n, 1);
    for(int i = 0; i < n; ++i)
        r.a[i][0] = rand() % 2;

    return A * (B * r) == C * r;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));

    while(cin >> n){
        A = Matrix<0>(n, n);
        B = Matrix<0>(n, n);
        C = Matrix<0>(n, n);

        cin >> A >> B >> C;

        bool ok = true;
        for(int c = 0; c < 30; ++c){
            if(!check()){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
