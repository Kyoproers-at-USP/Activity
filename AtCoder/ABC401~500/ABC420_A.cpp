/*アルゴリズムと工夫点(What month is it?/CPU: 1 ms Memory: 3920 KB  Length: 295 B)
0-index にして考えると解きやすい．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_MONTH 12
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x,y;

int main(){
    scanf("%d%d",&x,&y);x--;
    printf("%d\n",((x+y)%MAX_MONTH)+1);
    return 0;
}