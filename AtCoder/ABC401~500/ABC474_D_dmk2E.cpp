/*アルゴリズムと工夫点(Outweigh/CPU: 19 ms Memory: 5472 KB  Length: 868 B)
条件となる比較式の厳密な評価を行って解く．
高橋君と青木君の石の重みの総和の差を最大にするには，下記のように石の重さを調整すればよい．
 ・a_i < b_i となる石の重みを 1
 ・それ以外では，10 ^ 18 
上記のように石の重さを決めた場合の総和の差の値が，0以上であるかを判定すればよい．
最悪計算量は，O(N) < 10 ^ 6 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_W (ll)(1e18)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;

    scanf("%d", &n);
    vector<int> a(n), b(n);
    rep(i, n)scanf("%d", &a[i]);
    rep(i, n)scanf("%d", &b[i]);

    ll min_minus_sum = 0, greater_diff_sum = 0;
    vector<ll> ans;
    rep(i, n){
        if(a[i] < b[i]){
            min_minus_sum += b[i] - a[i];
            ans.push_back(1);
        }else{
            greater_diff_sum += a[i] - b[i];
            ans.push_back(MAX_W);
        }
    }

    if(greater_diff_sum > min_minus_sum / MAX_W){
        puts("Yes");
        rep(i, n - 1)printf("%lld ", ans[i]);
        printf("%lld\n", ans[i]);
    }else puts("No");
    return 0;
}