#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6;
int n,delta,a[MAX+1];

bool check(int mid){
    deque<int>mindq,maxdq;
    for(int i=0;i<n;++i){
        if(!mindq.empty()&&i-mindq.front()+1>mid)mindq.pop_front();
        while(!mindq.empty()&&a[mindq.back()]>=a[i])mindq.pop_back();
        mindq.push_back(i);

        if(!maxdq.empty()&&i-maxdq.front()+1>mid)maxdq.pop_front();
        while(!maxdq.empty()&&a[maxdq.back()]<=a[i])maxdq.pop_back();
        maxdq.push_back(i);

        if(i>=mid-1){
            if(a[maxdq.front()]-a[mindq.front()]<=delta){
                return true;
            }
        }
    }
    return false;
}

int tknp(){
    int l=1,h=n,res=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>delta;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    cout<<tknp()<<'\n';
    return 0;
}