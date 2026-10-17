/*アルゴリズムと工夫点(ADjacent/CPU: 1 ms Memory: 3512 KB  Length: 591 B)
'A' と 'D' の位置座標を求めて，2点間のマンハッタン距離が1であるかどうかで判定すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define H 2
#define W 2
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int main(){
    int i, j;

    P p_a, p_d;
    rep(i, H){
        string s;
        cin >> s;
        rep(j, W){
            if(s[j] == 'A')p_a = P(i, j);
            else if(s[j] == 'D')p_d = P(i, j);
        }
    }

    int dist = abs(p_a.first - p_d.first) + abs(p_a.second - p_d.second);
    printf("%s\n", dist == 1 ? "Yes" : "No");
    return 0;
}