/*アルゴリズムと工夫点(Count Subgrid Sum = K/CPU: 2015 ms Memory: 4988 KB  Length: 1689 B)
二次元累積和 + 二分探索で解く．
長方形の左上の座標(y, x) と，長方形の横方向の辺の長さ w を固定する．
すると，縦の長さ h の増加に対して，長方形範囲内の累積和の値も増加する．
つまり，h と累積和の値の間には単調性が見られるため，二分探索が可能．
最悪計算量は，O(H * (W ^ 2) * log2(H)) < 10 ^ 9 となり，ギリギリ間に合う（4 sec 制限のため）．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int h, w, k;

int main(){
    int i, j;

    scanf("%d%d%d", &h, &w, &k);
    vector<vector<int> > sum(h + 1, vector<int>(w + 1, 0));
    rep(i, h){
        string s;
        cin >> s;
        rep(j, s.length())
            sum[i + 1][j + 1] = (s[j] == '1') + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    }

    auto range_sum = [&](int begin_y, int begin_x, int end_y, int end_x) -> int{
        return sum[end_y][end_x] - sum[end_y][begin_x] - sum[begin_y][end_x] + sum[begin_y][begin_x];
    };
    ll ans = 0;
    rep(i, h)rep(j, w)for(int len = 1;j + len <= w;len++){
        int left = 1, right = h - i + 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(range_sum(
                /* begin_y = */ i, 
                /* begin_x = */ j, 
                /* end_y = */ i + mid, 
                /* end_x = */ j + len
            ) < k)left = mid + 1;
            else right = mid;
        }
        int min_height = left;

        left = 1, right = h - i + 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(range_sum(
                /* begin_y = */ i, 
                /* begin_x = */ j, 
                /* end_y = */ i + mid, 
                /* end_x = */ j + len
            ) <= k)left = mid + 1;
            else right = mid;
        }
        int max_height = left - 1;
        ans += max_height - min_height + 1;
    }

    printf("%lld\n", ans);
    return 0;
}