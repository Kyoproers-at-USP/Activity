/*アルゴリズムと工夫点(456/CPU: 1 ms Memory: 3836 KB  Length: 803 B)
全探索で解く．
各サイコロが{4, 5, 6} のいずれかを被りがないように出す場合の数を求め，
マスの総数で割れば求められる．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define DICE 6
#define N 3
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int i, j, k;
    vector<vector<int> > dice_to_cnt(N, vector<int>(DICE, 0));
    rep(i, N){
        rep(j, DICE){
            int a;
            scanf("%d", &a);
            dice_to_cnt[i][a - 1]++;
        }
    }

    int sum_cases = 0;
    for(i = 4;i <= DICE;i++)
        for(j = 4;j <= DICE;j++)for(k = 4;k <= DICE;k++){
            if(i == j || j == k || k == i)continue;
            sum_cases += dice_to_cnt[0][i - 1] * dice_to_cnt[1][j - 1] * dice_to_cnt[2][k - 1];
        }

    printf("%.7f\n", (double)sum_cases / (6 * 6 * 6));
    return 0;
}