/*アルゴリズムと工夫点(Insert and Erase A/CPU: 12 ms Memory: 5004 KB  Length: 1084 B)
2段階に分けて解く．
まず，S を T に一致させることが可能であるかは，2つの文字列から'A' を除いた文字列が互いに一致するかどうかである．
この判定を行った後，'A'以外の文字を区切りとし，その区間に存在する'A'の個数の差分の絶対値の総和を出力すればよい．
最悪計算量は，O(|S| + |T|) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s, t;

string eraseA(string& str){
    string s_without_a = "";
    for(char c : str)if(c != 'A')s_without_a += c;
    return s_without_a;
}

int main(){
    int i, j, ans = 0;
    const int NIL = -1;
    cin >> s >> t;
    string s_without_a = eraseA(/* str = */ s);
    string t_without_a = eraseA(/* str = */ t);
    if(s_without_a == t_without_a){
        int s_i = 0, t_i = 0;
        while(s_i < s.length() || t_i < t.length()){
            int s_cnt_a = 0, t_cnt_a = 0;
            while(s_i < s.length() && s[s_i] == 'A'){
                s_cnt_a++;
                s_i++;
            }
            while(t_i < t.length() && t[t_i] == 'A'){
                t_cnt_a++;
                t_i++;
            }
            ans += abs(s_cnt_a - t_cnt_a);
            s_i++;t_i++;
        }
        printf("%d\n", ans);
    }else printf("%d\n", NIL);
    return 0;
}