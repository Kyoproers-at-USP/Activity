/*アルゴリズムと工夫点(Adjacent Distinct String/CPU: 145 ms Memory: 7448 KB  Length: 1300 B)
貪欲法 + 優先度付きキューで解く．
ある文字列Sが，並び替えることでどの隣り合う2文字も異なるようにすることが可能である場合，下記の手順でそのような並び替えを実現できる．
 1. アルファベットごとの個数を数え上げる
 2. 解として出力する文字列として使用していないアルファベットの内，未使用の個数が最も多いものから使用していく
これは，優先度付きキューを用いれば解ける．
1テストケース当たりの最悪計算量は，O(|S| * log2(|S)) < 10 ^ 8 となり，間に合う．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, char> P;

int t;

void solve(){
    string s;
    cin >> s;

    const int ALFA = 26;
    vector<int> alfa_to_cnt(ALFA, 0);
    for(char c : s)alfa_to_cnt[c - 'a']++;
    priority_queue<P> PQ;
    for(int i = 0;i < ALFA;i++)if(alfa_to_cnt[i] > 0)PQ.push(P(alfa_to_cnt[i], 'a' + i));

    string ans = "";
    const char NIL = '#';
    char last_ch = NIL;
    while(PQ.size()){
        int cnt = PQ.top().first;
        char ch = PQ.top().second;
        PQ.pop();

        if(ch == last_ch){
            if(PQ.size() == 0){
                puts("No");
                return ;
            }
            auto [nxt_cnt, nxt_ch] = PQ.top();PQ.pop();
            ans += nxt_ch;
            nxt_cnt--;
            last_ch = nxt_ch;

            if(nxt_cnt)PQ.push(P(nxt_cnt, nxt_ch));
        }else{
            ans += ch;
            cnt--;
            last_ch = ch;
        }

        if(cnt)PQ.push(P(cnt, ch));
    }
    puts("Yes");
    cout << ans << '\n';
}

int main(){
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}