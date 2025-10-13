/*アルゴリズムと工夫点(Bipartize/CPU: 1 ms Memory: 3920 KB  Length: 701 B)
ビット全探索で解く．
頂点をどう塗り分けるかを固定すれば，削除すべき辺の最小個数が一意に定まるため，頂点の塗り分け方を全探索する．
最悪計算量は，O(M * 2^(N)) < 10^6 となり十分高速。
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i, ans;
    scanf("%d%d",&n,&m);
    vector<vector<bool> > adj(n,vector<bool>(n,false));
    ans = m;
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);u--;v--;
        adj[u][v] = adj[v][u] = true;
    }
    auto cal = [&](int state)->int{
        int i,j,ans = 0;
        rep(i,n)rep(j,i)if(adj[j][i])ans += !(((state >> j) & 1) ^ ((state >> i) & 1));
        return ans;
    };
    rep(i,1 << n)ans = min(ans, cal(i));
    printf("%d\n",ans);
    return 0;
}