/*アルゴリズムと工夫点(Count Close Pairs/CPU: 10 ms Memory: 3884 KB  Length: 808 B)
尺取り法で解く．
整数の組(i, j) (i < j)の内，i の値を固定して，ペア数を数え上げる．
ボール1~N はその番号順に，左から右にかけて並んでいるため，
ボール [i, k] (i < k) が互いに距離1以下である場合，ボール [i + 1, k] も互いに距離1以下となる．
従って単調性が存在し，尺取り法を適用可能である．
最大クエリ回数は 2 * N 以下となり，また最悪計算量は O(N) < 10 ^ 4 であり，高速．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    scanf("%d", &n);

    auto isDistanceLowerOne = [&](int a_id, int b_id) -> bool{
        printf("? %d %d\n", a_id, b_id);cout << flush;
        string s;
        cin >> s;
        return s == "Yes";
    };
    
    int ans = 0;
    for(int left = 1, right = 2;left <= n;left++){
        if(left == right)right = left + 1;

        while(
            right <= n && 
            isDistanceLowerOne(
                /* a_id = */ left, 
                /* b_id = */ right
        ))right++;

        ans += right - left - 1;
    }

    printf("! %d\n", ans);
    cout << flush;
    return 0;
}