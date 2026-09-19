/*アルゴリズムと工夫点(Automat/CPU: 52 ms Memory: 6836 KB  Length: 1226 B)
累積和 + 二分探索で解く．
問題文の設定より，下記の性質がある．
 ・デザート販売機では1ドル紙幣もKドル紙幣もどちらも使用できるので，
   値段の昇順に合計金額を超えるまで買い続けた場合の個数が，購入できる商品数の最大値となる
従って購入するドリンク数を全探索すればよい．
デザート販売機利用時のお金は多い方がいいので，ドリンク販売機での購入も，値段の小さい順に行う．
ドリンク販売機での購入後，デザートをいくつか買えるかの計算では，前処理で値段の累積和を作成し，
二分探索を行えばよい．
最悪計算量は，O(M * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;
ll k, x, y;

int main(){
    int i, j;
    
    scanf("%d%d%lld%lld%lld", &n, &m, &k, &x, &y);
    vector<int> a(n), b(m);
    rep(i, n)scanf("%d", &a[i]);
    rep(i, m)scanf("%d", &b[i]);

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    vector<ll> sum_a(n + 1);
    sum_a[0] = 0;
    rep(i, n)sum_a[i + 1] = sum_a[i] + a[i];

    auto calcMax = [&](ll sum_doller) -> int{
        return (int)(upper_bound(sum_a.begin(), sum_a.end(), sum_doller) - sum_a.begin()) - 1;
    };
    int ans = calcMax(/* sum_doller = */ x + k * y);
    int sum_drink = 0;
    rep(i, m){
        if(y == 0)break;
        
        int k_use_cnt = (b[i] + k - 1) / k;
        if(k_use_cnt <= y){
            x += k * k_use_cnt - b[i];
            y -= k_use_cnt;
            sum_drink++;
        }else{
            x += k * y;
            y = 0;
        }

        ans = max(ans, sum_drink + calcMax(/* sum_doller = */ x + k * y));
    }

    printf("%d\n", ans);
    return 0;
}