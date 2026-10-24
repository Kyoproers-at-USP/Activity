/*アルゴリズムと工夫点(Self-Stopping Shower/CPU: 29 ms Memory: 8216 KB  Length: 1531 B)
お湯が出ていない時間帯を求めて，ボタンを押す回数を数え上げればよい．
まず，青木君がボタンを押したことにより，[A_{i}, A_{i} + K) の時間帯ではお湯が出ていると捉える．
この複数の時間帯について，共通範囲を持つ時間帯を一つにまとめ，互いに背反な状態にする．
すると [0, T) の時間帯において，お湯が出ていない時間帯が判明するため，
その時間の長さを元に何回高橋君がボタンを押せばよいか計算し，総和を計算すればよい．
最悪計算量は，O(N * log2(N)) < 10 ^ 7 となり，高速．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> P;

int n, k, t;

bool isCommon(P r1, P r2){
    return min(r1.second, r2.second) - max(r1.first, r2.first) >= 0;
}

int main(){
    int i, j;

    scanf("%d%d%d", &n, &k, &t);
    vector<P> ranges;
    rep(i, n){
        int a;
        scanf("%d", &a);
        ranges.push_back(P(a, a + k));
    }

    sort(ranges.begin(), ranges.end());
    vector<P> dstn_ranges;
    i = 0;
    while(i < ranges.size()){
        P now = ranges[i];

        j = i + 1;
        while(
            j < ranges.size() && 
            isCommon(
                /* r1 = */ now, 
                /* r2 = */ ranges[j]
        )){
            now.first = min(now.first, ranges[j].first);
            now.second = max(now.second, ranges[j].second);
            j++;
        }

        dstn_ranges.push_back(now);
        i = j;
    }

    i = 0;
    int start = 0;
    if(dstn_ranges[0].first == 0){
        i = 1;
        start = dstn_ranges[0].second;
    }

    int ans = 0;
    while(i < dstn_ranges.size() && start <= t){
        int cnt = (min(t, dstn_ranges[i].first) - start + k - 1) / k;
        ans += cnt;

        start = dstn_ranges[i].second;
        i++;
    }
    if(start <= t)ans += (t - start + k - 1) / k;

    printf("%d\n", ans);
    return 0;
}