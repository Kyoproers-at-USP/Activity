/*アルゴリズムと工夫点(A/CPU: 1 ms Memory: 3696 KB  Length: 313 B)
for文を用いていわれた通りに実装する．
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

    rep(i, s.length())if(s[i] != 'A')s[i] = '.';
    cout << s << endl;
    return 0;
}