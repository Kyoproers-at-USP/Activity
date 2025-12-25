/*アルゴリズムと工夫点(Sum of Differences/CPU: 71 ms Memory: 6028 KB  Length: 818 B)
尺取り法で解く．
Ai > Bj となるBjの個数nとすると，iの値を固定した時の Σ|Ai - Bj| を求めると，
n * Ai - Σ Bj + (sum_b - Σ Bj) - (m - n) * Ai = n * Ai - 2 * Σ Bj + sum_b - (m - n) * Ai
となるため，1 <= i <= N の値の総和を求めればよい．
A と B はそれぞれ昇順にソートしておくと，Σ Bj を尺取り法で高速に求められる．
よって，最悪計算量は，O(N + M) < 10^7 となり高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i,j;
    ll nxt_b = 0, ans = 0, sum_b = 0, smaller_sum_b = 0;
    scanf("%d%d", &n, &m);
    vector<int> a(n), b(m);
    rep(i,n)scanf("%d", &a[i]);
    rep(i,m){
        scanf("%d", &b[i]);
        sum_b += b[i];
    }
    sort(a.begin(), a.end());sort(b.begin(), b.end());
    rep(i,n){
        while(nxt_b < m && a[i] > b[nxt_b]){
            smaller_sum_b += b[nxt_b];
            nxt_b++;
        }
        ans = (ans + nxt_b * a[i] - 2 * smaller_sum_b + sum_b - (m - nxt_b) * a[i]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}