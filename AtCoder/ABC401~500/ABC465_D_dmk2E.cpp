/*アルゴリズムと工夫点(X to Y/CPU: 55 ms Memory: 3812 KB  Length: 477 B)
LCA (Lowest Common Ancestor) の考えを用いて解く．
各整数x を頂点とすると，行える操作によって2整数間の置き換えは可変であるから，
置き換えられる整数群を辺でつなぐと，K分木となる．
X = Y とするために必要な操作回数の最小値とは，頂点X と 頂点Y 間の木上の経路長であり，
これは2頂点間のLCAを求めればよい．
最悪計算量は，O(T * (logk(X) + logk(Y))) < O(T * (log(X) + log(Y)) / log(K)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int t;

int solve(){
    ll x, y, k;
    scanf("%lld%lld%lld", &x, &y, &k);

    int ans = 0;
    while(x != y){
        if(x > y)x = x / k;
        else y = y / k;
        ans++;
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    while(t--)printf("%d\n", solve());
    return 0;
}