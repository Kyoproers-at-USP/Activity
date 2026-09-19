/*アルゴリズムと工夫点(Not X/CPU: 2 ms Memory: 3800 KB  Length: 303 B)
1加えた値を解とすればよい．ただし加算した結果4になった場合は1となるようにする．
剰余を上手く使うと，一つの式で表せる．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x;

int main(){
    const int MAX_X = 3;

    scanf("%d", &x);x--;
    printf("%d\n", ((x + 1) % MAX_X) + 1);
    return 0;
}