/*アルゴリズムと工夫点(Deconstruct Chocolate/CPU: 1 ms Memory: 3928 KB  Length: 576 B)
シミュレーションで解く．
各タイミングにおけるチョコレートの高さと幅の値を保持しておけばよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w, q;

int main(){
    scanf("%d%d%d", &h, &w, &q);
    while(q--){
        int op;
        scanf("%d", &op);
        if(op == 1){
            int r;
            scanf("%d", &r);
            printf("%d\n", r * w);
            h -= r;
        }else{
            int c;
            scanf("%d", &c);
            printf("%d\n", c * h);
            w -= c;
        }
    }
    return 0;
}