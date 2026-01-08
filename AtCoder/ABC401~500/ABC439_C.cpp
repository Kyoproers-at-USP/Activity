/*アルゴリズムと工夫点(2026/CPU: 103 ms Memory: 49948 KB  Length: 658 B)
全探索して解く．
条件より，0 < x ^ 2 < x ^ 2 + y ^ 2 = n となるから，0 < x < √n
同様に，0 < y < √n となる．
よって，考慮しなければならないx, y の値の組全てについて，x ^ 2 + y ^ 2 を計算し，数え上げる．
その結果，ただ一つの組(x, y)のみ x ^ 2 + y ^ 2 == n となる数を数え上げる．
最悪計算量は，O(√x * √y) = O(N) < 10 ^ 8 となり間に合う．
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
    int i;
    scanf("%d", &n);
    vector<int> is_good(n + 1, 0), ans;
    for(int x = 1 ; x < (n + x - 1) / x; x++)for(int y = x + 1 ;y < (n + y - 1) / y ; y++){
        if(x * x + y * y <= n)is_good[x * x + y * y]++;
    }
    rep(i, n + 1)if(is_good[i] == 1)ans.push_back(i);
    printf("%ld\n", ans.size());
    if(ans.size() > 0){
        rep(i, ans.size() - 1)printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
    }
    return 0;
}