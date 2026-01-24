/*アルゴリズムと工夫点(Paid Walk/CPU: 60 ms Memory: 23604 KB  Length: 1264 B)
BFS (DFS でも可)で解く．
出次数，L の数が小さいため，頂点1からあり得るL回の移動を全列挙すればよい．
最悪計算量は，O(4 ^ L) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Data{
    int now, cnt, sum_c;

    Data(int now = 0, int cnt = 0, int sum_c = 0):now(now), cnt(cnt), sum_c(sum_c){}
};

struct Edge{
    int to, c;

    Edge(int to = 0, int c = 0):to(to), c(c){}
};

int n, m, l, s, t;

int main(){
    int i, j;
    scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
    vector<vector<Edge> > adj(n);
    while(m--){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);u--;v--;
        adj[u].push_back(Edge(v, c));
    }
    queue<Data> que;
    vector<bool> is_valid(n, false);
    que.push(Data());
    while(que.size()){
        Data now = que.front();que.pop();
        if(now.cnt == l){
            if(s <= now.sum_c && now.sum_c <= t)is_valid[now.now] = true;
            continue;
        }
        for(auto [to, c] : adj[now.now])que.push(Data(to, now.cnt + 1, now.sum_c + c));
    }
    vector<int> tmp;
    rep(i, n)if(is_valid[i])tmp.push_back(i + 1);
    if(tmp.size()){
        rep(i, tmp.size() - 1)printf("%d ", tmp[i]);
        printf("%d\n", tmp[i]);
    }
    return 0;
}