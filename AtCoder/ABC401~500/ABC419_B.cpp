/*アルゴリズムと工夫点(Get Min/CPU: 1 ms Memory: 3880 KB  Length: 495 B)
優先度付きキューを使うと楽．
*/
#include<iostream>
#include<queue>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;

int main(){
    priority_queue<int> PQ;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(x==1){
            scanf("%d",&x);
            PQ.push(-x);
        }else{
            printf("%d\n",-PQ.top());
            PQ.pop();
        }
    }
    return 0;
}