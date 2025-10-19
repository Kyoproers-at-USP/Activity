/*アルゴリズムと工夫点(Most Frequent Substrings/CPU: 1 ms Memory: 3872 KB  Length: 658 B)
長さKの連続部分文字列で，最も出現頻度が高い文字列を出力する問題．
連想配列を用いて実装したため，O(N * log2(K)) < 10^4 となり高速．
*/
#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,k;
string s;

int main(){
    int i,ans = 0;
    scanf("%d%d",&n, &k);
    cin >> s;
    map<string, int> dict;
    rep(i, n - k + 1){
        string tmp = s.substr(i, k);
        dict[tmp]++;
        ans = max(ans, dict[tmp]);
    }
    printf("%d\n",ans);
    vector<string> tmp;
    for(auto p : dict)if(p.second == ans)tmp.push_back(p.first);
    rep(i, tmp.size() - 1)cout << tmp[i] << ' ';
    cout << tmp[i] << '\n';
    return 0;
}