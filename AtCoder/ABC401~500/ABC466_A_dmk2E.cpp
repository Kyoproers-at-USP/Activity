/*アルゴリズムと工夫点(Compromise/CPU: 1 ms Memory: 3800 KB  Length: 391 B)
0以上の値が一つでもあれば "No", そうでなければ "Yes" を出力すればよい．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        if(x >= 0){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}