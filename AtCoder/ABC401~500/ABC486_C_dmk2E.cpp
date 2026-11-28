/*アルゴリズムと工夫点(Skip Lighting/CPU: 6 ms Memory: 4312 KB  Length: 631 B)
点灯している位置座標を K で割った余りで管理し，長さ K の間隔で連続している連結成分の数を出力すればよい．
最悪計算量は，O(N) < 10 ^ 6 となり，十分高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;
string s;

int main(){
    int i;

    scanf("%d%d", &n, &k);
    cin >> s;

    int ans = 0;
    rep(i, k){
        int j = i;
        while(j < n){
            int now = j;
            while(now < n && s[now] != 'o')now += k;
            if(now >= n)break;

            while(now < n && s[now] == 'o')now += k;

            j = now;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}