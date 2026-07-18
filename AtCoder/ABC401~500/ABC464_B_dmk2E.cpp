/*アルゴリズムと工夫点(Crop/CPU: 1 ms Memory: 3836 KB  Length: 1462 B)
処理後に削除されずに残っている区間を管理して解く．
各行・各列について，全て白であるかを判定し，徐々に範囲を狭めていく．
本実装では累積和を用いて高速化しているため，最悪計算量は O(H * W) < 10 ^ 5 となり十分高速．
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
    int i, j;
    
    scanf("%d%d", &h, &w);
    vector<string> mp(h);
    rep(i, h)cin >> mp[i];

    vector<vector<int> > sum_blk_horizon(h, vector<int>(w + 1, 0));
    rep(i, h)rep(j, w)
        sum_blk_horizon[i][j + 1] = sum_blk_horizon[i][j] + (mp[i][j] == '#');
    vector<vector<int> > sum_blk_vertical(h + 1, vector<int>(w, 0));
    rep(j, w)rep(i, h)
        sum_blk_vertical[i + 1][j] = sum_blk_vertical[i][j] + (mp[i][j] == '#');

    int start_y = 0;
    while(
        start_y < h && 
        sum_blk_horizon[start_y][w] - sum_blk_horizon[start_y][0] == 0
    )start_y++;

    int last_y = h - 1;
    while(
        last_y >= 0 && 
        sum_blk_horizon[last_y][w] - sum_blk_horizon[last_y][0] == 0
    )last_y--;

    int start_x = 0;
    while(
        start_x < w && 
        sum_blk_vertical[last_y + 1][start_x] - sum_blk_vertical[start_y][start_x] == 0
    )start_x++;

    int last_x = w - 1;
    while(
        last_x >= 0 && 
        sum_blk_vertical[last_y + 1][last_x] - sum_blk_vertical[start_y][last_x] == 0
    )last_x--;

    for(i = start_y;i <= last_y;i++){
        for(j = start_x;j < last_x;j++)printf("%c", mp[i][j]);
        printf("%c\n", mp[i][j]);
    }
    return 0;
}