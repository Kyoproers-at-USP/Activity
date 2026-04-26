/*アルゴリズムと工夫点(Straw Millionaire/CPU: 85 ms Memory: 19888 KB  Length: 918 B)
BFS で解く．
各アイテムを頂点とし，そのアイテムを渡すことで得られるアイテムを表す頂点に向かって有向辺を張ったグラフを考える．
このグラフ上で幅優先探索を行い，到達可能な頂点数を数え上げればよい．
最悪計算量は，O(N + M) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    vector<vector<int> > adj(n);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);a--;b--;
        adj[a].push_back(b);
    }

    auto bfs = [&]() -> int{
        vector<bool> vis(n, false);
        queue<int> que;

        que.push(0);
        vis[0] = true;
        int ans = 1;
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

    printf("%d\n", bfs());
    return 0;
}