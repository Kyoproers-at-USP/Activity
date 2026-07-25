/*アルゴリズムと工夫点(Representative Balls/CPU: 1 ms Memory: 3844 KB  Length: 574 B)
色毎のボールの大きさの最大値を，線型探索的に求めればよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    
    scanf("%d%d", &n, &m);
    const int NIL = -1;
    vector<int> color_to_max_s(m, NIL);
    while(n--){
        int c, s;
        scanf("%d%d", &c, &s);
        color_to_max_s[c - 1] = max(color_to_max_s[c - 1], s);
    }

    rep(i, m - 1)printf("%d ", color_to_max_s[i]);
    printf("%d\n", color_to_max_s[i]);
    return 0;
}