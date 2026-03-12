/*アルゴリズムと工夫点(Pepper Addiction/CPU: 1 ms Memory: 3908 KB  Length: 532 B)
貪欲法で解く．
各料理に，かけられるだけコショウを書ける方針で良い．
この時，各コショウの残量を別で保持して置くこと．
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
    int i, j, ans = 0;
    scanf("%d%d", &n, &m);
    vector<int> c(m);
    rep(i, m)scanf("%d", &c[i]);
    while(n--){
        int a, b;
        scanf("%d%d", &a, &b);a--;
        int used_grams = min(c[a], b);
        c[a] -= used_grams;
        ans += used_grams;
    }
    printf("%d\n", ans);
    return 0;
}