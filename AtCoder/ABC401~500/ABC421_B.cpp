/*アルゴリズムと工夫点(Fibonacci Reversed/CPU: 1 ms Memory: 3744 KB  Length: 519 B)
関数fを定義して，シミュレーション．
※バーチャル参加
*/
#include<iostream>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll x,y;

ll f(string x){
    reverse(x.begin(),x.end());
    ll num=0;
    for(char c:x){
        num*=10;
        num+=c-'0';
    }
    return num;
}

int main(){
    int i=8;
    cin>>x>>y;
    while(i--){
        ll tmp=y;
        y=f(to_string(x+y));
        x=tmp;
    }
    printf("%lld\n",y);
    return 0;
}