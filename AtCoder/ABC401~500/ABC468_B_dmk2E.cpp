/*アルゴリズムと工夫点(Corridor Watch/CPU: 1 ms Memory: 3824 KB  Length: 609 B)
imos 法で解く．
各マスについて，何人のガードマンの監視が入っているかを保持する配列を計算し，
値が「0」となるマスの個数を数え上げればよい．
最悪計算量は，O(M) < 10 ^ 3 となり，十分高速．
※ 愚直な O(M * D) 解法よりは実装が楽と判断し，本方針を採用した
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int m, d;
string s;

int main(){
    int i, j;

    scanf("%d%d", &m, &d);
    cin >> s;
    vector<int> imos(m + 1, 0);

    rep(i, m)if(s[i] == 'G'){
        int begin = max(0, i - d);
        int end = min(m, i + d + 1);
        imos[begin]++;
        imos[end]--;
    }
    rep(i, m)imos[i + 1] += imos[i];

    int ans = 0;
    rep(i, m)ans += imos[i] == 0;
    printf("%d\n", ans);
    return 0;
}