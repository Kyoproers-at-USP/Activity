/*アルゴリズムと工夫点(Maximize the Gap/CPU: 52 ms Memory: 5208 KB  Length: 1081 B)
貪欲法 + 二分探索で解く．
重ならないように布を選ぶとき，選択できる布の最大枚数を求める問題は
「区間スケジューリング問題」であり，貪欲法で解ける．
この最大枚数がK以上である時，布間の最小距離lの最大値を求めたい．
ここで，lには単調性があるため，二分探索を適用できる．
「最小距離をl以上にして，K枚以上布を選べるか」は，布の右端を l 加算して，
上記の区間スケジューリング問題を解く要領で判定可能．
従って，最悪計算量は O(N * (log2(N) + log2(MAX_R))) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MIN_L 0
#define MAX_R (int)(1e9)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n, k;

int main(){
    int i, j;
    
    scanf("%d%d", &n, &k);
    vector<P> seq(n);
    rep(i, n)scanf("%d%d", &seq[i].second, &seq[i].first);

    sort(seq.begin(), seq.end());
    auto judge = [&](int min_dist) -> bool{
        int i = 0, min_r = MIN_L - 1, cnt = 0;
        while(i < n){
            while(i < n && seq[i].second <= min_r)i++;
            if(i < n){
                cnt++;
                min_r = seq[i].first + min_dist;
                i++;
            }
        }
        return cnt >= k;
    };

    int left = 0, right = MAX_R + 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(judge(/* min_dist = */ mid))left = mid + 1;
        else right = mid;
    }

    printf("%d\n", left == 0 ? -1 : left);
    return 0;
}