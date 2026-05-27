/*アルゴリズムと工夫点(Hell, World!/CPU: 2 ms Memory: 3812 KB  Length: 364 B)
言われた通りに解く．
*/
#include<iostream>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x;
const string target = "HelloWorld";

int main(){
    scanf("%d", &x);
    for(int i = 0;i < target.size();i++)
        if(i != x - 1)putchar(target[i]);
    puts("");
    return 0;
}