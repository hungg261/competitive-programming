#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BAKER.INP","r",stdin);
    freopen("BAKER.OUT","w",stdout);
    int n;
    cin >> n;

	// #define double long double
    vector<int> a(n), b(n);
    for(int& ele: a) cin >> ele;
    for(int& ele: b) cin >> ele;
	
    int best = 0;
    for(int i = 1; i < n; ++i){
        if((__float128)a[i] / b[i] > (__float128)a[best] / b[best]) best = i;
    }

    cout << best + 1 << '\n';

    return 0;
}
