/*アルゴリズムと工夫点(Traffic Light/CPU: 1 ms Memory: 3588 KB  Length: 341 B)
余りの計算を利用すると楽．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char c;

int main(){
    int i;
    c = getchar();

    const string TARGET = "BYR";
    cout << TARGET[(TARGET.find(c) + 1) % TARGET.size()] << endl;
    return 0;
}