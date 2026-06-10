/******************************************************************************
Link: https://cses.fi/problemset/task/1625
Code: 1625
Time (YYYY-MM-DD-hh.mm.ss): 2026-04-14-10.38.32
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

const int N = 7;
bool visited[N][N];
string p;
int ans = 0;

void solve(int r, int c, int s) {
    if (r == 6 && c == 0) {
        if (s == 48) ans++;
        return;
    }
    if (s == 48) return;

    if ((r == 0 || r == 6 || (visited[r-1][c] && visited[r+1][c])) && c > 0 && c < 6 && !visited[r][c-1] && !visited[r][c+1]) return;
    if ((c == 0 || c == 6 || (visited[r][c-1] && visited[r][c+1])) && r > 0 && r < 6 && !visited[r-1][c] && !visited[r+1][c]) return;

    visited[r][c] = true;

    if (r < 6 && !visited[r+1][c] && (p[s] == '?' || p[s] == 'D')) solve(r+1, c, s+1);
    if (r > 0 && !visited[r-1][c] && (p[s] == '?' || p[s] == 'U')) solve(r-1, c, s+1);
    if (c > 0 && !visited[r][c-1] && (p[s] == '?' || p[s] == 'L')) solve(r, c-1, s+1);
    if (c < 6 && !visited[r][c+1] && (p[s] == '?' || p[s] == 'R')) solve(r, c+1, s+1);

    visited[r][c] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> p;

    solve(0, 0, 0);

    cout << ans << endl;

    return 0;
}
