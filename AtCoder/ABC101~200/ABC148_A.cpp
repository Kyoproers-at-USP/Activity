/*アルゴリズムと工夫点(Round One/CPU: 1 ms Memory: 3736 KB  Length: 428 B)
配列を使って，処理を簡単に．
*/
#include<iostream>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define QUESTION 3
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a,b;
bool is_correct[QUESTION] = {0};

int main(){
    int i;
    scanf("%d%d",&a,&b);
    is_correct[a - 1] = true;
    is_correct[b - 1] = true;
    rep(i,QUESTION)if(!is_correct[i])break;
    printf("%d\n",i + 1);
    return 0;
}