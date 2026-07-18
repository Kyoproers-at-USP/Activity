/*アルゴリズムと工夫点(Plumage Palette/CPU: 136 ms Memory: 23532 KB  Length: 1513 B)
色毎の区間管理 + imos法で解く．
N色それぞれを観察することができる区間が予め求まっていれば，
その区間に +1 することを繰り返すことで，各日の鳥の色の種類数が求められる．
そこで，色ごとに区間を管理し，各色の観察可能区間をそれぞれ求めればよい．
区間加算は imos法を用いて高速化する．
すると，最悪計算量は O(N * log2(N) + M) < 10 ^ 7 となり，高速．
※ 鳥iでは，[1, D1) の区間では Ai, [D1, M) の区間では Bi が観察可能であるため，最大の区間数は 2 * Nとなる
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n, m;

int main(){
    int i, j;
    
    scanf("%d%d", &n, &m);
    vector<vector<P> > color_to_seqs(n);
    rep(i, n){
        int a, d, b;
        scanf("%d%d%d", &a, &d, &b);
        a--;b--;

        color_to_seqs[a].push_back(P(0, d - 1));
        color_to_seqs[b].push_back(P(d - 1, m));
    }

    vector<int> imos(m + 1, 0);
    rep(i, n){
        auto& seqs = color_to_seqs[i];
        sort(seqs.begin(), seqs.end());
        
        int now = 0;
        while(now < seqs.size()){
            int now_begin = seqs[now].first;
            int now_end = seqs[now].second;
            now++;

            auto is_common = [&](int begin, int end) -> bool{
                return min(now_end, end) >= max(now_begin, begin);
            };
            while(now < seqs.size() && is_common(
                /* begin = */ seqs[now].first, 
                /* end = */ seqs[now].second
            )){
                now_begin = min(now_begin, seqs[now].first);
                now_end = max(now_end, seqs[now].second);
                now++;
            }

            imos[now_begin]++;
            imos[now_end]--;
        }
    }
    rep(i, m)imos[i + 1] += imos[i];

    rep(i, m)printf("%d\n", imos[i]);
    return 0;
}