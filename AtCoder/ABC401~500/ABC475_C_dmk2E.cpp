/*アルゴリズムと工夫点(Walk the Line/CPU: 2 ms Memory: 3960 KB  Length: 2689 B)
折り返し地点を固定した，高速シミュレーションで解く．
一直線上の移動であるため，同じ都市を3回以上訪れるような経路は考える必要がない．
そのため折り返し地点Tを決め打つと，S -> T -> （反対方向で行けるところまで）というルートが最適となる．
この地点Tを全探索して解く．
実装では 累積和 + 二分探索 を用いているため，最悪計算量は，O(N * log2(N)) < 10 ^ 5 となり，十分高速．
※ 公式解説では，最後に到達する都市も固定して考えることで，実装量を大幅に減らしている
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, s;
ll l;

int main(){
    int i, j;

    scanf("%d%d%lld", &n, &s, &l);
    s--;
    vector<ll> sum_a(n);
    sum_a[0] = 0;
    rep(i, n - 1){
        ll a;
        scanf("%lld", &a);
        sum_a[i + 1] = sum_a[i] + a;
    }

    auto calcCost = [&](int city_a, int city_b) -> ll{
        int left = min(city_a, city_b), right = max(city_a, city_b);
        return sum_a[right] - sum_a[left];
    };
    auto calcEnableDist = [&](int start, int last, ll now_l) -> int{
        int left = min(start, last), right = max(start, last);

        if(last - start < 0){
            while(left < right){
                int mid = (left + right) / 2;
                if(calcCost(
                    /* city_a = */ start, 
                    /* city_b = */ mid
                ) <= now_l)right = mid;
                else left = mid + 1;
            }

            return abs(left - start) + 1;
        }else{
            while(left < right){
                int mid = (left + right) / 2;
                if(calcCost(
                    /* city_a = */ start, 
                    /* city_b = */ mid
                ) <= now_l)left = mid + 1;
                else right = mid;
            }

            return abs(left - start);
        }
    };
    auto calcCnt = [&](int turn_id) -> int{
        if(turn_id == s)return 0;

        int ans = 0;
        ll now_l = l;
        ll cost_to_turn = calcCost(
            /* city_a = */ s, 
            /* city_b = */ turn_id
        );
        if(cost_to_turn > now_l){
            ans += calcEnableDist(
                /* start = */ s, 
                /* last = */ turn_id, 
                /* now_l = */ now_l
            );
            return ans;
        }
        ans += abs(turn_id - s) + 1;
        now_l -= cost_to_turn * 2;

        if(now_l <= 0)return ans;

        int goal_id = s < turn_id ? 0 : n - 1;

        ll cost_to_goal = calcCost(
            /* city_a = */ s, 
            /* city_b = */ goal_id
        );
        if(cost_to_goal > now_l){
            ans += calcEnableDist(
                /* start = */ s, 
                /* last = */ goal_id, 
                /* now_l = */ now_l
            ) - 1;
            return ans;
        }
        ans += abs(goal_id - s);

        return ans;
    };

    int ans = 0;
    rep(i, n)ans = max(ans, calcCnt(/* turn_id = */ i));
    
    printf("%d\n", ans);
    return 0;
}