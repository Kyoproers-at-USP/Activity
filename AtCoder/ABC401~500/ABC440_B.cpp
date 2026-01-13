/*アルゴリズムと工夫点(Trifecta/CPU: 1 ms Memory: 3964 KB  Length: 535 B)
T の値を番号付きでソートして解く．
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;

int main(){
    int i, j;
    scanf("%d", &n);
    vector<int> t(n), id(n);
    rep(i, n){
        scanf("%d", &t[i]);
        id[i] = i;
    }
    sort(id.begin(), id.end(), [&](int a, int b) -> bool{
        return t[a] < t[b];
    });
    printf("%d %d %d\n", id[0] + 1, id[1] + 1, id[2] + 1);
    return 0;
}