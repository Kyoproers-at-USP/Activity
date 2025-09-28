/*アルゴリズムと工夫点(Rotate and Sum Query/CPU: 84 ms Memory: 5224 KB  Length: 884 B)
先頭位置管理+累積和 で解く．
「先頭要素を末尾に移動させる」という操作は，配列の先頭位置を変更するのと同じである．
また列の総和を高速に求めるには，累積和を用いればよい．
最悪計算量は，O(N) < 10^7 となり高速．
※バーチャル参加
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,q;

int main(){
    int i,j,top = 0;
    scanf("%d%d",&n,&q);
    vector<ll> sum_a(n+1,0);
    rep(i,n){
        scanf("%lld",&sum_a[i+1]);
        sum_a[i+1] += sum_a[i];
    }
    auto calc = [&](int l,int r)->ll{
        if(l <= r)return sum_a[r+1]-sum_a[l];
        swap(l,r);
        l = (l+1)%n;
        return sum_a[n]-(sum_a[r]-sum_a[l]);
    };
    while(q--){
        scanf("%d",&i);
        if(i == 1){
            scanf("%d",&i);
            top = (top+i)%n;
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            l = (l+top-1)%n;
            r = (r+top-1)%n;
            printf("%lld\n",calc(l,r));
        }
    }
    return 0;
}