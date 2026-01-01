/*アルゴリズムと工夫点(First Contest of the Year/CPU: 1 ms Memory: 3848 KB  Length: 270 B)
計算式を考えて，出力．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int d,f;

int main(){
    scanf("%d%d", &d, &f);
    printf("%d\n", 7 - ((d - f) % 7));
    return 0;
}