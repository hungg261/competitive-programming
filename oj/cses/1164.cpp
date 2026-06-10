#include<bits/stdc++.h>
using namespace std;

struct Event{
    int time, type, idx;

    bool operator < (const Event& other) const{
        if(this->time == other.time) return this->type == 0;
        return this->time < other.time;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    vector<Event> events;
    for(int i = 1; i <= n; ++i){
        int a, b; cin >> a >> b;

        events.push_back({a, 0, i});
        events.push_back({b, 1, i});
    }
    sort(begin(events), end(events));

    vector<int> available;
    for(int i = n; i >= 1; --i) available.push_back(i);

    int rooms = 0;
    vector<int> res(n + 1);
    for(int i = 0; i < n * 2; ++i){
        if(events[i].type == 0){
            int curRoom = available.back();

            res[events[i].idx] = curRoom;
            rooms = max(rooms, curRoom);
            available.pop_back();
        }
        else{
            available.push_back(res[events[i].idx]);
        }
    }

    cout << rooms << '\n';
    for(int i = 1; i <= n; ++i) cout << res[i] << ' ';


    return 0;
}
