/*アルゴリズムと工夫点(Chocolate Bar Count/CPU: 1 ms Memory: 3784 KB  Length: 304 B)
最終的に残った板チョコの縦横の長さを元に，チョコレートの片数を出力すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define H 30
#define W 30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int b, r;

int main(){
    scanf("%d%d", &b, &r);
    printf("%d\n", (H - b) * (W - r));
    return 0;
}