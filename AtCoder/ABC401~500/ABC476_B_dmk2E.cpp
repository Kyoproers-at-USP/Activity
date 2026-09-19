/*アルゴリズムと工夫点(Wild Card/CPU: 1 ms Memory: 3620 KB  Length: 354 B)
前の文字から順に適切な条件判定をして解く．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s, t;

int main(){
    int i;
    cin >> n >> s >> t;

    rep(i, n)if(t[i] != '*' && s[i] != t[i])break;
    printf("%s\n", i == n ? "Yes" : "No");
    return 0;
}