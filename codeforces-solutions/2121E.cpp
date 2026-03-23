#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
int dp[10][2][2][10][10];
int numL[10], numR[10];
int l, r;

int Try(int idx, int largerL, int smallerR, int diffL, int diffR){
    if(idx < 0){
        return diffL + diffR;
    }

    int &memo = dp[idx][largerL][smallerR][diffL][diffR];
    if(memo != -1) return memo;

    int limL = largerL ? 0 : numL[idx];
    int limR = smallerR ? 9 : numR[idx];

    memo = INF;
    for(int digit = limL; digit <= limR; ++digit){
        memo = min(memo, Try(idx - 1,
                                largerL || digit > limL,
                                smallerR || digit < limR,
                                diffL + (digit == numL[idx]),
                                diffR + (digit == numR[idx])
                             )
                   );
    }

    return memo;
}

void solve(){
    cin >> l >> r;

    int lenL = 0, lenR = 0;
    while(l > 0){
        numL[lenL++] = l % 10;
        l /= 10;
    }
    while(r > 0){
        numR[lenR++] = r % 10;
        r /= 10;
    }

    int len = max(lenL, lenR);
    memset(dp, -1, sizeof dp);

    int ans = Try(len - 1, 0, 0, 0, 0);
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}
