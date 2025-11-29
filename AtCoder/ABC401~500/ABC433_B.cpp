/*アルゴリズムと工夫点(Nearest Taller/CPU: 1 ms Memory: 4024 KB  Length: 505 B)
全探索で解く．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define NIL -1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i,j;
    scanf("%d",&n);
    vector<int> a(n), ans(n,NIL);
    rep(i,n)scanf("%d",&a[i]);
    rep(i,n)for(j = i - 1;j >= 0;j--){
        if(a[j] > a[i]){
            ans[i] = j + 1;
            break;
        }
    }
    rep(i,n)printf("%d\n",ans[i]);
    return 0;
}