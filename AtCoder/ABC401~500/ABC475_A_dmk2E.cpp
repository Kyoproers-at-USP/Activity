/*アルゴリズムと工夫点(mnclr/CPU: 1 ms Memory: 3724 KB  Length: 312 B)
末端文字以外は，'o'を隣に付けて出力すればよい．
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

    rep(i, s.length() - 1)printf("%co", s[i]);
    printf("%c\n", s[i]);
    return 0;
}