/*アルゴリズムと工夫点(Train Car/CPU: 1 ms Memory: 3612 KB  Length: 268 B)
N と K の値から解を計算して出力するだけ．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    printf("%d\n", n - k + 1);
    return 0;
}