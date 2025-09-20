/*アルゴリズムと工夫点(Locked Rooms/CPU: 1 ms Memory: 3884 KB  Length: 740 B)
シミュレーションで解く．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j;
    scanf("%d", &n);
    vector<bool> l(n), vis(n + 1);
    rep(i,n){
        scanf("%d",&j);
        l[i] = j == 0;
    }
    i = 0;
    vis[0] = vis[n] = true;
    while(i < n){
        if(l[i]){
            i++;
            vis[i] = true;
        }else
            break;
    }
    i = n;
    while(i > 0){
        if(l[i - 1]){
            i--;
            vis[i] = true;
        }else
            break;
    }
    j = n + 1;
    rep(i,n + 1)j -= vis[i];
    printf("%d\n", j);
    return 0;
}