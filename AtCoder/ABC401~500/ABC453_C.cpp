/*アルゴリズムと工夫点(Sneaking Glances/CPU: 28 ms Memory: 3936 KB  Length: 936 B)
ビット全探索で解く．
N回の移動それぞれにおいて，正負のどちらの方向に進むかは全てで，2 ^ N 通り．
N <= 20 と小さいので，全探索可能．
座標は，「(実際の座標) - 0.5」 とした，整数値として扱う．
最悪計算量は，O(N * 2 ^ N) ≒ 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;
    scanf("%d", &n);
    vector<int> l(n);
    rep(i, n)scanf("%d", &l[i]);

    auto judge = [](ll x1, ll x2) -> bool{
        ll smaller = min(x1, x2), larger = max(x1, x2);
        return smaller <= 0 && larger > 0;
    };
    auto calc = [&](int state) -> int{
        int i, cnt = 0;
        ll now_x = 0;
        rep(i, n){
            ll nxt_x;
            if((state >> i) & 1)nxt_x = now_x + l[i];
            else nxt_x = now_x - l[i];
            cnt += judge(/* x1 = */ now_x, /* x2 = */ nxt_x);
            swap(now_x, nxt_x);
        }
        return cnt;
    };
    int ans = 0;
    rep(i, 1 << n)ans = max(ans, calc(/* state = */ i));
    printf("%d\n", ans);
    return 0;
}