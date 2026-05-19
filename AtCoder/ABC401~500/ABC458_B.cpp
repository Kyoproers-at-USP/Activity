/*アルゴリズムと工夫点(Count Adjacent Cells/CPU: 1 ms Memory: 3856 KB  Length: 840 B)
y ∈ [1, H], x ∈ [1, W] の各マスの隣接数を，その隣接する座標の内グリッド内部に存在する数として計算すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w;

int main(){
    int i, j, k;
    scanf("%d%d", &h, &w);

    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1}, MAX_D = 4;
    rep(i, h){
        rep(j, w - 1){
            int ans = 0;
            rep(k, MAX_D){
                int y = i + dy[k];
                int x = j + dx[k];
                ans += 0 <= y && y < h && 0 <= x && x < w;
            }
            printf("%d ", ans);
        }
        int ans = 0;
        rep(k, MAX_D){
            int y = i + dy[k];
            int x = j + dx[k];
            ans += 0 <= y && y < h && 0 <= x && x < w;
        }
        printf("%d\n", ans);
    }
    return 0;
}