/*アルゴリズムと工夫点(Reachability Query 2/CPU: 158 ms Memory: 20100 KB  Length: 1043 B)
適宜BFSを用いて状態更新しつつ処理する．
入力とは逆向きに辺を張ったグラフを考える．
クエリ1に対しては，黒く塗れと指示された頂点を始点としてBFSを行い，白い頂点を黒く塗る．
クエリ2に対しては，塗った頂点が黒か否か判定する．
最悪計算量は，O(N + M + Q) < 10^7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m,q;

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    vector<vector<int> > adj(n);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);x--;y--;
        adj[y].push_back(x);
    }
    scanf("%d",&q);
    vector<bool> can_reach(n, false);
    auto bfs = [&](int now) -> void{
        if(can_reach[now])return;
        can_reach[now] = true;
        queue<int> que;
        que.push(now);
        while(que.size()){
            now = que.front();que.pop();
            for(int nxt : adj[now])if(can_reach[nxt] == false){
                can_reach[nxt] = true;
                que.push(nxt);
            }
        }
    };
    while(q--){
        scanf("%d%d",&i, &j);
        if(i == 1){
            bfs(j - 1);
        }else printf("%s\n", can_reach[j - 1] ? "Yes" : "No");
    }
    return 0;
}