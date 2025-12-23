/*アルゴリズムと工夫点(Feet/CPU: 1 ms Memory: 3892 KB  Length: 263 B)
12 * A + B を出力する．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a,b;

int main(){
    scanf("%d%d", &a, &b);
    printf("%d\n", 12 * a + b);
    return 0;
}