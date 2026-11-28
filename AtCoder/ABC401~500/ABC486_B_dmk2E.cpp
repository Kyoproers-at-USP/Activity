/*アルゴリズムと工夫点(Player Substitution/CPU: 1 ms Memory: 3900 KB  Length: 702 B)
選手毎に出場中か控えかを管理しつつ，シミュレーションを行えばよい．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_A 100
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i;

    scanf("%d%d", &n, &m);
    vector<bool> is_playing(MAX_A, false);
    rep(i, n){
        int a;
        scanf("%d", &a);
        is_playing[a - 1] = true;
    }

    while(m--){
        int x, y;
        scanf("%d%d", &x, &y);
        x--;y--;
        is_playing[x] = false;
        is_playing[y] = true;
    }

    rep(i, MAX_A)if(is_playing[i]){
        printf("%d%c", i + 1, n == 1 ? '\n' : ' ');
        n--;
    }
    return 0;
}