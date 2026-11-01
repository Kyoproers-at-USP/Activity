/*アルゴリズムと工夫点(Polyline/CPU: 1 ms Memory: 3848 KB  Length: 670 B)
配列 A を2回走査して解く．
それぞれ下記の値を求めて，総和を出力する．
 ・A[i] == k を満たす数
 ・A[i] < k < A[i + 1] を満たす数)
最悪計算量は，O(N) < 10 ^ 3 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int main(){
    int i;

    scanf("%d%d", &n, &k);
    vector<int> a(n);
    rep(i, n)scanf("%d", &a[i]);

    int ans = 0;
    auto judge = [&](int num_1, int num_2) -> bool{
        int min_num = min(num_1, num_2);
        int max_num = max(num_1, num_2);
        return min_num < k && k < max_num;
    };
    rep(i, n - 1)ans += judge(/* num_1 = */ a[i], /* num_2 = */ a[i + 1]);
    rep(i, n)ans += a[i] == k;

    printf("%d\n", ans);
    return 0;
}