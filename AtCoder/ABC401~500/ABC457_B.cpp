/*アルゴリズムと工夫点(Arrays/CPU: 28 ms Memory: 14384 KB  Length: 509 B)
2次元配列で入力を保持し，指定された要素を出力すればよい．
可変長配列で持てば，メモリ効率は良い．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, x, y;

int main(){
    int i, j;
    scanf("%d", &n);
    
    vector<vector<int> > a(n);
    rep(i, n){
        int l;
        scanf("%d",&l);
        a[i] = vector<int>(l);
        rep(j, l)scanf("%d", &a[i][j]);
    }

    scanf("%d%d", &x, &y);
    printf("%d\n", a[x - 1][y - 1]);
    return 0;
}