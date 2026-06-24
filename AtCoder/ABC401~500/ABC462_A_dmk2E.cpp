/*アルゴリズムと工夫点(Secret Numbers/CPU: 1 ms Memory: 3592 KB  Length: 294 B)
言われた通りにやる．
数値の文字かの判定は，文字コードの連番性を活かすと実装が楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;
    for(char c : s)if('0' <= c && c <= '9')putchar(c);
    puts("");
    return 0;
}