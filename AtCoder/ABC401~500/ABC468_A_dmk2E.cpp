/*アルゴリズムと工夫点(Maximal Value/CPU: 1 ms Memory: 3812 KB  Length: 436 B)
2番目からN - 1番目の要素について条件を満たすか判定し，数え上げる．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i;

    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);

    int cnt = 0;
    for(i = 1;i < n - 1;i++)cnt += a[i - 1] < a[i] && a[i] > a[i + 1];

    printf("%d\n", cnt);
    return 0;
}