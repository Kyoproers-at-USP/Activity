/*アルゴリズムと工夫点(Repdigit/CPU: 2 ms Memory: 3652 KB  Length: 284 B)
文字列として受け取ると判定が楽．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string n;

int main(){
    cin >> n;
    printf("%s\n", n[0] == n[1] && n[1] == n[2] ? "Yes" : "No");
    return 0;
}