/*アルゴリズムと工夫点(Old Maid/CPU: 1 ms Memory: 3808 KB  Length: 521 B)
カードに書かれている値毎の頻度表を作って解く．
操作では2枚ずつカードが減っていくため，カードに書かれた整数値毎のグループで見ると，
最終的に残る数は，元々の枚数が奇数なら1枚，そうでないなら0枚となる．
よって値毎の頻度表を作っておき，適切に操作後の総和を求めれば，解を求めることができる．
従って最悪計算量は，O(N + max(Ai)) < 10 ^ 4 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_A 100
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;

    scanf("%d", &n);
    vector<int> val_to_cnt(MAX_A + 1, 0);
    rep(i, n){
        int a;
        scanf("%d", &a);
        val_to_cnt[a]++;
    }
    
    int ans = 0;
    rep(i, MAX_A + 1)ans += i * (val_to_cnt[i] % 2);

    printf("%d\n", ans);
    return 0;
}