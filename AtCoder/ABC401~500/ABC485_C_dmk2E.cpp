/*アルゴリズムと工夫点(Different Neighbor/CPU: 28 ms Memory: 9024 KB  Length: 966 B)
ランレングス圧縮を用いて解く．
座標の昇順に並べた点群を色毎にグルーピングすると，とあるグループの色は，
隣接するグループが表す色とは異なるものになる．
ここで各グループにおいて下記の情報を保持しておく．
 ・最も小さい座標（左端）
 ・最も大きい座標（右端）
すると点 i において最も距離が近い，色が C_{i} とは異なる点は，
点 i が属するグループの左側のグループの右端の点，または右側のグループの左端の点となるため，
距離がより小さい方を解として出力すればよい．
最悪計算量は，O(N) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n;

int main(){
    int i, j;

    scanf("%d", &n);
    vector<int> c(n);
    rep(i, n)scanf("%d", &c[i]);

    vector<P> rle;
    i = 0;
    while(i < n){
        P now(i, i);
        j = i + 1;
 
        while(j < n && c[j] == c[i])j++;
        now.second = j - 1;
        rle.push_back(now);

        i = j;
    }

    vector<int> ans(n, n);
    j = 0;
    rep(i, n){
        while(
            j < rle.size() && 
            (i < rle[j].first || i > rle[j].second)
        )j++;

        if(j + 1 < rle.size())ans[i] = abs(rle[j + 1].first - i);
        if(j - 1 >= 0)ans[i] = min(ans[i], abs(rle[j - 1].second - i));
    }

    rep(i, n - 1)printf("%d ", ans[i]);
    printf("%d\n", ans[i]);
    return 0;
}