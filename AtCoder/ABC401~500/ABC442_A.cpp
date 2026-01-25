/*アルゴリズムと工夫点(Count ./CPU: 1 ms Memory: 3908 KB  Length: 311 B)
そのまま解く．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int ans = 0;
    cin >> s;
    for(char c : s)ans += c == 'i' || c == 'j';
    printf("%d\n", ans);
    return 0;
}