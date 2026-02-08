/*アルゴリズムと工夫点(Digit Sum/CPU: 2 ms Memory: 3920 KB  Length: 465 B)
全探索して解く．
[1, N] の整数に対して，桁和がKになるか判定すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, k;

int digitSum(int x){
    int ans = 0;
    string str_x = to_string(x);
    for(char c : str_x)ans += c - '0';
    return ans;
}

int main(){
    int i, ans = 0;
    scanf("%d%d", &n, &k);
    for(i = 1;i <= n;i++)ans += digitSum(i) == k;
    printf("%d\n", ans);
    return 0;
}