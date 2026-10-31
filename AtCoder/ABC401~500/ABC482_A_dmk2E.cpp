/*アルゴリズムと工夫点(Nigiri/CPU: 1 ms Memory: 3576 KB  Length: 338 B)
'o' の数を数え上げて解を出力する．
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
    int cnt_o = 0;
    for(char c : s)if(c == 'o')cnt_o++;
    printf("%s\n", cnt_o % 2 == 1 ? "odd" : "even");
    return 0;
}