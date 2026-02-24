/*アルゴリズムと工夫点(Handmaid/CPU: 3 ms Memory: 6484 KB  Length: 305 B)
そのまま解く．
※ c++ における文字列リテラルは const char* 型でありstring型であるため，そのまま加算できないことに注意
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;
    cout << string("Of") + (char)tolower(s[0]) + s.substr(1, s.length() - 1) << endl;
    return 0;
}