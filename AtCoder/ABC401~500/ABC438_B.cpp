/*アルゴリズムと工夫点(Substring 2/CPU: 1 ms Memory: 3900 KB  Length: 589 B)
Sのどの部分をTにするか全探索する．
最悪計算量は，O(N * M) < 10^5 となり十分高速．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;
string s, t;

int main(){
    int i,j,ans = 1e9;
    scanf("%d%d", &n, &m);
    cin >> s >> t;
    auto calc = [&](int top) -> int{
        int i, ans = 0;
        rep(i, m){
            int len = abs(s[top + i] - t[i]);
            ans += t[i] <= s[top + i] ? len : 10 - len;
        }
        return ans;
    };
    rep(i, n - m + 1)ans = min(ans, calc(i));
    printf("%d\n", ans);
    return 0;
}