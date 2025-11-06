/*アルゴリズムと工夫点(Count Subgrid/CPU: 1 ms Memory: 4012 KB  Length: 638 B)
set + 全探索で解く．
M * M の領域としてあり得るものを全て取り出し，setを用いて数え上げる．
最悪計算量は，O(N^2 * (M^2 + log2(N^(2) * M^(2))) ) < 10^5 となり高速．
*/
#include<iostream>
#include<vector>
#include<set>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;

int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    vector<string> mp(n);
    set<string> st;
    rep(i,n)cin >> mp[i];
    auto parseMap = [&](int sy,int sx)->string{
        int i,j;
        string ans = "";
        rep(i,m)rep(j,m)ans += mp[sy + i][sx + j];
        return ans;
    };
    rep(i,n - m + 1)rep(j, n - m + 1){
        st.insert(parseMap(i,j));
    }
    printf("%ld\n",st.size());
    return 0;
}