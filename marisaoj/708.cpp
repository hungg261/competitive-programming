#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, MAXQ = 2e5;
int BLOCKSIZE;
int n, q;
int a[MAXN + 5], pre[MAXN + 5];
pair<long long, int> mp[MAXN * 2 + 5];

struct Query{
    int l, r, id;

    bool operator < (const Query& other){
        int b1 = l / BLOCKSIZE, b2 = other.l / BLOCKSIZE;

        if(b1 != b2) return b1 < b2;
        return (b1 & 1) ? r < other.r : r > other.r;
    }
} queries[MAXQ + 5];

int L = 0, R = 0;
long long curRes = 0;

void addR(){
    ++R;

    {
        const pair<long long, int>& p = mp[pre[R]];
        curRes += 1LL * R * p.second - p.first;
    }

    pair<long long, int>& p = mp[pre[R]];
    p.first += R; p.second++;
}

void addL(){
    --L;
    pair<long long, int>& p = mp[pre[L]];
    p.first += L; p.second++;

    {
        const pair<long long, int>& p = mp[pre[L]];
        curRes += p.first - 1LL * L * p.second;
    }
}

void popR(){
    pair<long long, int>& p = mp[pre[R]];
    p.first -= R; p.second--;

    {
        const pair<long long, int>& p = mp[pre[R]];
        curRes -= 1LL * R * p.second - p.first;
    }

    R--;
}

void popL(){
    {
        const pair<long long, int>& p = mp[pre[L]];
        curRes -= p.first - 1LL * L * p.second;
    }

    pair<long long, int>& p = mp[pre[L]];
    p.first -= L; p.second--;

    L++;
}

long long res[MAXQ + 5];
void solve(){
    sort(queries + 1, queries + q + 1);
    for(int i = 1; i <= q; ++i){
        int l = queries[i].l, r = queries[i].r;
        while(L > l - 1) addL();
        while(R < r) addR();
        while(L < l - 1) popL();
        while(R > r) popR();

        res[queries[i].id] = curRes;
    }

    for(int i = 1; i <= q; ++i){
        cout << res[i] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    BLOCKSIZE = n / sqrt(q);
    if(BLOCKSIZE < 1) BLOCKSIZE = 1;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + (a[i] ? 1 : -1);
    }
    for(int i = 0; i <= n; ++i) pre[i] += MAXN;

    pair<long long, int>& p = mp[pre[0]];
    p.first += R; p.second++;

    for(int i = 1; i <= q; ++i){
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }

    solve();

    return 0;
}
