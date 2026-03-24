/*アルゴリズムと工夫点(Make Target 2/CPU: 13 ms Memory: 3864 KB  Length: 1008 B)
段階的に共通範囲を数え上げて解く．
まず，L以上R以下 かつ 2の倍数となるxの値について，D以上U以下となるyの値の内，(x, y)が黒く塗られた点の数を数え上げる．
その後，D以上U以下 かつ 2の倍数となるyの値について，L以上D以下となるxの値の内，(x, y)が黒く塗られた点の数を数え上げる．
この時，重複に注意すること．
最悪計算量は，O(R - L + U - D) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int l, r, d, u;

int main(){
    int i, j;
    ll ans = 0;
    scanf("%d%d%d%d", &l, &r, &d, &u);
    for(int now_x = (l < 0 ? (l / 2) : ((l + 1) / 2)) * 2;now_x <= r;now_x += 2){
        // [d, u] && [-abs(now_x), abs(now_x)]
        int len = min(u, abs(now_x)) - max(d, -abs(now_x));
        ans += len >= 0 ? len + 1 : 0;
    }
    for(int now_y = (d < 0 ? (d / 2) : ((d + 1) / 2)) * 2;now_y <= u;now_y += 2){
        // [l, r] && [-abs(now_y), abs(now_y)]
        int first_x = max(l, -abs(now_y));
        int last_x = min(r, abs(now_y));
        if(last_x >= first_x){
            ans += last_x - first_x + 1;
            ans -= first_x == -abs(now_y);
            ans -= last_x == abs(now_y);
        }
    }
    ans += (l <= 0 && 0 <= r && d <= 0 && 0 <= u) ? 1 : 0;
    printf("%lld\n", ans);
    return 0;
}