/*アルゴリズムと工夫点(illegal/CPU: 3 ms Memory: 3616 KB  Length: 280 B)
そのままやる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    cin >> s;
    printf("%s\n", s.length() % 5 == 0 ? "Yes" : "No");
    return 0;
}