/******************************************************************************
Link: https://oj.uz/problem/view/IOI18_combo
Code: IOI18_combo
Time (YYYY-MM-DD-hh.mm.ss): 2026-06-03-20.47.36
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#ifndef __________
#include "combo.h"
#else
namespace {

const int MAX_N = 2000;
int MAX_NUM_MOVES = 8000;

int N;
std::string S;

int num_moves;

void wrong_answer(const char *MSG) {
  printf("Wrong Answer: %s\n", MSG);
  exit(0);
}

}  // namespace

int press(std::string p) {
//cerr << "pressed: " << p << endl;

  if (++num_moves > MAX_NUM_MOVES) {
    wrong_answer("too many moves");
  }
  int len = p.length();
  if (len > 4 * N) {
    wrong_answer("invalid press 1");
  }
  for (int i = 0; i < len; ++i) {
    if (p[i] != 'A' && p[i] != 'B' && p[i] != 'X' && p[i] != 'Y') {
      wrong_answer("invalid press 2");
    }
  }
  int coins = 0;
  for (int i = 0, j = 0; i < len; ++i) {
    if (j < N && S[j] == p[i]) {
      ++j;
    } else if (S[0] == p[i]) {
      j = 1;
    } else {
      j = 0;
    }
    coins = std::max(coins, j);
  }
  return coins;
}

string guess_sequence(int N);

signed main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);

    srand(0);

    for(int t = 1; t <= 1000; ++t){
        N = rand() % 2000 + 1;
        vector<string> av = {"A", "B", "X", "Y"};
        S = av[rand() % 4];
        av.erase(find(begin(av), end(av), S));
        ;
        for(int i = 0; i < N - 1; ++i){
            string c = av[rand() % av.size()];
            S += c;
        }

        MAX_NUM_MOVES = N + 2;
        num_moves = 0;

//        cout << S << "\n";
        string out = guess_sequence(S.size());
        cout << (out == S) << "\n";
    }

//    cin >> S;
//    N = S.size();
//
//    cerr << guess_sequence(N) << "\n";

    return 0;
}
#endif

string guess_sequence(int N){
    string P;
    vector<string> S = {"A", "B", "X", "Y"};

    if(press("AB")){
        if(press("A")) P += 'A';
        else P += 'B';
    }
    else{
        if(press("X")) P += 'X';
        else P += 'Y';
    }

    if(N == 1) return P;

    S.erase(find(begin(S), end(S), P));

    for(int i = 1; i < N - 1; ++i){
        int p = press((P + S[0] + S[0]) + (P + S[0] + S[1]) + (P + S[0] + S[2]) + (P + S[1]));

        int cur = P.size();
        if(p == cur + 2) P += S[0];
        else if(p == cur + 1) P += S[1];
        else P += S[2];
    }

    if(press((P + S[0]) + (P + S[1])) == N){
        if(press(P + S[0]) == N) P += S[0];
        else P += S[1];
    }
    else{
        P += S[2];
    }

    return P;
}
