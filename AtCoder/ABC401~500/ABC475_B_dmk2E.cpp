/*アルゴリズムと工夫点(Change/CPU: 1 ms Memory: 3848 KB  Length: 634 B)
各買い物でのお釣りに応じた1~100円の硬貨の枚数を合計していけばよい．
合計枚数が最小となるようにするには，値の大きい硬貨の枚数から順に数えるようにすればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;
    scanf("%d", &n);
    
    const int BASE = 1000;
    int sum_one = 0, sum_ten = 0, sum_hun = 0;
    rep(i, n){
        int a;
        scanf("%d", &a);

        int oturi = (BASE - (a % BASE)) % BASE;
        sum_hun += oturi / 100;

        oturi %= 100;
        sum_ten += oturi / 10;

        oturi %= 10;
        sum_one += oturi;
    }

    printf("%d %d %d\n", sum_one, sum_ten, sum_hun);
    return 0;
}