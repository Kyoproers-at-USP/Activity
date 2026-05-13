/*アルゴリズムと工夫点(Raise Minimum/CPU: 54 ms Memory: 5176 KB  Length: 935 B)
二分探索で解く．
min_a ∈ [0, A_{1} + K] にて，「min(A_{i}) を min_a 以上にできるか」という条件を考えると，
ある閾値を境目にして，条件を満たす / 満たさない 2範囲があり，単調性が存在する．
また，条件を満たすかの判定は O(N) で可能．
従って，最悪計算量は，O(N * log2(A_{1} + K)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll k;

int main(){
    int i, j;

    scanf("%d%lld", &n, &k);
    vector<ll> a(n);
    rep(i, n)scanf("%lld", &a[i]);

    auto judge = [&](ll min_a) -> bool{
        int i;

        ll rest_k = k;
        rep(i, n){
            ll diff_value = max(0LL, min_a - a[i]);
            ll diff_count = (diff_value + i) / (i + 1);
            if(diff_count > rest_k)return false;
            rest_k -= diff_count;
        }
        return true;
    };

    const ll MAX_MIN_A = 2e18;
    ll left = 0, right = MAX_MIN_A + 1;
    while(left < right){
        ll mid = (left + right) / 2;
        if(judge(/* min_a = */ mid))left = mid + 1;
        else right = mid;
    }
    printf("%lld\n", left - 1);
    return 0;
}