/*アルゴリズムと工夫点(Chompers/CPU: 1 ms Memory: 3652 KB  Length: 308 B)
取り除かれていない部分だけを，逐次出力すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;
int n;

int main(){
    cin >> s >> n;
    for(int i = n;i < s.length() - n;i++)putchar(s[i]);
    puts("");
    return 0;
}