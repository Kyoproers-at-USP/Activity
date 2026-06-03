/*アルゴリズムと工夫点(Two Rings/CPU: 1 ms Memory: 3816 KB  Length: 643 B)
整数型の比較に持ち込んで判定する．
2つの円が共通点を持つか否かは，下記の条件式を満たすかで判定できる．
 (2つの円の半径の差の絶対値) <= (2円の中心間距離) <= (2つの円の半径の差の絶対値)
ただし，浮動小数点が絡むと誤差が生じ得るため，各辺2乗して比較する．
最悪計算量は，O(T) < 10 ^ 3 となり，十分高速．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int t;

ll norm(ll x, ll y){
    return x * x + y * y;
}

bool solve(){
    ll x_1, y_1, r_1, x_2, y_2, r_2;
    scanf("%lld%lld%lld%lld%lld%lld", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);

    ll dist_centers = norm(/* x = */ x_1 - x_2, /* y = */ y_1 - y_2);
    return (r_1 - r_2) * (r_1 - r_2) <= dist_centers && dist_centers <= (r_1 + r_2) * (r_1 + r_2);
}

int main(){
    scanf("%d", &t);
    while(t--)printf("%s\n", solve() ? "Yes" : "No");
    return 0;
}