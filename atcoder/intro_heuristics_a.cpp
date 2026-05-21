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

void SA(){
    greedy();
    int curBest = compute_score();

    const double Time = 1.867;
    double cur_time = 0;
    while((cur_time = 1.0 * clock() / CLOCKS_PER_SEC) < Time){
        int d = rng() % D + 1;
        int old_t = ans[d];
        int new_t;
        bool swapped = false;
        if(d < D && rng() % 100 < 20){
            old_t = rng() % D + 1; new_t = rng() % D + 1;
            swap(ans[old_t], ans[new_t]);
            swapped = true;
        }
        else{
            do{ new_t = rng() % 26 + 1; } while(new_t == old_t);

            ans[d] = new_t;
        }

        int newScore = compute_score();

        int delta = newScore - curBest;
        double T = 3000.0 * (1.0 - cur_time / Time);

        if(delta >= 0 || uniform_real_distribution<double>(0, 1)(rng) < exp(1.0 * delta / T))
            curBest = newScore;
        else{
            if(swapped) swap(ans[old_t], ans[new_t]);
            else ans[d] = old_t;
        }
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

    SA();

    return 0;
}
