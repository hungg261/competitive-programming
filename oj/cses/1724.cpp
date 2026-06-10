#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
    credit: hungg261 (me)
    template nhan ma tran (v2)
*/
struct Matrix{
    static const int MAX_SIZE = 100;
    static const int mod = 1e9 + 7;

    int n, m;
    int self[MAX_SIZE][MAX_SIZE];

    Matrix() = default;
    Matrix(int n, int m){ this->n = n; this->m = m; memset(self, 0x3f, sizeof(self)); }
    Matrix(int n, int m, vector<vector<int>> mat){
        this->n = n;
        this->m = m;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                this->self[i][j] = mat[i][j];
            }
        }
    }

    static Matrix identity(int n, int m){
        assert(n == m);

        Matrix I(n, n);
        for(int i = 0; i < n; ++i){
            I[i][i] = 1;
        }

        return I;
    }

    Matrix operator * (const Matrix& other) const{
        assert(this->m == other.n);

        Matrix res(this->n, other.m);
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < other.m; ++j){
                for(int k = 0; k < this->m; ++k){
                    res[i][j] = min(res[i][j], this->self[i][k] + other[k][j]);
                }
            }
        }

        return res;
    }

    Matrix operator ^ (int b) const{
        if(b == 0) return identity(this->n, this->m);

        Matrix temp = *this;
        Matrix res = temp;
        --b;

        while(b > 0){
            if(b & 1) res = res * temp;
            temp = temp * temp;
            b >>= 1;
        }

        return res;
    }

    int* operator [] (int i){ return self[i]; }
    const int* operator[] (int i) const{ return self[i]; }

    void output(){
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < this->m; ++j){
                cerr << this->self[i][j] << ' ';
            }
            cerr << '\n';
        }
    }
};


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    Matrix dp(n, n);
    int LIMIT = dp[0][0];

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        --a; --b;
        dp[a][b] = min(dp[a][b], c);
    }

    dp = dp ^ k;
    cout << (dp[0][n - 1] != LIMIT ? dp[0][n - 1] : -1) << '\n';

    return 0;
}
