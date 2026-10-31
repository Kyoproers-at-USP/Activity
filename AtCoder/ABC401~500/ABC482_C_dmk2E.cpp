/*アルゴリズムと工夫点(Band Count/CPU: 156 ms Memory: 6012 KB  Length: 888 B)
二分探索で解く．
y 座標，x 座標毎に駒の座標値を保持して置き，クエリ毎に二分探索を行って解く．
最悪計算量は，O((N + Q) * log2(N)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w, n, q;

int main(){
    int i, j;

    scanf("%d%d%d%d", &h, &w, &n, &q);
    vector<int> rs(n), cs(n);
    rep(i, n)scanf("%d%d", &rs[i], &cs[i]);

    sort(rs.begin(), rs.end());
    sort(cs.begin(), cs.end());

    while(q--){
        scanf("%d", &i);

        if(i == 1){
            int u, d;
            scanf("%d%d", &u, &d);
            printf("%ld\n", upper_bound(rs.begin(), rs.end(), d) - lower_bound(rs.begin(), rs.end(), u));
        }else{
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%ld\n", upper_bound(cs.begin(), cs.end(), r) - lower_bound(cs.begin(), cs.end(), l));
        }
    }
    return 0;
}