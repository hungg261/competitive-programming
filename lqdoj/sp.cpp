#include<bits/stdc++.h>
using namespace std;

typedef string bigint;
bigint sub(bigint a, bigint b){
    string A=a,B=b;
    bool negative=0,cmp=1;
    if(A.size()==B.size()){
        for(int i=0;i<A.size();++i){
            if(A[i]<B[i]){
                cmp=0;
                break;
            }
        }
    }
    else cmp=A.size()<B.size();
    if(cmp){
        swap(A,B);
        negative=1;
    }

    bigint res="";
    int i = A.size()-1, j = B.size()-1, cr = 0;
    while (i < A.size() || j < B.size()){
        int digA=i>=0?A[i--]-'0':0, digB=j>=0?B[j--]-'0':0;
        int dif=digA-digB-cr;

        if(dif<0){
            dif+=10;
            cr=1;
        }
        else cr=0;
        res+=dif+'0';
    }
    while(res.back()=='0')res.pop_back();
    if(res.empty())res="0";
    else reverse(begin(res),end(res));

    if(negative)res="-"+res;
    return res;
}

bigint operator+(bigint a, bigint b){
    string A=a,B=b;
    bool aneg=A[0]=='-',bneg=B[0]=='-',negative=0;
    if(aneg&&!bneg){
        A.erase(0,1);
        return sub(B,A);
    }
    else if(!aneg&&bneg){
        B.erase(0,1);
        return sub(A,B);
    }
    else if(aneg&&bneg){
        A.erase(0,1);B.erase(0,1);
        negative=1;
    }

    bigint res="";
    int i = A.size()-1, j = B.size()-1, cr = 0;
    while (i>=0||j>=0) {
        if(i>=0) 
            cr+=A[i--]-'0';
        if(j>=0) 
            cr+=B[j--]-'0';
        res+=cr%10+'0';
        cr/=10;
    }
    if(cr>0) res+=cr+'0';
    reverse(begin(res),end(res));

    if(negative)res="-"+res;
    return res;
}

bigint operator-(bigint a, bigint b){
    string A=a,B=b;
    bool aneg=A[0]=='-',bneg=B[0]=='-',negative=0;
    if(aneg&&!bneg){
        A.erase(0,1);
        return "-"+(A+B);
    }
    else if(!aneg&&bneg){
        B.erase(0,1);
        return A+B;
    }
    else if(aneg&&bneg){
        A.erase(0,1);B.erase(0,1);
        swap(A,B);
    }

    bool cmp=1;
    if(A.size()==B.size()){
        for(int i=0;i<A.size();++i){
            if(A[i]<B[i]){
                cmp=0;
                break;
            }
            else if(A[i]>B[i])
                break;
        }
    }
    else cmp=A.size()<B.size();
    if(!cmp){
        swap(A,B);
        negative=1;
    }

    bigint res="";
    int i = A.size()-1, j = B.size()-1, cr = 0;
    while (i < A.size() || j < B.size()){
        int digA=i>=0?A[i--]-'0':0, digB=j>=0?B[j--]-'0':0;
        int dif=digA-digB-cr;

        if(dif<0){
            dif+=10;
            cr=1;
        }
        else cr=0;
        res+=dif+'0';
    }
    while(res.back()=='0')res.pop_back();
    if(res.empty())res="0";
    else reverse(begin(res),end(res));

    if(negative)res="-"+res;
    return res;
}

string div2(string num) {
    string res="";
    int cr = 0;

    bool negative=num[0]=='-';
    if(negative)num.erase(0,1);

    for (char digit:num) {
        int current = cr*10+digit-'0';
        res+=current/2 + '0';
        cr = current % 2;
    }

    size_t start = res.find_first_not_of('0');
    if (start!=string::npos)
        res = res.substr(start);
    else
        res = "0";

    if(negative)return "-"+res;
    return res;
}

signed main(){
    bigint m,n;cin>>m>>n;

    bigint a=div2(m+n);
    cout<<(a=="-0"?"0":a)<<'\n'<<a-n;
    return 0;
}