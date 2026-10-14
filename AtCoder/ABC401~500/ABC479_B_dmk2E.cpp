/*アルゴリズムと工夫点(Longest Rainy Streak/CPU: 1 ms Memory: 3876 KB  Length: 525 B)
'R' の先頭位置を全探索し，'R'の連続文字列の最大の長さを求めればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(){
    int i, j;

    scanf("%d", &n);
    cin >> s;

    int ans = 0;
    i = 0;
    while(i < n){
        if(s[i] == 'R'){
            j = i;
            while(j < n && s[j] == 'R')j++;
            ans = max(ans, j - i);

            i = j;
        }else i++;
    }

    printf("%d\n", ans);
    return 0;
}