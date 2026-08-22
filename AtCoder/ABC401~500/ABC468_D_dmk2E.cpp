/*アルゴリズムと工夫点(Pre-Palindrome/CPU: 31 ms Memory: 3864 KB  Length: 1180 B)
中心位置を固定した回文判定を繰り返して解く．
中心位置centerとした時，その位置からできる文字列について，
1文字以下の書き換えで回文にできる数の数え上げは，下記の方法で効率的に可能．
 ・長さが奇数の場合：
    - k >= 0 とし，kを徐々に増やしていき，S[i - k, i + k] が良い文字列か判定
    - kを増やす時，S[i - k] == S[i + k] が成立しない，かつ今までに成立しなかった場合が1回ある場合のみ，
      それ以上増やしても「良い文字列」にはならないと判定できる
    - 上記が満たされるまで，条件を満たす数を数え上げる
 ・長さが偶数の場合：
    - k >= 0 とし，kを徐々に増やしていき，S[i - k, i + 1 + k] が良い文字列か判定
    - kを増やす時，S[i - k] == S[i + 1 + k] が成立しない，かつ今までに成立しなかった場合が1回ある場合のみ，
      それ以上増やしても「良い文字列」にはならないと判定できる
    - 上記が満たされるまで，条件を満たす数を数え上げる
center ∈ [1, |S|] について試せばよく，最悪計算量は，O(|S| ^ 2) ≒ 10 ^ 8 となり，間に合う．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int i;
    cin >> s;

    auto countPrePali = [&](int center) -> int{
        int start, last, cnt = 0;
        bool is_replaced;

        // odd version
        start = center, last = center;
        is_replaced = false;
        while(start >= 0 && last <= s.length() - 1){
            if(s[start] != s[last]){
                if(is_replaced)break;
                else is_replaced = true;
            }
            start--;last++;
            cnt++;
        }

        // even version
        start = center, last = center + 1;
        is_replaced = false;
        while(start >= 0 && last <= s.length() - 1){
            if(s[start] != s[last]){
                if(is_replaced)break;
                else is_replaced = true;
            }
            start--;last++;
            cnt++;
        }

        return cnt;
    };
    int ans = 0;
    rep(i, s.length())ans += countPrePali(/* center = */ i);

    printf("%d\n", ans);
    return 0;
}