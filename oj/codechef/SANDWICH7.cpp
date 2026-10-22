/******************************************************************************
Link: https://www.codechef.com/START258D/problems/SANDWICH7
Code: SANDWICH7
Time (YYYY-MM-DD-hh.mm.ss): 2026-09-30-21.35.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int B, H, C;
    cin >> B >> H >> C;

    cout << min({B / 2, H + C});

    return 0;
}
