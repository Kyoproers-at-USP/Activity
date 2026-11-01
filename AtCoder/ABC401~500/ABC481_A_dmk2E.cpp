/*アルゴリズムと工夫点(Digits of A+B/CPU: 1 ms Memory: 3852 KB  Length: 285 B)
A + B の値を文字列化して，その長さを取得する方針すると楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a, b;

int main(){
    scanf("%d%d", &a, &b);
    printf("%ld\n", to_string(a + b).length());
    return 0;
}