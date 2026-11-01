/*アルゴリズムと工夫点(Autopilot/CPU: 42 ms Memory: 15268 KB  Length: 1278 B)
0-1 BFS で解く．
惑星と航路をそれぞれ頂点と辺とし，燃料を辺の重みと捉えた有向グラフ上で，惑星 S から 惑星 T への最短経路を求めればよい．
辺の重みは 0 or 1 であるため、0 - 1 BFS で解ける．
コストが 0 の場合の遷移を高速に行うため，隣接リストを予め頂点番号の昇順にソートしておくこと．
最悪計算量は O(N * log(M) + M) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m, s, t;

int main(){
    int i, j;

    scanf("%d%d%d%d", &n, &m, &s, &t);s--;t--;
    vector<vector<int> > adj(n);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;

        adj[a].push_back(b);
    }
    rep(i, n)sort(adj[i].begin(), adj[i].end());

    const int NIL = 2 * n;
    vector<int> dist(n, NIL);
    auto bfs = [&](int start) -> void{
        deque<int> deq;

        dist[start] = 0;
        deq.push_back(start);
        while(deq.size()){
            int now = deq.front();deq.pop_front();
            if(adj[now].size() == 0)continue;

            if(dist[adj[now][0]] > dist[now]){
                deq.push_front(adj[now][0]);
                dist[adj[now][0]] = dist[now];
            }
            for(int nxt : adj[now])if(dist[nxt] > dist[now] + 1){
                deq.push_back(nxt);
                dist[nxt] = dist[now] + 1;
            }
        }
    };
    bfs(/* start = */ s);

    printf("%d\n", dist[t] == NIL ? -1 : dist[t]);
    return 0;
}