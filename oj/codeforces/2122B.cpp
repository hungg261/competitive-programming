#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Pile{
    int a, b, c, d;

    void input(){
        cin >> a >> b >> c >> d;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Pile> arr(n);
    int ans = 0;
    for(Pile& p: arr){
        p.input();
    }

    for(Pile p: arr){
        if(p.a > p.c){
            ans += p.a - p.c;
            p.a = p.c;
        }
        if(p.b > p.d){
            ans += p.a + (p.b - p.d);
            p.b = p.d;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
1
3
0 2 2 2
2 1 1 0
1 0 0 1
*/
