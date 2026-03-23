#include<bits/stdc++.h>
using namespace std;

int n,m,R;
struct interval{
    int start,stop;

    void output(){
        cout<<"["<<start<<", "<<stop<<"]"<<'\n';
    }
} x[1000005];
int len=0;

bool op(interval&a,interval&b){
    if(a.start==b.start)return a.stop<b.stop;
    return a.start<b.start;
}

void solve(){
    int covered=0,
        idx=0;
    while(covered<n){
        int farthest=covered,old_pos=idx;
        while(idx<m&&x[idx].start<=covered){
            if(x[idx].stop>farthest){
                farthest=max(farthest,x[idx].stop);
            }
            ++idx;
        }
        
        if(old_pos==idx){
            cout<<"0\n";
            return;
        }
        covered=farthest+1;
        ++len;
    }
    cout<<len<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("STATION.INP","r",stdin);
    freopen("STATION.OUT","w",stdout);
    cin>>n>>m>>R;
    for(int i=0;i<m;++i){
        int point;
        cin>>point;

        x[i]={point-R,point+R};
    }
    sort(x,x+m,op);
    
    solve();
    return 0;
}
