/*アルゴリズムと工夫点(Placing Rooks/CPU: 38 ms Memory: 8264 KB  Length: 774 B)
時系列を導入して解く．
各行各列について，最後に削除された時間を記録しておく．
データ (R_{i}, C_{i}) が与えられた場合，R_{i} 行，C_{i} 列はそれぞれ時間 i に削除されたと捉え，
時間 i + 1 にコマがR_{i} 行 C_{i} 列の位置に配置されたと考える．
すると各コマはその配置時間が，配置するマスが削除された時間よりも後の場合のみ，最後まで残っているコマとなる．
最悪計算量は，O(N + M) < 10 ^ 7 となり，高速．
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
    const int NIL = -1;
    vector<int> latest_rm_t_row(n, NIL), latest_rm_t_col(n, NIL), r(m), c(m);
    rep(i, m){
        scanf("%d%d", &r[i], &c[i]);
        r[i]--;c[i]--;
        latest_rm_t_row[r[i]] = max(latest_rm_t_row[r[i]], i);
        latest_rm_t_col[c[i]] = max(latest_rm_t_col[c[i]], i);
    }

    int ans = 0;
    rep(i, m){
        int latest_rm_t = max(latest_rm_t_row[r[i]], latest_rm_t_col[c[i]]);
        ans += i + 1 > latest_rm_t;
    }

    printf("%d\n", ans);
    return 0;
}
