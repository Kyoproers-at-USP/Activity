/*アルゴリズムと工夫点(Variety/CPU: 36 ms Memory: 5296 KB  Length: 1026 B)
ソート + 2回走査で解く．
下記の貪欲法で解ける．
 <i>M種類の色の宝石の選び方は，各色の最大の価値を求めた時に，その最大価値が大きい順にM色選ぶ
 <ii>残りの K - M 個の宝石は，価値の大きい順に選ぶ
そこで，宝石について，(色，価値) の組のデータを，その価値の降順にソートして解く．
色ごとにどれを選択済みか，宝石ごとにどれを選択済みかを記録して置き，1回目の操作で<i>，2回目の操作で<ii>の処理を線形走査で行う．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n, k, m;

int main(){
    int i;
    
    scanf("%d%d%d", &n, &k, &m);
    vector<P> jewels(n);
    rep(i, n){
        scanf("%d%d", &jewels[i].first, &jewels[i].second);
        jewels[i].first--;
    }

    sort(jewels.rbegin(), jewels.rend(), [](P a, P b) -> bool{
        return a.second < b.second;
    });

    ll ans = 0;
    vector<bool> is_color_selected(n, false), is_selected(n, false);
    rep(i, n)if(is_color_selected[jewels[i].first] == false){
        is_color_selected[jewels[i].first] = is_selected[i] = true;
        ans += jewels[i].second;
        k--;m--;
        if(m == 0)break;
    }

    rep(i, n)if(k > 0 && is_selected[i] == false){
        ans += jewels[i].second;
        k--;
    }

    printf("%lld\n", ans);
    return 0;
}