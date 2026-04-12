/*アルゴリズムと工夫点(Trimo/CPU: 1 ms Memory: 3636 KB  Length: 339 B)
'o' でない一番左端の所からの部分文字列を出力すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(){
    int i;
    cin >> n >> s;
    rep(i, s.length())if(s[i] != 'o')break;
    cout << s.substr(i, s.length()) << endl;
    return 0;
}