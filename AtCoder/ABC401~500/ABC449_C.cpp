/*アルゴリズムと工夫点(Comfortable Distance/CPU: 51 ms Memory: 7268 KB  Length: 983 B)
二分探索で解く．
英単語の種類ごとに，S 上の添え字を管理する．
その後，英単語の種類を固定し，その中で整数iの値を固定した時の，条件を満たす整数jの個数を二分探索により求める．
最悪計算量は，O(|S| * log2(|S|)) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, l, r;
string s;

ll calcCnt(vector<int>& target_ids){
    int left, right;
    ll ans = 0;
    rep(left, target_ids.size()){
        int begin_id = lower_bound(target_ids.begin(), target_ids.end(), l + target_ids[left]) - target_ids.begin();
        int end_id = upper_bound(target_ids.begin(), target_ids.end(), r + target_ids[left]) - target_ids.begin();
        ans += end_id - begin_id;
    }
    return ans;
}

int main(){
    int i, j;
    const int MAX_ALFA = 26;
    ll ans = 0;
    scanf("%d%d%d", &n, &l, &r);
    vector<vector<int> > alfa_to_ids(MAX_ALFA);
    cin >> s;
    rep(i, n)alfa_to_ids[s[i] - 'a'].push_back(i);
    rep(i, MAX_ALFA)ans += calcCnt(/* target_ids = */ alfa_to_ids[i]);
    printf("%lld\n", ans);
    return 0;
}