/*アルゴリズムと工夫点(Eating Symbols Easy /CPU: 1 ms Memory: 3884 KB  Length: 344 B)
if文使って解く．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int i,now = 0;
    cin>>s;
    rep(i,s.length()){
        if(s[i] == '+')now++;
        else now--;
    }
    printf("%d\n",now);
    return 0;
}