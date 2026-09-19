/*アルゴリズムと工夫点(Not Covered Points/CPU: 214 ms Memory: 20020 KB  Length: 672 B)
平面走査で解く．
N個の点について，Xi の昇順に走査する．
この時，x ∈ [0, Xi] かつ y ∈ [0, Yi] となるような点の個数が分かればよい．
これは順次走査していくたびに，その時点で訪問した点の Yi を set で管理しておき，
Yi 未満の要素の個数が0か否かで判定ができる．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n;

int main(){
    int i, j;

    scanf("%d", &n);
    vector<P> ps(n);
    rep(i, n)scanf("%d%d", &ps[i].first, &ps[i].second);

    sort(ps.begin(), ps.end());
    set<int> ys;
    int ans = 0;
    for(P now : ps){
        auto [_, now_y] = now;
        auto it = ys.lower_bound(now_y);
        ans += it == ys.begin();

        ys.insert(now_y);
    }

    printf("%d\n", ans);
    return 0;
}