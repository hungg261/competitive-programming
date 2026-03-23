#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5, MAXLG = __lg(MAXN) + 1;

struct AhoCorasick{
    static const int CHARCNT = 26;
    static const char ORIGIN = 'a';
    struct Node{
        int nxt[CHARCNT];
        int cnt;
        int link;

        Node(){
            memset(nxt, -1, sizeof nxt);
            cnt = 0;
            link = -1;
        }
    };

    vector<Node> T;

    AhoCorasick(){
        T.emplace_back();
    }

    void clear(){
        T.clear();
        T.emplace_back();
    }

    void add(const string& s){
        int p = 0;
        for(int c: s){
            c -= ORIGIN;

            if(T[p].nxt[c] == -1){
                T[p].nxt[c] = T.size();
                T.emplace_back();
            }
            p = T[p].nxt[c];
        }

        ++T[p].cnt;
    }

    void build(){
        queue<int> que;

        T[0].link = 0;
        for(int c = 0; c < CHARCNT; ++c){
            if(T[0].nxt[c] != -1){
                T[T[0].nxt[c]].link = 0;
                que.push(T[0].nxt[c]);
            }
            else{
                T[0].nxt[c] = 0;
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int c = 0; c < CHARCNT; ++c){
                int v = T[u].nxt[c];
                if(v != -1){
                    T[v].link = T[T[u].link].nxt[c];
                    T[v].cnt += T[T[v].link].cnt;
                    que.push(v);
                }
                else{
                    T[u].nxt[c] = T[T[u].link].nxt[c];
                }
            }
        }
    }

    long long Analyze(const string& Text){
        int p = 0;
        long long ans = 0;
        for(int c: Text){
            c -= ORIGIN;

            p = T[p].nxt[c];
            ans += T[p].cnt;
        }

        return ans;
    }
};

int n;
string Data[MAXN + 5];
struct Groups{
    vector<int> groups[MAXLG + 1];
    AhoCorasick forest[MAXLG + 1];

    void Insert(int idx){
        vector<int> U = {idx};
        for(int bit = 0; bit <= MAXLG; ++bit){
            if(groups[bit].size() == U.size()){
                U.insert(U.end(), groups[bit].begin(), groups[bit].end());
                groups[bit].clear();
            }
            else{
                groups[bit] = U;
                forest[bit].clear();
                for(int id: groups[bit]){
                    forest[bit].add(Data[id]);
                }
                forest[bit].build();

                break;
            }
        }
    }

    long long Query(int idx){
        long long ans = 0;
        for(int bit = 0; bit <= MAXLG; ++bit){
            if(groups[bit].empty()) continue;
            ans += forest[bit].Analyze(Data[idx]);
        }

        return ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    Groups ins, del;
    for(int i = 1; i <= n; ++i){
        int type;
        string s;

        cin >> type >> s;
        Data[i] = s;

        if(type == 1){
            ins.Insert(i);
        }
        else if(type == 2){
            del.Insert(i);
        }
        else{
            int ans = ins.Query(i) - del.Query(i);
            cout << ans << endl;
        }
    }

    return 0;
}
