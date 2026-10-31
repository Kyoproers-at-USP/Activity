/*アルゴリズムと工夫点(Blank Bingo/CPU: 1 ms Memory: 3764 KB  Length: 800 B)
縦横斜めそれぞれに存在する'o' の数の最大値を求め，5 から引いた値を出力する．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define H 5
#define W 5
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int i, j;
    
    vector<string> mp(H);
    rep(i, H)cin >> mp[i];

    int max_o = 0;
    // yoko
    rep(i, H){
        int cnt = 0;
        rep(j, W)cnt += mp[i][j] == 'o';
        max_o = max(max_o, cnt);
    }
    // tate
    rep(j, W){
        int cnt = 0;
        rep(i, H)cnt += mp[i][j] == 'o';
        max_o = max(max_o, cnt);
    }
    // naname
    int cnt = 0;
    rep(i, H)cnt += mp[i][i] == 'o';
    max_o = max(max_o, cnt);
    cnt = 0;
    rep(i, H)cnt += mp[i][W - i - 1] == 'o';

    printf("%d\n", H - max_o);
    return 0;
}