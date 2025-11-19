/*アルゴリズムと工夫点(Permute to Minimize/CPU: 9 ms Memory: 6552 KB  Length: 480 B)
貪欲法で解く．
0の個数と0以外の数を別々に管理する．
0以外の数の集合について，昇順に整列し，先頭から1番目と2番目の要素の間に0を挿入したものを出力すればよい．
*/
#include<iostream>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string x;

int main(){
    string ans, not_zero = "", zero = "";
    cin >> x;
    for(char c : x){
        if(c == '0')zero += '0';
        else not_zero += c;
    }
    sort(not_zero.begin(),not_zero.end());
    cout << not_zero[0] + zero + not_zero.substr(1) << endl;
    return 0;
}