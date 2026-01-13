/*アルゴリズムと工夫点(Octave/CPU: 1 ms Memory: 3896 KB  Length: 278 B)
X * 2 ^ (Y) を出力する．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x, y;

int main(){
    scanf("%d%d", &x, &y);
    while(y--)x *= 2;
    printf("%d\n", x);
    return 0;
}