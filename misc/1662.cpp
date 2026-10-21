/******************************************************************************
Link: https://qoj.ac/problem/1662
Code: 1662
Time (YYYY-MM-DD-hh.mm.ss): 2026-10-21-09.01.29
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;
string str;

struct Box{
    vector<string> v;

    Box() = default;
    Box(string c){
        init(c);
    }
    Box(char c){
        init(string(1, c));
    }

    void init(const string &c){
        if(c[0] == '-'){
            v = {" ", string(1, c[1])};
        }
        else{
            v.resize(3);
            v[0] = v[2] = "+" + string(c.size() + 2, '-') + "+";
            v[1] = "+ " + c + " +";
        }
    }

    bool special(char c) const {
        return v[1][0] == c;
    }

    int width() const { return v[0].size(); }
    int height() const { return v.size(); }

    friend ostream& operator << (ostream &os, const Box &box){ for(const string &s: box.v){ os << s << "\n"; } return os; }


    Box pl() const { // +
        Box res;

        int h = v.size(), w = v[0].size();
        res.v.resize(h + 2);

        res.v[0] = string(3, ' ') + v[0] + string(3, ' ');
        res.v[1] = "+->" + v[1] + "->+";

        for(int i = 2; i < h; ++i)
            res.v[i] = "|  " + v[i] + "  |";

        res.v[h] = string(w + 6, ' ');
        res.v[h][0] = res.v[h].back() = '|';
        res.v.back() = "+<" + string(w + 3, '-') + "+";

        for(int i = 1; i < h + 2; ++i){
            if(res.v[i][0] != '+') res.v[i][0] = res.v[i].back() = '|';
        }
        return res;
    }


    Box qu() const { // ?
        Box res;

        int H = this->height() + 3, W = this->width() + 6;
        res.v.resize(H);


        res.v[0] = string(W, ' ');
        res.v[1] = "+" + string(W - 3, '-') + ">+";
        res.v[2] = "|" + string(W - 2, ' ') + "|";
        for(int i = 3; i < H; ++i){
            string pre, suf;

            if(i < 4) pre = "|  ", suf = "  |";
            else if(i == 4) pre = "+->", suf = "->+";
            else pre = "   ", suf = "   ";

            res.v[i] = pre + v[i - 3] + suf;
        }

        return res;
    }


    Box ast(){ // *
        Box res = this->qu();

        int H = this->height() + 5, W = this->width() + 6;
        res.v.resize(H);

        for(int i = 1; i < H; ++i){
            if(res.v[i][0] != '+') res.v[i][0] = res.v[i].back() = '|';
        }

        res.v[H - 2] = "|" + string(W - 2, ' ') + "|";
        res.v[H - 1] = "+" + string(W - 3, '-') + ">+";

        return res;
    }


    Box operator + (const Box &other) const {
        if(this->v.empty()) return other;
        else if(other.v.empty()) return *this;

        Box res;
        res.v.resize(max(v.size(), other.v.size()));
        int sz = res.v.size();

        auto get = [](int i, const vector<string> &vec){
            return i >= (int)vec.size() ? (vec.empty() ? "" : string(vec[0].size(), ' '))  : vec[i];
        };

        for(int i = 0; i < sz; ++i){
            res.v[i] = get(i, v) + (i == 1 ? "->" : "  ") + get(i, other.v);
        }
        return res;
    }
};


Box OR(const vector<Box> &boxes);


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> str;
    str += '|';
    int sz = str.size();

    vector<Box> sta;
    vector<Box> parts;
    string curv = "";
    for(int i = 0; i < sz; ++i){
        if(isalpha(str[i])){
            curv += str[i];
        }
        else{
            if(!curv.empty()){
                char c = '#';
                if(str[i] == '+' || str[i] == '?' || str[i] == '*'){
                    c = curv.back();
                    curv.pop_back();
                }

                if(!curv.empty()) sta.push_back(Box(curv));
                if(c != '#') sta.push_back(Box(c));

                curv = "";
            }

            if(str[i] == '|'){
                Box cur;
                for(const Box &b: sta){
                    cur = cur + b;
                }
                sta.clear();
                parts.push_back(cur);
            }
            else if(str[i] == '('){
                sta.push_back(Box("-("));
            }
            else if(str[i] == ')'){
                vector<Box> order;
                while(!sta.back().special('(')){
                    order.push_back(sta.back());
                    sta.pop_back();
                }

                Box cur;
                while(!order.empty()){
                    cur = cur + order.back();
                    order.pop_back();
                }



                sta.pop_back();
                sta.push_back(cur);
            }
            else{
                if(str[i] == '+') sta.back() = sta.back().pl();
                else if(str[i] == '?') sta.back() = sta.back().qu();
                else if(str[i] == '*') sta.back() = sta.back().ast();
            }
        }
    }

    Box res = Box("-S") + OR(parts) + Box("-T");

    cout << res.height() << " " << res.width() << "\n";
    cout << res << "\n";

    return 0;
}


Box OR(const vector<Box> &boxes){
    if((int)boxes.size() == 1) return boxes[0];

    Box res;

    int H = 0, W = 0, cnt = boxes.size();
    for(const Box &B: boxes)
        H += B.height(),
        W = max(W, B.width());

    H += (int)boxes.size() - 1;
    W += 6;

    res.v.resize(H);

    auto fill = [&res, &W](Box box, int shift){
        for(int i = 0; i < box.height(); ++i){
            string pre, suf;
            if(i == 0) pre = "   ", suf = string(W - (box.width() + 3), ' ');
            else if(i == 1) pre = "+->", suf = string(W - (box.width() + 3) - 2, '-') + ">+";
            else if(i > 1) pre = "   ", suf = string(W - (box.width() + 3) - 1, ' ') + " ";

            res.v[shift + i] = pre + box.v[i] + suf;
        }
    };

    for(int i = 0, shift = 0; i < cnt; ++i){
        fill(boxes[i], shift);

        if(i + 1 < cnt) res.v[shift + boxes[i].height()] = string(W, ' ');
        shift += boxes[i].height() + 1;
    }
    for(int i = 0, shift = 0; i < cnt; ++i){
        if(i + 1 < cnt){
            for(int j = shift + 2; j < shift + boxes[i].height() + 2; ++j){
                res.v[j][0] = res.v[j].back() = '|';
            }
        }
        shift += boxes[i].height() + 1;
    }

    return res;
}
