/*アルゴリズムと工夫点(Topping/CPU: 1 ms Memory: 3812 KB  Length: 503 B)
全探索で解く．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, v;

int main(){
    int i, j, k;

    scanf("%d%d", &n, &v);
    vector<int> w(n);
    rep(i, n)scanf("%d", &w[i]);

    int max_sum_w = 0;
    rep(i, n)rep(j, i)rep(k, j)
        if(i + j + k + 3 <= v)max_sum_w = max(max_sum_w, w[i] + w[j] + w[k]);

    printf("%d\n", max_sum_w);
    return 0;
}