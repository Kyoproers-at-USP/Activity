/*アルゴリズムと工夫点(Not Adjacent 2/CPU: 10 ms Memory: 4060 KB  Length: 1126 B)
動的計画法で解く．
下記のDPテーブルを考えると，
dp[i][j] := S上のi文字目までをいくつか選んだ時にできる部分文字列であって，末尾の状態がj（0: '', 1: 'a', 2: 'b', 3: 'c'）であるものの総数
解は，dp[N][1] + dp[N][2] + dp[N][3] となる．
最悪計算量は，O(N) < 10 ^ 6 となり十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int char2Id(char c){
    switch(c){
        case 'a': 
            return 1;
        case 'b': 
            return 2;
        case 'c': 
            return 3;
    }
    return 0;
}

int main(){
    int i, j;
    cin >> s;

    const int MAX_STATE = 4;
    vector<ll> dp(MAX_STATE, 0);
    dp[0] = 1;
    for(char c : s){
        vector<ll> nxt = dp;
        switch(char2Id(/* c = */ c)){
            case 1: 
                nxt[1] = (nxt[1] + dp[0] + dp[2] + dp[3]) % MOD;
                break;
            case 2: 
                nxt[2] = (nxt[2] + dp[0] + dp[1] + dp[3]) % MOD;
                break;
            case 3: 
                nxt[3] = (nxt[3] + dp[0] + dp[1] + dp[2]) % MOD;
                break;
            default:
                break;
        }
        swap(dp, nxt);
    }

    printf("%lld\n", (dp[1] + dp[2] + dp[3]) % MOD);
    return 0;
}