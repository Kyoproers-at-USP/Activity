/*アルゴリズムと工夫点(C Stands for Center/CPU: 9 ms Memory: 4340 KB  Length: 376 B)
中央位置となる'C'を全探索して解く．
ある位置にいる'C'が，条件を満たす部分文字列となるためには，そのf'C'を区切り文字とした，
両側の部分文字列の長さによって決まる．
短いの方の長さの数だけ，条件を満たす部分文字列を作成できるため，この数の総和を求めればよい．
最悪計算量は，O(|S|) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int i;
    cin >> s;

    ll ans = 0;
    rep(i, s.length())if(s[i] == 'C')
        ans += min(i, (int)s.length() - i - 1) + 1;

    printf("%lld\n", ans);
    return 0;
}