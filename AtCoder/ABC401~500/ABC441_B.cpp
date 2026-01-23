/*アルゴリズムと工夫点(Two Languages/CPU: 1 ms Memory: 3932 KB  Length: 1218 B)
S, Tそれぞれの各文字の存在性を保持 + 文字列走査 で解く．
最悪計算量は，O(Q * max(wi)) < 10 ^ 5 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

enum Judge{
    TAKAHASHI, 
    AOKI, 
    UNKNOWN, 
};

int n, m, q;
string s, t;

int main(){
    int i,j;
    const int MAX_ALFA = 26;
    scanf("%d%d", &n, &m);
    cin >> s >> t;
    vector<bool> s_exist(MAX_ALFA, false), t_exist(MAX_ALFA, false);
    rep(i, n)s_exist[s[i] - 'a'] = true;
    rep(i, m)t_exist[t[i] - 'a'] = true;
    scanf("%d", &q);
    auto judge = [&](const string& str) -> Judge{
        for(char c : str){
            int alpa_id = c - 'a';
            if(s_exist[alpa_id] && !t_exist[alpa_id])return TAKAHASHI;
            if(!s_exist[alpa_id] && t_exist[alpa_id])return AOKI;
        }
        return UNKNOWN;
    };
    while(q--){
        string w;
        cin >> w;
        switch(judge(w)){
            case TAKAHASHI:
                puts("Takahashi"); 
                break;
            case AOKI: 
                puts("Aoki");
                break;
            default :
                puts("Unknown");
                break;
        }
    }
    return 0;
}