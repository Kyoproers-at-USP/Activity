/*アルゴリズムと工夫点(Standing Outliers/CPU: 1 ms Memory: 3920 KB  Length: 628 B)
全探索で解く．
各i について，条件を満たすか判定すればよい．
最悪計算量は，O(N ^ 2) となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, d;

int main(){
    int i, j;

    scanf("%d%d", &n, &d);
    vector<int> x(n);
    rep(i, n)scanf("%d", &x[i]);

    vector<int> ans;
    rep(i, n){
        rep(j, n)if(j != i && abs(x[i] - x[j]) < d)break;

        if(j == n)ans.push_back(i + 1);
    }

    printf("%ld\n", ans.size());
    if(ans.size()){
        rep(i, ans.size() - 1)printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
    }
    return 0;
}