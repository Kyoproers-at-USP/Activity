/*アルゴリズムと工夫点(The Big Two/CPU: 23 ms Memory: 6000 KB  Length: 981 B)
グラフの考えを用いて解く．
各プレイヤを頂点，各トーナメント戦で勝ち上がったプレイヤ2人を辺でつないだグラフを考える．
条件を満たす2ペアとは，(その2頂点と繋がっている辺群) = (グラフ上の全ての辺群) となるようなものである．
またそのような2ペアとは，最初の1ペアに着目した時，その2頂点のどちらかを必ず含む．
従ってこの2頂点をペアの片方に持つ場合で考え，条件を満たす2ペアを全探索すればよい．
最悪計算量は O(N + M) < 10 ^ 6 となり，高速。
*/
#include<iostream>
#include<vector>
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
    vector<P> edges;
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        edges.push_back(P(a, b));
    }

    int ans = 0;
    for(int vertex : {edges[0].first, edges[0].second}){
        vector<int> connected_cnt(n, 0);
        connected_cnt[vertex]--;

        if(vertex == edges[0].second)connected_cnt[edges[0].first]--;
        
        int num = 0;
        for(auto [a, b] : edges){
            if(a == vertex || b == vertex)continue;
            
            num++;
            connected_cnt[a]++;connected_cnt[b]++;
        }

        rep(i, n)ans += connected_cnt[i] == num;
    }

    printf("%d\n", ans);
    return 0;
}