#include<bits/stdc++.h>
#define int long long
using namespace std;
 
struct matrix{
    int n, m;
    int mod = 1e9 + 7;
    vector<vector<int>> self;
 
    void set_size(int n, int m, bool reset = false){
        if(reset){
            this->self.resize(n, vector<int>(m, 0));
        }
 
        this->n = n;
        this->m = m;
 
    }
 
    matrix() = default;
 
    matrix(int n, int m){
        set_size(n, m, true);
    }
 
    matrix(int n, int m, vector<vector<int>> new_matrix){
        this->self = new_matrix;
        set_size(n, m, false);
    }
 
    void set_identity(){
        if(this->n != this->m) return;
 
        set_size(this->n, this->m, true);
        for(int i = 0; i < this->n; ++i){
            this->self[i][i] = 1;
        }
    }
 
    void modify(int i, int j, int value){ this->self[i][j] = value; }
    void set_mod(int x){ this->mod = x; }
 
    matrix operator + (const matrix& other) const{
        if(!(this->n == other.n && this->m == other.m)){
            throw runtime_error("Kich thuoc 2 ma tran phai giong nhau!");
        }
 
        matrix res(this->n, this->m);
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < this->m; ++j){
                res.modify(i, j, (this->self[i][j] % mod + other.self[i][j] % mod) % mod);
            }
        }
 
        return res;
    }
 
    matrix operator - (const matrix& other) const{
        if(!(this->n == other.n && this->m == other.m)){
            throw runtime_error("Kich thuoc 2 ma tran phai giong nhau!");
        }
 
        matrix res(this->n, this->m);
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < this->m; ++j){
                res.modify(i, j, ((this->self[i][j] % mod - other.self[i][j] % mod) % mod + mod) % mod);
            }
        }
 
        return res;
    }
 
    matrix operator * (const matrix& other) const{
        if(!(this->m == other.n)){
            throw runtime_error("Khong the nhan 2 ma tran nay duoc");
        }
 
        matrix res(this->n, other.m);
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < other.m; ++j){
                for(int k = 0; k < this->m; ++k){
                    res.modify(i, j, (res.self[i][j] + (this->self[i][k] % mod) * (other.self[k][j] % mod) % mod) % mod);
                }
            }
        }
 
        return res;
    }
 
    matrix operator ^ (int b) const{
        matrix res(this->n, this->m);
        if(b == 0){
            res.set_identity();
            return res;
        }
 
        matrix temp = *this;
        res = temp;
 
 
        --b;
        while(b > 0){
            if((b & 1) == 1){
                res = res * temp;
            }
 
            temp = temp * temp;
            b >>= 1;
        }
 
        return res;
    }
 
    int get(int i, int j){
        return this->self[i][j];
    }
 
    void output(){
        for(int i = 0; i < this->n; ++i){
            for(int j = 0; j < this->m; ++j){
                cout << get(i, j) << ' ';
            }
            cout << '\n';
        }
    }
};
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    matrix base(2, 2, {{1, 1}, {1, 0}});
 
    int n;
    cin >> n;
 
    base = base ^ n;
    cout << base.get(0, 1) << '\n';
 
    return 0;
}