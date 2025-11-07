/*アルゴリズムと工夫点(Five Variables/CPU: 1 ms Memory: 3876 KB  Length: 367 B)
何番目の値化を別で保持して，順番に値を受け取る処理を書けばよい．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX 5
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x;

int main(){
    int i;
    rep(i,MAX){
        scanf("%d",&x);
        if(x == 0){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}