/*アルゴリズムと工夫点(AtCoder Riko/CPU: 40 ms Memory: 4824 KB  Length: 1012 B)
場合分けと全探索で解く．
解となりうるのは，下記の2通りのみである．
・L = (Ai の最大値) となる場合
・L = (Ai の最大値) + (Ai の最小値) となる場合
各場合について，それぞれO(N) で判定可能．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;
    scanf("%d", &n);
    vector<int> a(n), ans;
    rep(i, n)scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    auto judge2 = [&](int r, int target) -> bool{
        int s = 0;
        // 対象要素数が偶数か判定
        if((r - s + 1) % 2 > 0)return false;
        while(s < r){
            if(a[s] + a[r] != target)return false;
            s++;r--;
        }
        return true;
    };
    auto judge1 = [&]() -> bool{
        int r = n - 1;
        while(r >= 0 && a[r] == a[n - 1])r--;
        return judge2(r, a[n - 1]);
    };
    if(judge1())ans.push_back(a[n - 1]);
    if(judge2(n - 1, a[0] + a[n - 1]))ans.push_back(a[0] + a[n - 1]);
    rep(i, ans.size() - 1)printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}