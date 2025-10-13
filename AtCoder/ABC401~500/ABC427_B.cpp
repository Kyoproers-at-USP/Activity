/*アルゴリズムと工夫点(Sum of Digits Sequence/CPU: 1 ms Memory: 3924 KB  Length: 518 B)
シミュレーションして解く．
各桁の和は，一旦文字列を経由すると楽．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

ll f(ll x){
    int i;
    ll ans = 0;
    string tmp = to_string(x);
    rep(i,tmp.size())ans += tmp[i] - '0';
    return ans;
}

int main(){
    int i,j;
    ll last_a = 1;
    scanf("%d",&n);
    while(--n){
        ll nxt_a = last_a + f(last_a);
        swap(last_a, nxt_a);
    }
    printf("%lld\n",last_a);
    return 0;
}