/*アルゴリズムと工夫点(Not Adjacent/CPU: 6 ms Memory: 4120 KB  Length: 510 B)
同じ文字が隣り合わない区間 [l, r) を順に求めていき，各区間から作られる部分文字列数の総和を求めればよい．
最悪計算量は，O(N) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;

    int r;
    ll ans = 0;
    for(int l = 0, r = 1;l < s.length();r++){
        while(r < s.length() && s[r] != s[r - 1])r++;
        ans = (ans + ((ll)r - l + 1) * (r - l) / 2) % MOD;
        l = r;
    }

    printf("%lld\n", ans);
    return 0;
}