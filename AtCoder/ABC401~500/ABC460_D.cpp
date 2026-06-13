/*アルゴリズムと工夫点(Repeatedly Repainting/CPU: 87 ms Memory: 24524 KB  Length: 1822 B)
幅優先探索を用いて解く．
解の形を観察してみると，下記の性質が分かる．
 <i> 一度黒マスになると，それ以降は，白 → 黒 → 白 と状態が順に遷移するようになる
 <ii> 初期状態に寄っては，もともと黒であったが，白になった後に周囲8マスに黒がないために，白 → 白 → ... となる場合がある
10 ^ 100 は偶数であるため，各マスが初めて黒になった際のターン数が偶数であるものは，最終的に黒ますとして出力される．
このターン数の偶奇は，BFS を用いて求めることができる．
ここで <ii> の場合に対応するため，初期状態の黒マスの周囲8マスの内，白マスの所を，奇数ターンに塗られたとし，
その状態から多始点BFSの形で，各マスの「初めて黒くなったターンの偶奇」を求めていけばよい．
最悪計算量は，O(H * W) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int h, w;

int main(){
    int i, j;
    
    scanf("%d%d", &h, &w);
    vector<string> mp(h);
    rep(i, h)cin >> mp[i];

    const int NIL = -1;
    vector<vector<int> > vis(h, vector<int>(w, NIL));
    const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, MAX_D = 8;
    auto bfs = [&]() -> void{
        int i, j, k;

        queue<P> que;
        rep(i, h)rep(j, w)if(mp[i][j] == '#'){
            rep(k, MAX_D){
                int nxt_y = i + dy[k];
                int nxt_x = j + dx[k];                
                if(
                    0 <= nxt_y && nxt_y < h && 
                    0 <= nxt_x && nxt_x < w && 
                    mp[nxt_y][nxt_x] == '.'
                ){
                    vis[nxt_y][nxt_x] = 1;
                    que.push(P(nxt_y, nxt_x));
                }
            }
        }

        while(que.size()){
            auto [y, x] = que.front();que.pop();
            rep(i, MAX_D){
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if(
                    0 <= nxt_y && nxt_y < h && 
                    0 <= nxt_x && nxt_x < w && 
                    vis[nxt_y][nxt_x] == NIL
                ){
                    vis[nxt_y][nxt_x] = (vis[y][x] + 1) % 2;
                    que.push(P(nxt_y, nxt_x));
                }
            }
        }
    };
    bfs();

    rep(i, h){
        rep(j, w - 1)printf("%c", vis[i][j] ? '.' : '#');
        printf("%c\n", vis[i][j] ? '.' : '#');
    }
    return 0;
}