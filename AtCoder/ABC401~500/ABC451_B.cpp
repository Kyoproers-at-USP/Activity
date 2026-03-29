/*アルゴリズムと工夫点(Personnel Change/CPU: 2 ms Memory: 3860 KB  Length: 494 B)
部門ごとに人数を管理して解く．
今期に部門iに所属している場合は部門iの人数-1, 来期に所属している場合は+1する方針をとれば，実装は楽．
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
    vector<int> dep_to_cnt(m, 0);
    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;b--;
        dep_to_cnt[a]--;
        dep_to_cnt[b]++;
    }
    rep(i, m)printf("%d\n", dep_to_cnt[i]);
    return 0;
}