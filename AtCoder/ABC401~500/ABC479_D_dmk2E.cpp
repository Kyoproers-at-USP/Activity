/*アルゴリズムと工夫点(Back and Forth Distance/CPU: 80 ms Memory: 8260 KB  Length: 1004 B)
s < t or s > t で場合分けして解く．
問題の性質により，同じ方向に二度も移動するのはコストが無駄にかかるため，
s -> t への道順は下記の2通りとなる．
 <i> s -> t に直接移動する
 <ii> s -> t とは違う方向のマスに一回だけ移動してから，t に向かう
<ii> の場合，s から一度移動する方向の端までの範囲において，
反対方向への移動にかかるコストが最小となるマスが分かればよい．
従って，L については右端からの累積max, R については左端からの累積min を前処理で求めておけば，
各クエリに O(1) で回答可能．
最悪計算量は，O(N + Q) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, q;

int main(){
    int i, j;

    scanf("%d%d", &n, &q);
    const int INF = (1e9) + 1;
    vector<int> l(n), r(n);
    l[0] = INF;
    rep(i, n - 1)scanf("%d", &l[i + 1]);
    r[n - 1] = INF;
    rep(i, n - 1)scanf("%d", &r[i]);

    vector<int> min_l(n), min_r(n);
    min_r[0] = r[0];
    rep(i, n - 1)min_r[i + 1] = min(min_r[i], r[i + 1]);
    min_r[n - 1] = INF;

    min_l[n - 1] = l[n - 1];
    for(i = n - 2;i >= 0;i--)min_l[i] = min(min_l[i + 1], l[i]);
    min_l[0] = INF;

    while(q--){
        int s, t;
        scanf("%d%d", &s, &t);
        s--;t--;

        printf("%d\n", s < t ? 
                       min(r[s], l[s] + (s > 0 ? min_r[s - 1] : INF)) : 
                       min(l[s], r[s] + (s < n - 1 ? min_l[s + 1] : INF))
        );
    }
    return 0;
}