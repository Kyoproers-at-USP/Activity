/*アルゴリズムと工夫点(Phonetic Alphabet/CPU: 1 ms Memory: 3600 KB  Length: 429 B)
アルファベット毎の文字列を配列等で定義しておくと実装が楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;
const string s_to_name[] = {
    "Alpha", 
    "Bravo", 
    "Charlie"
};

int main(){
    int i;

    cin >> n >> s;
    rep(i, n - 1)cout << s_to_name[s[i] - 'A'] << ' ';
    cout << s_to_name[s[i] - 'A'] << endl;
    return 0;
}