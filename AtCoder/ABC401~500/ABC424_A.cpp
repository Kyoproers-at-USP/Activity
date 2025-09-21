/*アルゴリズムと工夫点(Isosceles/CPU: 1 ms Memory: 3872 KB  Length: 300 B)
あり得る2辺の組み合わせを全て試す．
※ バーチャル参加
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a,b,c;

int main(){
    scanf("%d%d%d",&a,&b,&c);
    printf("%s\n",(a == b || b == c || c == a) ? "Yes" : "No");
    return 0;
}