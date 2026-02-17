/*アルゴリズムと工夫点(Reconstruct Chocolate/CPU: 76 ms Memory: 10752 KB  Length: 1565 B)
ソートして解く．
チョコは，常に現在のチョコの幅もしくは高さと一致するように分割される．
ここで，問題をH * Wの幅にチョコのピースを当てはめていく問題を考える．
すると，当てはめられていないブロックの長方形の幅または高さに一致するピースを選び，
左端から詰めて当てはめていけばよい．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P; //(length, id)

struct Block{
    int h, w;

    Block(int h = 0, int w = 0):h(h), w(w){};
};

int h, w, n;

int main(){
    int i, j;
    scanf("%d%d%d", &h, &w, &n);
    vector<bool> is_used(n, false);
    vector<Block> blocks(n);
    vector<P> hs(n), ws(n), ans(n);
    rep(i, n){
        int block_h, block_w;
        scanf("%d%d", &block_h, &block_w);
        blocks[i] = Block(block_h, block_w);
        hs[i] = P(block_h, i);
        ws[i] = P(block_w, i);
    }
    sort(hs.begin(), hs.end());sort(ws.begin(), ws.end());
    int now_h = h, now_w = w;
    while(now_h > 0 && now_w > 0){
        while(hs.size() && is_used[hs.back().second])hs.pop_back();
        while(ws.size() && is_used[ws.back().second])ws.pop_back();
        if(hs.size() && now_h == hs.back().first){
            int id = hs.back().second;hs.pop_back();
            ans[id] = P(h - now_h + 1, w - now_w + 1);
            is_used[id] = true;
            now_w -= blocks[id].w;
        }else if(ws.size() && now_w == ws.back().first){
            int id = ws.back().second;ws.pop_back();
            ans[id] = P(h - now_h + 1, w - now_w + 1);
            is_used[id] = true;
            now_h -= blocks[id].h;
        }
    }
    rep(i, n)printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}