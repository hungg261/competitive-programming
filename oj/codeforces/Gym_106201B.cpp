/******************************************************************************
Link: https://codeforces.com/gym/106201/problem/B
Code: Gym_106201B
Time (YYYY-MM-DD-hh.mm.ss): 2026-11-01-19.12.35
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, s, e, k;
struct State{
    int L, R, V;
};

void solve(){
    list<State> lst;
    lst.insert(lst.begin(), {1, n, 0});

    auto merge = [&](list<State>::iterator it, list<State>::iterator vip){
        if(it != lst.begin()){
            auto prv = prev(it);
            if(prv->V == it->V){
                it->L = prv->L;
                if(prv != vip) lst.erase(prv);
            }
        }

        if(it != lst.end()){
            auto nxt = next(it);
            if(nxt != lst.end() && nxt->V == it->V){
                it->R = nxt->R;
                if(nxt != vip) lst.erase(nxt);
            }
        }
    };

    auto it = lst.begin();
    int sub = 0;
    for(int i = 1; i <= s; ++i){
        sub += e;
        int H = m + sub;

        while(it != lst.begin()){
            auto prv = prev(it);
            if(prv->V < H){
                --it;
            }
            else break;
        }

        {
            int len = 0;
            while(!lst.empty() && lst.back().V <= sub){
                len += lst.back().R - lst.back().L + 1;
                if(it == prev(lst.end())) it = lst.end();
                lst.pop_back();
            }

            if(len > 0){
                lst.push_back({n - len + 1, n, sub});
                if(it == lst.end()) it = prev(lst.end());
            }
        }

        int left = k;
        for(; it != lst.end(); ++it){
            int filled = (H - it->V) * (it->R - it->L + 1);
            if(left >= filled){
                it->V = H;
                left -= filled;
                merge(it, it);
            }
            else{
                int full = left / (H - it->V),
                    rem = left % (H - it->V);

                if(full > 0){
                    merge(lst.insert(it, {it->L, it->L + full - 1, H}), it);
                    it->L += full;
                }
                if(rem > 0){
                    merge(lst.insert(it, {it->L, it->L, it->V + rem}), it);
                    it->L++;
                }

                if(it->L > it->R){
                    it = lst.erase(it);
                }

                merge(it, it);
                break;
            }
        }
    }

    int min_val = max(0LL, lst.back().V - sub);
    int ans_room = lst.back().L;
    cout << ans_room << " " << min_val << "\n";
}

void brute();

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> e >> k;

    solve();

    return 0;
}

void brute(){
    vector<int> rooms(n + 1);
    for(int d = 1; d <= s; ++d){
        for(int i = 1; i <= n; ++i)
            rooms[i] = max(0LL, rooms[i] - e);

        int left = k;
        for(int i = 1; i <= n; ++i){
            rooms[i] += left;
            if(rooms[i] > m){
                left = rooms[i] - m;
                rooms[i] = m;
            }
            else break;
        }
    }

    auto it = min_element(begin(rooms) + 1, end(rooms));
    cout << (it - begin(rooms)) << " " << (*it) << "\n";
}
