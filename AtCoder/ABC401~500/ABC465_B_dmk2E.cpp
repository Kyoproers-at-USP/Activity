/*アルゴリズムと工夫点(Parking 2/CPU: 1 ms Memory: 3788 KB  Length: 383 B)
[L, R] と [A, B] の共通範囲を求めてから，料金を計算すると楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x, y, l, r, a, b;

int main(){
    scanf("%d%d%d%d%d%d", &x, &y, &l, &r, &a, &b);
    
    int common = max(0, min(r, b) - max(l, a));
    printf("%d\n", common * x + (b - a - common) * y);
    return 0;
}