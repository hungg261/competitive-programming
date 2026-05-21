/******************************************************************************
Link: https://atcoder.jp/contests/intro-heuristics/tasks/intro_heuristics_a
Code: intro_heuristics_a
Time (YYYY-MM-DD-hh.mm.ss): 2026-05-21-07.14.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXD = 367, MAX = 26;
int D, c[MAX + 1], s[MAXD + 1][MAX + 1];
int ans[MAXD + 1], last[MAX + 1];

// greedy
void greedy(){
    for(int i = 1; i <= D; ++i){
        int dec = 0;
        for(int j = 1; j <= 26; ++j){
            dec += c[j] * (i - last[j]);
        }

        pair<int, int> best = {LLONG_MIN, 0};
        for(int j = 1; j <= 26; ++j){
            dec -= c[j] * (i - last[j]);
            best = max(best, {s[i][j] - dec, j});
            dec += c[j] * (i - last[j]);
        }

        ans[i] = best.second;
        last[best.second] = i;
    }
}

// hill climbing
int compute_score(){
    int score = 0;
    for(int j = 1; j <= 26; ++j) last[j] = 0;
    for(int i = 1; i <= D; ++i){
        score += s[i][ans[i]];
        last[ans[i]] = i;
        for(int j = 1; j <= 26; ++j){
            if(j != ans[i]){
                score -= c[j] * (i - last[j]);
            }
        }
    }
    return score;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void hill_climbing(){
    greedy();
    int curBest = compute_score();

    while(1.0 * clock() / CLOCKS_PER_SEC < 1.867){
        int d = rng() % D + 1;
        int old_t = ans[d];
        int new_t;
        do{ new_t = rng() % 26 + 1; } while(new_t == old_t);

        ans[d] = new_t;
        int newScore = compute_score();

        if(newScore >= curBest)
            curBest = newScore;
        else ans[d] = old_t;
    }

    for(int i = 1; i <= D; ++i){
        cout << ans[i] << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> D;
    for(int i = 1; i <= MAX; ++i) cin >> c[i];
    for(int i = 1; i <= D; ++i){
        for(int j = 1; j <= MAX; ++j){
            cin >> s[i][j];
        }
    }

    hill_climbing();

    return 0;
}
