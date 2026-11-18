/*アルゴリズムと工夫点(Nineball/CPU: 1 ms Memory: 3860 KB  Length: 516 B)
9 の存在判定と，配列 A に含まれる要素の中で最小の値の探索を同時に行えばよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_A 9
#define NIL -1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int k;

int main(){
    bool is_nine_exist = false;
    int min_a = MAX_A + 1;

    scanf("%d", &k);
    while(k--){
        int a;
        scanf("%d", &a);

        if(a == 9)is_nine_exist = true;
        min_a = min(min_a, a);
    }

    printf("%d\n", is_nine_exist ? min_a : NIL);
    return 0;
}