/*アルゴリズムと工夫点(Bento Packing/CPU: 8 ms Memory: 3876 KB  Length: 525 B)
ビット全探索で解く．
どの弁当を選ぶかを全探索し，条件を満たす場合の美味しさの最大値を求めればよい．
最悪計算量は，O(N * 2 ^ (N)) < 10 ^ 8 となり，間に合う．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, w;

int main(){
    int i, j;

    scanf("%d%d", &n, &w);
    vector<int> a(n), b(n);
    rep(i, n)scanf("%d%d", &a[i], &b[i]);

    auto calc = [&](int state) -> pair<ll, ll>{
        ll sum_a = 0, sum_w = 0;

        int i;
        rep(i, n)if((state >> i) & 1){
            sum_a += a[i];
            sum_w += b[i];
        }

        return pair<ll, ll>(sum_a, sum_w);
    };
    ll ans = 0;
    rep(i, 1 << n){
        auto [sum_a, sum_w] = calc(/* state = */ i);
        if(sum_w <= w)ans = max(ans, sum_a);
    }

    printf("%lld\n", ans);
    return 0;
}