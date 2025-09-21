/*アルゴリズムと工夫点(New Skill Acquired/CPU: 71 ms Memory: 14940 KB  Length: 1122 B)
多始点BFS で解く．
各スキルを頂点とする有向グラフを考える．もしスキルiからスキルjを習得可能な場合，頂点i->頂点jに辺を張る．
すると，習得済みのスキル群から到達可能な頂点数を出力すればよい．
最悪計算量は，O(N) < 10^7 となり高速．
※ バーチャル参加
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j;
    scanf("%d",&n);
    vector<vector<int> > adj(n);
    vector<int> start;
    rep(i,n){
        int a,b;
        scanf("%d%d",&a,&b);a--;b--;
        if(a < 0 || b < 0)start.push_back(i);
        else{
            adj[a].push_back(i);
            adj[b].push_back(i);
        }
    }
    auto bfs = [&](const vector<int>& start)->int{
        int i,ans = 0;
        queue<int> que;
        vector<int> vis(n,false);
        rep(i,start.size()){
            que.push(start[i]);
            vis[start[i]] = true;
            ans++;
        }
        while(que.size()){
            int now = que.front();que.pop();
            for(int nxt : adj[now])if(vis[nxt] == false){
                vis[nxt] = true;
                ans++;
                que.push(nxt);
            }
        }
        return ans;
    };
    printf("%d\n",bfs(start));
    return 0;
}