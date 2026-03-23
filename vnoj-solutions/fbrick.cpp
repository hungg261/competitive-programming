#include<bits/stdc++.h>
#define int long long
using namespace std;

int MOD = 1e9 + 7;

struct Matrix{
    static const int MAX = 100;
    int base[MAX][MAX];
    int n, m;

    Matrix() = default;
    Matrix(int n, int m){ this->n = n; this->m = m; memset(base, 0, sizeof base); }
    Matrix(int n, int m, vector<vector<int>> arr){
        this->n = n; this->m = m;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) base[i][j] = arr[i][j];
    }

    static Matrix Identity(int n){
        Matrix I(n, n);
        for(int i = 0; i < n; ++i) I[i][i] = 1;

        return I;
    }

    Matrix operator * (const Matrix& other) const{
        Matrix res(this->n, other.m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < other.m; ++j){
                for(int k = 0; k < m; ++k){
                    res[i][j] += (base[i][k] % MOD) * (other.base[k][j] % MOD) % MOD;
                    res[i][j] %= MOD;
                }
            }
        }

        return res;
    }

    Matrix operator ^ (int b) const{
        if(this->n != this->m) throw runtime_error("invalid");
        
        Matrix res = Identity(this->n);
        Matrix temp = *this;
        while(b > 0){
            if(b & 1) res = res * temp;
            temp = temp * temp;
            b >>= 1;
        }

        return res;
    }

    int* operator[] (int idx){
        return this->base[idx];
    }

    void output(){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cerr << base[i][j] << ' ';
            }
            cerr << '\n';
        }
    }
};

void solve(){
    int k, n, m;
    cin >> k >> n >> m;
    MOD = m;
    
    Matrix base(4, 4, {
        {0, 1, 0, 0},
        {1, 4*k*k, -4*k, 0},
        {0, 2*k, -1, 0},
        {0, 1, 0, 1}
    });
    Matrix vec(4, 1, {
        {1}, {k * k}, {k}, {1}
    });
    
    if(m == 1) cout << 1 << '\n';
    else{
        Matrix ans = (base ^ (n - 1)) * vec;
        cout << ((ans[3][0] % MOD) + MOD) % MOD << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}
