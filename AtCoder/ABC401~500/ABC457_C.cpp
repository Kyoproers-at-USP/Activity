/*アルゴリズムと工夫点(Long Sequence/CPU: 40 ms Memory: 16172 KB  Length: 797 B)
配列1つ1つを単位とした，高速シミュレーションで解く．
B_{K} の値が，どの配列A に存在するかを，その配列のまとまりの長さを順次引きながら求めればよい．
最悪計算量は，O(ΣLi + N) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
ull k;

int main(){
    int i, j;
    scanf("%d%llu", &n, &k);
    k--;

    vector<vector<int> > a(n); 
    rep(i, n){
        int l;
        scanf("%d", &l);
        a[i] = vector<int>(l);
        rep(j, l)scanf("%d", &a[i][j]);
    }

    vector<ll> c(n);
    rep(i, n)scanf("%lld", &c[i]);

    int a_i = 0;
    while(k > 0){
        ll sum_len = c[a_i] * a[a_i].size();
        if(k >= sum_len){
            k -= sum_len;
            a_i++;
        }else{
            k %= a[a_i].size();
            break;
        }
    }
    printf("%d\n", a[a_i][k]);
    return 0;
}