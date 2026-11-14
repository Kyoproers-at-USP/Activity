/*アルゴリズムと工夫点(Flip Card Stack/CPU: 1 ms Memory: 3832 KB  Length: 706 B)
問題文の指示通りに操作を行えばよい．
この時，スタックやキューといったデータ構造を利用すると楽．
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cassert>
#define rep(i, n) for(i = 0;i < (int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, q;

int main(){
    int i;

    scanf("%d%d", &n, &q);
    vector<int> cards;
    rep(i, n)cards.push_back(n - i);

    while(q--){
        int k;
        scanf("%d", &k);

        queue<int> temp;
        while(k--){
            temp.push(-cards.back());
            cards.pop_back();
        }

        while(temp.size()){
            cards.push_back(temp.front());
            temp.pop();
        }
    }

    rep(i, n)printf("%d\n", cards[n - 1 - i]);
    return 0;
}