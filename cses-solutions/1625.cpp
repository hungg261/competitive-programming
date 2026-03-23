/******************************************************************************
Link: https://cses.fi/problemset/task/1625
Code: 1625
Time (YYYY-MM-DD-hh.mm.ss): 2026-03-05-21.38.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int N = 5, SX = 0, SY = 0, TARX = N - 1, TARY = 0;
int len;
string s;

pair<int, int> coord(int idx){
    return {idx / N, idx % N};
}

int idx(int x, int y){
    return x * N + y;
}

bool bound(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int ins(char ch){
    if(ch == 'U') return 0;
    if(ch == 'R') return 1;
    if(ch == 'D') return 2;
    if(ch == 'L') return 3;
    throw "ins failed";
}

char dir(int id){
    return "URDL"[id];
}

char invdir(char ch){
    if(ch == 'U') return 'D';
    if(ch == 'R') return 'L';
    if(ch == 'D') return 'U';
    if(ch == 'L') return 'R';
    throw "invdir failed";
}

int invdir(int d){
    return ins(invdir(dir(d)));
}

bool mark[N][N];
int res = 0;
//string trace;
void Try(int idx, int x, int y){
//    cerr << idx << ' ' << x << ' ' << y << '\n';
    if(idx >= len){
        if(x == TARX && y == TARY){
//            cout << trace << '\n';
            ++res;
        }
        return;
    }

    if(s[idx] != '?'){
        int d = ins(s[idx]);

        int nx = x + dx[d], ny = y + dy[d];
        if(bound(nx, ny) && !mark[nx][ny]){
            mark[nx][ny] = true;
//            trace += dir(d);

            int nnx = nx + dx[d], nny = ny + dy[d];
            if(!bound(nnx, nny) || mark[nnx][nny]){

            }

            Try(idx + 1, nx, ny);

            mark[nx][ny] = false;
//            trace.pop_back();
        }
    }
    else for(int d = 0; d < 4; ++d){
        int nx = x + dx[d], ny = y + dy[d];
        if(!bound(nx, ny) || mark[nx][ny]) continue;


        mark[nx][ny] = true;
//        trace += dir(d);

        Try(idx + 1, nx, ny);

        mark[nx][ny] = false;
//        trace.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    len = s.size();

    mark[0][0] = true;
    Try(0, 0, 0);

    cout << res << '\n';

    return 0;
}
