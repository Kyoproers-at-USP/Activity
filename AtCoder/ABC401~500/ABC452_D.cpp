/*アルゴリズムと工夫点(No-Subsequence Substring/CPU: 185 ms Memory: 5056 KB  Length: 1084 B)
アルファベットごとに管理 + 二分探索を用いて解く．
左端を固定した際の S の部分文字列を順次考え，ギリギリ T を含まない右端の位置を求めることを繰り返す．
この時，S上に存在するアルファベットごとの添え字を管理する配列 alfa を用意しておく．
すると，T を部分列として含むかは，alfa上での二分探索 + 貪欲法により解くことが出来る．
最悪計算量は，O(|S| * |T| * log2(|T|)) ≒ 10 ^ 8 となり間に合う．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s, t;

int main(){
    int i, j;
    cin >> s >> t;
    // 前処理
    const int ALFA = 26;
    vector<vector<int> > alfa_to_ids(ALFA);
    rep(i, s.length())alfa_to_ids[s[i] - 'a'].push_back(i);

    // 本処理
    auto calc = [&](int start) -> int{
        int i, prev_pos = start;
        rep(i, t.length()){
            int alfa_index = t[i] - 'a';
            vector<int>& ids = alfa_to_ids[alfa_index];
            int nxt_pos_id = lower_bound(
                ids.begin(), 
                ids.end(), 
                prev_pos
            ) - ids.begin();
            if(nxt_pos_id == ids.size())return s.length() - start;
            prev_pos = ids[nxt_pos_id] + 1;
        }
        return prev_pos - start - 1;
    };
    ll ans = 0;
    rep(i, s.length())ans += calc(/* begin = */ i);
    printf("%lld\n", ans);
    return 0;
}