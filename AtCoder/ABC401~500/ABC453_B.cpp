/*アルゴリズムと工夫点(Sensor Data Logging/CPU: 3 ms Memory: 3960 KB  Length: 569 B)
実際にシミュレーションして解く．
センサーの保持は，可変長配列を用いると便利．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int t, x;

int main(){
    int i, j;
    scanf("%d%d", &t, &x);
    int prev_a = -x;
    vector<P> ans;
    rep(i, t + 1){
        int a;
        scanf("%d", &a);
        if(abs(a - prev_a) >= x){
            ans.push_back(P(a, i));
            prev_a = a;
        }
    }
    for(auto [a, t] : ans)printf("%d %d\n", t, a);
    return 0;
}