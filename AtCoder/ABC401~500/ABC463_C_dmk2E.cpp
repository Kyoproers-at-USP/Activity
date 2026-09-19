/*アルゴリズムと工夫点(Tallest at the Moment/CPU: 120 ms Memory: 7340 KB  Length: 908 B)
ソート + 二分探索 で解く．
クエリ T_i に対する解は，時刻 [T_i, L_N] である時の，最大の H を答えればよい．
これは，下記の max_h を前計算で求めておき，各クエリでは T_i より大きい最小の L_i を二分探索で求めることで，高速に計算可能．
 max_h[i] := (時刻 [L_i, L_N] である時の最大の H)
最悪計算量は，O((N + Q) * log2(N)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n, q;

int main(){
    int i, j;
    
    scanf("%d", &n);
    vector<P> taka(n);
    rep(i, n)scanf("%d%d", &taka[i].second, &taka[i].first);

    sort(taka.begin(), taka.end());
    const int MIN_H = 0;
    vector<int> range_max_h(n, MIN_H);
    range_max_h[n - 1] = taka[n - 1].second;
    for(i = n - 2;i >= 0;i--)range_max_h[i] = max(range_max_h[i + 1], taka[i].second);

    scanf("%d", &q);
    const int MAX_H = (int)(1e9) + 1;
    while(q--){
        int t;
        scanf("%d", &t);
        int upb_id = upper_bound(taka.begin(), taka.end(), P(t, MAX_H)) - taka.begin();
        printf("%d\n", range_max_h[upb_id]);
    }
    return 0;
}