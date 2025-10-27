/*アルゴリズムと工夫点(Odd One Subsequence/CPU: 20 ms Memory: 4048 KB  Length: 515 B)
主客転倒で解く．
値毎にその数を数えておき，2つ選ぶ値を固定して数え上げる．
最悪計算量は，O(N) < 10^6 となり高速．
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
    int i,j;
    ll ans = 0;
    scanf("%d",&n);
    vector<int> a_to_count(n, 0);
    rep(i,n){
        int a;
        scanf("%d",&a);a--;
        a_to_count[a]++;
    }
    rep(i,n)ans += ((ll)a_to_count[i] * (a_to_count[i] - 1) / 2) * (n - a_to_count[i]);
    printf("%lld\n", ans);
    return 0;
}