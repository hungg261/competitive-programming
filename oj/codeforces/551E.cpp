#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, BLOCKSIZE = 700, BLOCKCNT = MAXN / BLOCKSIZE + 1;
int n, q;
long long arr[MAXN + 5];

struct Block{
    vector<pair<long long, int>> self;
    long long lazy = 0;

    Block() = default;
    Block(long long _lazy): lazy(_lazy){}

    void push_back(long long val, int idx){
        self.emplace_back(val, idx);
    }

    void clear(){
        self.clear();
    }

    void sort(){
        std::sort(begin(self), end(self));
    }

    int size(){
        return (int)self.size();
    }

    int getFirst(long long x){
        int l = 0, r = size() - 1, res = -1;
        pair<long long, int> target = {x - lazy, -1};
        while(l <= r){
            int mid = (l + r) >> 1;
            if(self[mid] >= target){
                if(self[mid].first == target.first) res = self[mid].second;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return res;
    }

    int getLast(long long x){
        int l = 0, r = size() - 1, res = -1;
        pair<long long, int> target = {x - lazy, MAXN + 5};
        while(l <= r){
            int mid = (l + r) >> 1;
            if(self[mid] <= target){
                if(self[mid].first == target.first) res = self[mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return res;
    }
} blocks[BLOCKCNT + 1];

inline int f(int idx){ return (idx - 1) / BLOCKSIZE + 1; }
inline int St(int b){ return (b - 1) * BLOCKSIZE + 1; }
inline int En(int b){ return min(n, b * BLOCKSIZE); }

void build(int idx){
    int b = f(idx);

    blocks[b].clear();
    for(int i = idx - 1; i >= 1 && f(i) == b; --i) blocks[b].push_back(arr[i], i);
    for(int i = idx; i <= n && f(i) == b; ++i) blocks[b].push_back(arr[i], i);
    blocks[b].sort();
}

void update(int l, int r, long long delta){
    int blockL = f(l),
        blockR = f(r);

    if(blockL == blockR){
        for(int i = l; i <= r; ++i){
            arr[i] += delta;
        }
        build(l);
        return;
    }

    for(int b = blockL + 1; b <= blockR - 1; ++b){
        blocks[b].lazy += delta;
    }

    for(int i = l; i <= En(blockL); ++i) arr[i] += delta;
    for(int i = St(blockR); i <= r; ++i) arr[i] += delta;
    build(l);
    build(r);
}

void query(int target){
    int first = -1, last = -1;
    for(int b = 1; b <= BLOCKCNT; ++b){
        int L = blocks[b].getFirst(target);
        if(L != -1){
            first = L;
            break;
        }
    }
    for(int b = BLOCKCNT; b >= 1; --b){
        int R = blocks[b].getLast(target);
        if(R != -1){
            last = R;
            break;
        }
    }

    if(first == -1) cout << "-1\n";
    else cout << last - first << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];

        blocks[f(i)].push_back(arr[i], i);
    }
    for(int b = 1; b <= BLOCKCNT; ++b){
        blocks[b].sort();
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            long long l, r, x;
            cin >> l >> r >> x;

            update(l, r, x);
        }
        else{
            int x;
            cin >> x;

            query(x);
        }
    }

    return 0;
}

