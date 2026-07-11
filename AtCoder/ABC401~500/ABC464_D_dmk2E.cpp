/*アルゴリズムと工夫点(Celester/CPU: 39 ms Memory: 5504 KB  Length: 1121 B)
動的計画法で解く．
下記のDPテーブルを満たす動的計画法を考える．
ここで，num(S[i]) = (S[i] == 'S' ならば `0`, S[i] == 'R' ならば `1`) とする．
dp[i][j] := num(S[i]) == j であった時の，最大の嬉しさ
i + 1 日目の嬉しさは，i 日目の天気の状態に依存するため，dp[i + 1] の値は dp[i] の値から求めることが出来る．
1テストケース当たりの最悪計算量は，O(N) < 10 ^ 6 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int t;

ll solve(){
    int i, j;
    
    int n;
    string s;
    cin >> n >> s;
    vector<int> x(n), y(n - 1);
    rep(i, n)scanf("%d", &x[i]);
    rep(i, n - 1)scanf("%d", &y[i]);

    const int SUN = 0, RAIN = 1;
    auto parseWeather = [](char w) -> int{
        return w == 'S' ? SUN : RAIN;
    };
    
    vector<ll> dp(2);
    dp[SUN] = dp[RAIN] = -x[0];
    dp[parseWeather(/* w = */ s[0])] = 0;
    for(i = 1;i < n;i++){
        vector<ll> nxt(2);

        if(s[i] == 'S'){
            nxt[SUN] = max(dp[SUN], dp[RAIN] + y[i - 1]);
            nxt[RAIN] = max(dp[RAIN], dp[SUN]) - x[i];
        }else{
            nxt[RAIN] = max(dp[RAIN], dp[SUN]);
            nxt[SUN] = max(dp[RAIN] + y[i - 1], dp[SUN]) - x[i];
        }

        swap(dp, nxt);
    }

    return max(dp[SUN], dp[RAIN]);
}

int main(){
    scanf("%d", &t);
    while(t--)printf("%lld\n", solve());
    return 0;
}