/*アルゴリズムと工夫点(Wannabe Zombie/CPU: 19 ms Memory: 4388 KB  Length: 647 B)
貪欲法で解く．
最適な各人の移動方法は，下記の2パターンのどちらかであるため，最小の時間の方を出力する．
 ・人 k より左側の人は全員右方向に進み，人 k 含むそうでない人は左方向に進む
 ・人 k より右側の人は全員右方向に進み，人 k 含むそうでない人は左方向に進む
どちらの場合も，人 k と逆方向に進む人の中で最も人 k に近い人が，人 k が進む方向と逆側の人をゾンビにできるため，
人 k が途中で進む方向を変える必要はない．
そこで，人1, 人k-1, 人k, 人k+1, 人N の座標値の差分を用いることで解を求めることができる．
ここで N = 1 である時，解が 0 になるというコーナーケースに注意．
最悪計算量は，O(N) < 10 ^ 6 となり，高速．
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
    vector<int> x(n);
    rep(i, n)scanf("%d", &x[i]);

    if(n == 1){
        puts("0");
        return 0;
    }

    const int INF = 2e9;
    rep(i, n){
        int ans = i + 1 < n ? max((x[n - 1] - x[i]) / 2, (x[i + 1] - x[0]) / 2) : INF;
        ans = min(ans, i - 1 >= 0 ? max((x[i] - x[0]) / 2, (x[n - 1] - x[i - 1]) / 2) : INF);

        printf("%d\n", ans);
    }
    return 0;
}