/*アルゴリズムと工夫点(Sushi/CPU: 53 ms Memory: 5064 KB  Length: 652 B)
貪欲法 + (ソート + )尺取り法 で解く．
満たすべき条件式，2 * A >= B より，下記の性質が見られる．
 ・Aの値は大きいほど，条件式を満たしやすい
 ・Bの値は小さいほど，条件式を満たしやすい
そこで，条件式を満たす組の数を最大にするには，Aの値の降順に見ていった時，
「条件式を満たす最大のBの値と組み合わせる」ことを繰り返せばよい．
「Aの値が小さくなるほど，組み合わせることが出来るBの値も小さくなる」という単調性が見られるため，尺取り法が適用できる．
最悪計算量は，O(N * log2(N) + M * log2(M)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);
    vector<int> b(m);
    rep(i, m)scanf("%d", &b[i]);

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    j = 0;
    rep(i, n){
        while(j < m && 2 * a[i] < b[j])j++;
        if(j == m)break;
        ans++;j++;
    }

    printf("%d\n", ans);
    return 0;
}