/*アルゴリズムと工夫点(Break a Stick/CPU: 2 ms Memory: 3804 KB  Length: 547 B)
全探索で解く．
切れ込みを折り方を全て試し，2本の長さの差の絶対値それぞれ求め，最小の値を探索すればよい．
折る箇所を先頭から一つずつずらしていく方針で実装したため，O(N) で求まる．
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
    int i;

    scanf("%d", &n);
    vector<int> l(n);
    int sum_l = 0;
    rep(i, n){
        scanf("%d", &l[i]);
        sum_l += l[i];
    }

    int ans = sum_l, now_sum = 0;
    rep(i, n - 1){
        now_sum += l[i];
        ans = min(ans, abs(sum_l - 2 * now_sum));
    }

    printf("%d\n", ans);
    return 0;
}