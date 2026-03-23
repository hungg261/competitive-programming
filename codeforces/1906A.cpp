/******************************************************************************
Link: https://codeforces.com/problemset/problem/1906/A
Code: 1906A
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-05-16.34.53
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int sz = 3;

bool bound(int x, int y){
    return 0 <= x && x < sz && 0 <= y && y < sz;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	string arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	string res = string(3, 125);
    for(int i = 0; i < sz; ++i){
        for(int j = 0; j < sz; ++j){
            for(int d1 = 0; d1 < 8; ++d1){
                int nx1 = i + dx[d1], ny1 = j + dy[d1];
                if(bound(nx1, ny1)){
                    for(int d2 = 0; d2 < 8; ++d2){
                        if(d2 == d1) continue;
                        int nx2 = i + dx[d2], ny2 = j + dy[d2];
                        if(bound(nx2, ny2)){
                            string cur;
                            cur += arr[nx1][ny1];
                            cur += arr[i][j];
                            cur += arr[nx2][ny2];

                            res = min(res, cur);
                        }
                    }
                }
            }
        }
    }

    cout << res << '\n';

	return 0;
}
