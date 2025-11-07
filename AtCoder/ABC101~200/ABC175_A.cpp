/*アルゴリズムと工夫点(Rainy Season/CPU: 1 ms Memory: 3696 KB  Length: 443 B)
全パターンは3!通りであるため，全探索でも良いが，for文を使って O(|S|)で．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s;

int main(){
    int i, cnt = 0, ans = 0;
    cin >> s;
    rep(i,s.length()){
        if(s[i] == 'R')cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    printf("%d\n",ans);
    return 0;
}