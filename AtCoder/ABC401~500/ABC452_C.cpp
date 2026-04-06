/*アルゴリズムと工夫点(Fishbones/CPU: 55 ms Memory: 18300 KB  Length: 957 B)
脊椎の位置毎に，どのアルファベットが有効かを管理して解く．
文字列の長さは短いため，脊椎に書くS を全探索する．
Sを固定する際，各Si が有効かどうかは，対応する脊椎の位置でとり得るアルファベットを管理していればよい．
最悪計算量は，O(N * M) < 10 ^ 7 となり高速．
*/
#include<iostream>
#include<vector>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
#define MAX_S 10
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;

int main(){
    int i, j;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    rep(i, n){
        scanf("%d%d", &a[i], &b[i]);b[i]--;
    }

    scanf("%d", &m);
    vector<string> s(m);
    vector<vector<string> > len_to_str(MAX_S + 1);
    rep(i, m){
        cin >> s[i];
        len_to_str[s[i].length()].push_back(s[i]);
    }

    vector<int> id_to_alfas(n, 0);
    rep(i, n)for(string str : len_to_str[a[i]])
        id_to_alfas[i] |= (1 << (str[b[i]] - 'a'));

    rep(i, m){
        if(s[i].length() != n){
            puts("No");
            continue;
        }
        rep(j, n)if(((id_to_alfas[j] >> (s[i][j] - 'a')) & 1) == 0)break;
        printf("%s\n", j == n ? "Yes" : "No");
    }
    return 0;
}