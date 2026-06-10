/******************************************************************************
Link: https://codeforces.com/contest/1349/problem/A
Code: 1349A
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-05-16.03.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5, MAXVAL = 2e5;
int n, a[MAXN + 5];
map<int, int> cnt[MAXVAL + 5];

int spf[MAXVAL + 5];

void compute(){
    for(int i = 2; i * i <= MAXVAL; ++i){
        if(!spf[i]) for(int j = i * i; j <= MAXVAL; j += i){
            if(!spf[j]) spf[j] = i;
        }
    }
}

void pfactor(int cur){
    while(cur > 1){
        int p = spf[cur];
        if(p == 0) p = cur;

        int c = 0;
        while(cur % p == 0){
            cur /= p;
            c++;
        }

        cnt[p][c]++;
    }
}

int solve(){
    for(int i = 1; i <= n; ++i){
        pfactor(a[i]);
    }

    int res = 1;
    for(int p = 2; p <= MAXVAL; ++p){
        if(spf[p]) continue;

        int cntv0 = n;

        for(const pair<int, int>& pii: cnt[p]){
            cntv0 -= pii.second;
        }
        cnt[p][0] = cntv0;

        int contrib = 0;
        bool skipped = false;
        for(const pair<int, int>& pii: cnt[p]){
            if(pii.second == 0) continue;
            else if(skipped || pii.second > 1){
                contrib = pii.first;
                break;
            }
            skipped = true;
        }

        while(contrib--) res *= p;
    }

    return res;
}

long long trau(){
    auto __lcm = [](int a, int b) -> long long { return 1LL * a / __gcd(a, b) * b; };

    long long g = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            g = __gcd(g, __lcm(a[i], a[j]));
        }
    }

    return g;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    srand(time(0));

//    #define stress
    #ifdef stress
    bool STRESS = true;
    #else
    bool STRESS = false;
    #endif

    compute();

    if(!STRESS){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }

        cout << solve() << "\n";
    }
    else{
        while(true){
            n = rand() % 1000 + 2;
            int g = rand() % 10 + 1;
            for(int i = 1; i <= n; ++i){
                a[i] = g * (rand() % (200000 / g - 1) + 1);
            }

            for(int i = 1; i <= MAXVAL; ++i) cnt[i].clear();

            cerr << "===== TEST ======\n";
//            cerr << n << "\n";
//            for(int i = 1; i <= n; ++i) cerr << a[i] << " "; cerr << endl;
            cerr << "================\n";
            int jury = trau();
//            for(int i = 1; i <= MAXVAL; ++i) cnt[i].clear();
            int out = solve();
            cerr << "exp: " << jury << ", got " << out << endl;
            cerr << "================\n";
            if(out != jury) break;

//            system("pause");
        }
    }


    return 0;
}
