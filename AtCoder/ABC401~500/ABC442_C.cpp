/*アルゴリズムと工夫点(Peer Review/CPU: 58 ms Memory: 14168 KB  Length: 684 B)
隣接リストで解く．
各研究者ごとに利害関係にある人数を数え上げ，解を計算する．
最悪計算量は，O(N + M) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i;
    scanf("%d%d", &n, &m);
    vector<vector<int> > adj(n);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, n - 1){
        ll valid = n - (int)adj[i].size() - 1;
        printf("%lld ", valid * (valid - 1) * (valid - 2) / 6);
    }
    ll valid = n - (int)adj[i].size() - 1;
    printf("%lld\n", valid * (valid - 1) * (valid - 2) / 6);
    return 0;
}