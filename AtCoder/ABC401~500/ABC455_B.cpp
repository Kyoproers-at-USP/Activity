/*アルゴリズムと工夫点(Spiral Galaxy/CPU: 1 ms Memory: 3976 KB  Length: 829 B)
あり得る長方形全てについて，点対称かどうかを判定し，数え上げる．
最悪計算量は，O(H ^ (3) * W ^ (3)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w;

int main(){
    int i, j, k, ii;
    scanf("%d%d", &h, &w);
    
    vector<string> s(h);
    rep(i, h)cin >> s[i];

    auto isSpiral = [&](int sy, int sx, int gy, int gx) -> bool{
        int i, j;
        for(i = sy;i <= gy;i++)for(j = sx;j <= gx;j++)
            if(s[i][j] != s[sy + gy - i][sx + gx - j])return false;
        return true;
    };
    int ans = 0;
    rep(i, h)rep(j, i + 1)rep(k, w)rep(ii, k + 1){
        ans += isSpiral(
            /* sy = */ j, 
            /* sx = */ ii, 
            /* gy = */ i, 
            /* gx = */ k
        );
    }
    printf("%d\n", ans);
    return 0;
}