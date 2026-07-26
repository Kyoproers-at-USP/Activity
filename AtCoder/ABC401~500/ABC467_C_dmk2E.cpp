/*アルゴリズムと工夫点(Adjacent Sums (easy)/CPU: 20 ms Memory: 5128 KB  Length: 795 B)
動的計画法で解く．
A_{i} の値は，直前の A_{i + 1} の値に依存する．
そこで，下記のDPテーブルを埋めていけばよい．
 dp[i][j] := A[1, i] までの値が確定している状態で，A[i] == j である時の，最小の操作回数
最悪計算量は，O(N * M) = O(N * 2) < 10 ^ 6 となり，高速．
※ 公式解説によると，A_{1} が決まると全ての要素の値が決まることから，
※ A_{1} の値が 0, 1 である時の2通りについて探索するだけで良かった模様
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;

    scanf("%d%d", &n, &m);
    vector<int> a(n), b(n - 1);
    rep(i, n)scanf("%d", &a[i]);
    rep(i, n - 1)scanf("%d", &b[i]);

    vector<int> dp(2);
    dp[a[0]] = 0;dp[!a[0]] = 1;
    rep(i, n - 1){
        vector<int> nxt(2);

        if(b[i]){
            nxt[0] = dp[1] + (a[i + 1] == 1);
            nxt[1] = dp[0] + (a[i + 1] == 0);
        }else{
            nxt[0] = dp[0] + (a[i + 1] == 1);
            nxt[1] = dp[1] + (a[i + 1] == 0);
        }

        swap(dp, nxt);
    }

    printf("%d\n", min(dp[0], dp[1]));
    return 0;
}