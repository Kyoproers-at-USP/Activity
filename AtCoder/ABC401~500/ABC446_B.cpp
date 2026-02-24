/*アルゴリズムと工夫点(Greedy Draft/CPU: 2 ms Memory: 3928 KB  Length: 705 B)
各ジュースが選ばれているか否かを管理し，シミュレーションして解く．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    scanf("%d%d", &n, &m);
    vector<bool> is_juice_exist(m, true);
    rep(i, n){
        int l;
        bool selected = false;
        scanf("%d", &l);
        while(l--){
            int x;
            scanf("%d", &x);x--;
            if(!selected && is_juice_exist[x]){
                is_juice_exist[x] = false;
                selected = true;
                printf("%d\n", x + 1);
            }
        }
        if(!selected)puts("0");
    }
    return 0;
}